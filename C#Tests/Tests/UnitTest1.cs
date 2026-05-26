using System;
using System.Linq;
using NUnit.Framework;

namespace TestingDemo;

public class LibraryCard
{
    private int _borrowedBooksCount;
    private string _cardNumber;
    private bool _isBlocked;
    private List<string> _operationHistory;

    public LibraryCard(string cardNumber, int initialBorrowedCount)
    {
        if (string.IsNullOrEmpty(cardNumber))
            throw new ArgumentException("Номер абонемента не может быть пустым");
        
        if (initialBorrowedCount < 0)
            throw new ArgumentException("Начальное количество книг не может быть отрицательным");
        
        _cardNumber = cardNumber;
        _borrowedBooksCount = initialBorrowedCount;
        _isBlocked = false;
        _operationHistory = new List<string>();
        _operationHistory.Add($"Абонемент оформлен. Книг на руках: {initialBorrowedCount}");
    }

    // Выдача книги
    public void BorrowBook(int count)
    {
        if (_isBlocked)
            throw new InvalidOperationException("Абонемент заблокирован. Выдача книг невозможна");
        
        if (count <= 0)
            throw new ArgumentException("Количество книг для выдачи должно быть положительным");
        
        if (_borrowedBooksCount + count > 10)
            throw new InvalidOperationException("Превышен лимит книг на руках (максимум 10)");
        
        _borrowedBooksCount += count;
        _operationHistory.Add($"Выдано книг: +{count}. Всего на руках: {_borrowedBooksCount}");
    }

    // Возврат книги
    public void ReturnBook(int count)
    {
        if (_isBlocked)
            throw new InvalidOperationException("Абонемент заблокирован. Возврат книг невозможен");
        
        if (count <= 0)
            throw new ArgumentException("Количество книг для возврата должно быть положительным");
        
        if (count > _borrowedBooksCount)
            throw new InvalidOperationException("Нельзя вернуть больше книг, чем есть на руках");
        
        _borrowedBooksCount -= count;
        _operationHistory.Add($"Возврат книг: -{count}. Всего на руках: {_borrowedBooksCount}");
    }

    // Перевод книги другому читателю
    public void TransferBook(LibraryCard targetCard, int count)
    {
        if (targetCard == null)
            throw new ArgumentNullException(nameof(targetCard), "Карта получателя не указана");
        
        if (_isBlocked)
            throw new InvalidOperationException("Карта отправителя заблокирована");
        
        if (targetCard._isBlocked)
            throw new InvalidOperationException("Карта получателя заблокирована");
        
        if (count <= 0)
            throw new ArgumentException("Количество книг для перевода должно быть положительным");
        
        if (count > _borrowedBooksCount)
            throw new InvalidOperationException("Недостаточно книг на руках для перевода");
        
        if (targetCard._borrowedBooksCount + count > 10)
            throw new InvalidOperationException("У получателя превысится лимит книг");
        
        // Списываем с текущей карты
        _borrowedBooksCount -= count;
        _operationHistory.Add($"Передано книг: -{count} читателю {targetCard._cardNumber}");
        
        // Добавляем получателю
        targetCard._borrowedBooksCount += count;
        targetCard._operationHistory.Add($"Получено книг: +{count} от читателя {_cardNumber}");
    }

    // Проверка количества книг на руках
    public int GetBorrowedBooksCount()
    {
        return _borrowedBooksCount;
    }

    // Блокировка абонемента
    public void BlockCard()
    {
        _isBlocked = true;
        _operationHistory.Add("Абонемент заблокирован");
    }

    // Разблокировка абонемента
    public void UnblockCard()
    {
        _isBlocked = false;
        _operationHistory.Add("Абонемент разблокирован");
    }

    // Проверка, заблокирован ли абонемент
    public bool IsBlocked()
    {
        return _isBlocked;
    }

    // Получение истории операций
    public string[] GetOperationHistory()
    {
        return _operationHistory.ToArray();
    }

    // Номер абонемента (только для чтения)
    public string GetCardNumber()
    {
        return _cardNumber;
    }
}

public class LibraryService
{
    // Проверка, может ли читатель заказать редкую книгу (книг на руках <= 5 и абонемент не заблокирован)
    public bool CanOrderRareBook(LibraryCard card)
    {
        if (card == null)
            return false;
        
        return card.GetBorrowedBooksCount() <= 5 && !card.IsBlocked();
    }

    // Расчёт пени за просрочку (2 рубля за каждую книгу сверх лимита 3, минимум 0, максимум 300)
    public double CalculateOverdueFine(LibraryCard card, int overdueDays)
    {
        if (card == null)
            throw new ArgumentNullException(nameof(card));
        
        if (overdueDays <= 0)
            return 0;
        
        int excessBooks = Math.Max(0, card.GetBorrowedBooksCount() - 3);
        double fine = excessBooks * overdueDays * 2.0;
        
        if (fine > 300)
            fine = 300;
        
        return fine;
    }

    // Проверка, является ли выдача книг подозрительной (> 8 книг за раз)
    public bool IsSuspiciousIssuance(int bookCount)
    {
        return bookCount > 8;
    }
}

[TestFixture]
public class LibraryCardTests
{
    [Test]
    public void Constructor_WithValidData_CreatesCardSuccessfully()
    {
        var card = new LibraryCard("LIB-001", 2);

        Assert.That(card.GetCardNumber(), Is.EqualTo("LIB-001"));
        Assert.That(card.GetBorrowedBooksCount(), Is.EqualTo(2));
        Assert.That(card.IsBlocked(), Is.False);
    }

    [Test]
    public void Constructor_WithEmptyCardNumber_ThrowsArgumentException()
    {
        Assert.That(() => new LibraryCard("", 0), Throws.TypeOf<ArgumentException>());
    }

    [Test]
    public void Constructor_WithNullCardNumber_ThrowsArgumentException()
    {
        Assert.That(() => new LibraryCard(null!, 0), Throws.TypeOf<ArgumentException>());
    }

    [Test]
    public void Constructor_WithNegativeInitialBooks_ThrowsArgumentException()
    {
        Assert.That(() => new LibraryCard("LIB-001", -5), Throws.TypeOf<ArgumentException>());
    }

    [Test]
    public void BorrowBook_WhenBorrowingThreeBooksFromZero_IncreasesCountToThree()
    {
        var card = new LibraryCard("LIB-001", 0);

        card.BorrowBook(3);

        Assert.That(card.GetBorrowedBooksCount(), Is.EqualTo(3));
    }

    [Test]
    public void BorrowBook_WithNegativeCount_ThrowsArgumentException()
    {
        var card = new LibraryCard("LIB-001", 0);

        Assert.That(() => card.BorrowBook(-1), Throws.TypeOf<ArgumentException>());
    }

    [Test]
    public void BorrowBook_WithZeroCount_ThrowsArgumentException()
    {
        var card = new LibraryCard("LIB-001", 0);

        Assert.That(() => card.BorrowBook(0), Throws.TypeOf<ArgumentException>());
    }

    [Test]
    public void BorrowBook_ExceedingLimit_ThrowsInvalidOperationException()
    {
        var card = new LibraryCard("LIB-001", 9);

        Assert.That(() => card.BorrowBook(2), Throws.TypeOf<InvalidOperationException>());
    }

    [Test]
    public void BorrowBook_UpToLimit_Succeeds()
    {
        var card = new LibraryCard("LIB-001", 8);

        Assert.That(() => card.BorrowBook(2), Throws.Nothing);
        Assert.That(card.GetBorrowedBooksCount(), Is.EqualTo(10));
    }

    [Test]
    public void BorrowBook_WhenCardIsBlocked_ThrowsInvalidOperationException()
    {
        var card = new LibraryCard("LIB-001", 0);
        card.BlockCard();

        Assert.That(() => card.BorrowBook(1), Throws.TypeOf<InvalidOperationException>());
    }

    [Test]
    public void ReturnBook_WhenReturningThreeBooks_DecreasesCountToTwo()
    {
        var card = new LibraryCard("LIB-001", 5);

        card.ReturnBook(3);

        Assert.That(card.GetBorrowedBooksCount(), Is.EqualTo(2));
    }

    [Test]
    public void ReturnBook_WhenReturningAllBooks_CountBecomesZero()
    {
        var card = new LibraryCard("LIB-001", 5);

        card.ReturnBook(5);

        Assert.That(card.GetBorrowedBooksCount(), Is.EqualTo(0));
    }

    [Test]
    public void ReturnBook_WithNegativeCount_ThrowsArgumentException()
    {
        var card = new LibraryCard("LIB-001", 5);

        Assert.That(() => card.ReturnBook(-1), Throws.TypeOf<ArgumentException>());
    }

    [Test]
    public void ReturnBook_MoreThanBorrowed_ThrowsInvalidOperationException()
    {
        var card = new LibraryCard("LIB-001", 3);

        Assert.That(() => card.ReturnBook(5), Throws.TypeOf<InvalidOperationException>());
    }

    [Test]
    public void ReturnBook_WhenCardIsBlocked_ThrowsInvalidOperationException()
    {
        var card = new LibraryCard("LIB-001", 5);
        card.BlockCard();

        Assert.That(() => card.ReturnBook(1), Throws.TypeOf<InvalidOperationException>());
    }

    [Test]
    public void TransferBook_WithValidTransfer_AdjustsCountsForSenderAndReceiver()
    {
        var sender = new LibraryCard("LIB-001", 5);
        var receiver = new LibraryCard("LIB-002", 1);

        sender.TransferBook(receiver, 3);

        Assert.That(sender.GetBorrowedBooksCount(), Is.EqualTo(2));
        Assert.That(receiver.GetBorrowedBooksCount(), Is.EqualTo(4));
    }

    [Test]
    public void TransferBook_WithNullReceiver_ThrowsArgumentNullException()
    {
        var sender = new LibraryCard("LIB-001", 5);

        Assert.That(() => sender.TransferBook(null!, 1), Throws.TypeOf<ArgumentNullException>());
    }

    [Test]
    public void TransferBook_WhenSenderIsBlocked_ThrowsInvalidOperationException()
    {
        var sender = new LibraryCard("LIB-001", 5);
        var receiver = new LibraryCard("LIB-002", 0);
        sender.BlockCard();

        Assert.That(() => sender.TransferBook(receiver, 1), Throws.TypeOf<InvalidOperationException>());
    }

    [Test]
    public void TransferBook_WhenReceiverIsBlocked_ThrowsInvalidOperationException()
    {
        var sender = new LibraryCard("LIB-001", 5);
        var receiver = new LibraryCard("LIB-002", 0);
        receiver.BlockCard();

        Assert.That(() => sender.TransferBook(receiver, 1), Throws.TypeOf<InvalidOperationException>());
    }

    [Test]
    public void TransferBook_MoreThanSenderHas_ThrowsInvalidOperationException()
    {
        var sender = new LibraryCard("LIB-001", 2);
        var receiver = new LibraryCard("LIB-002", 0);

        Assert.That(() => sender.TransferBook(receiver, 5), Throws.TypeOf<InvalidOperationException>());
    }

    [Test]
    public void TransferBook_WhenReceiverWouldExceedLimit_ThrowsInvalidOperationException()
    {
        var sender = new LibraryCard("LIB-001", 2);
        var receiver = new LibraryCard("LIB-002", 9);

        Assert.That(() => sender.TransferBook(receiver, 2), Throws.TypeOf<InvalidOperationException>());
    }

    [Test]
    public void BlockCard_SetsIsBlockedToTrue()
    {
        var card = new LibraryCard("LIB-001", 0);

        card.BlockCard();

        Assert.That(card.IsBlocked(), Is.True);
    }

    [Test]
    public void UnblockCard_AfterBlock_SetsIsBlockedToFalse()
    {
        var card = new LibraryCard("LIB-001", 0);

        card.BlockCard();
        card.UnblockCard();

        Assert.That(card.IsBlocked(), Is.False);
    }

    [Test]
    public void OperationHistory_AfterCreation_ContainsSubscriptionCreatedEntry()
    {
        var card = new LibraryCard("LIB-001", 0);
        var history = card.GetOperationHistory();

        Assert.That(history.Length, Is.EqualTo(1));
        Assert.That(history[0], Does.Contain("Абонемент оформлен"));
    }

    [Test]
    public void OperationHistory_AfterBorrowingBooks_ContainsIssueEntry()
    {
        var card = new LibraryCard("LIB-001", 0);

        card.BorrowBook(2);
        var history = card.GetOperationHistory();

        Assert.That(history.Last(), Does.Contain("Выдано книг"));
    }

    [Test]
    public void OperationHistory_AfterBlocking_ContainsBlockedEntry()
    {
        var card = new LibraryCard("LIB-001", 0);

        card.BlockCard();
        var history = card.GetOperationHistory();

        Assert.That(history.Last(), Does.Contain("заблокирован"));
    }
}

[TestFixture]
public class LibraryServiceTests
{
    private LibraryService _service = null!;

    [SetUp]
    public void SetUp()
    {
        _service = new LibraryService();
    }

    [Test]
    public void CanOrderRareBook_WhenBooksAtMostFiveAndNotBlocked_ReturnsTrue()
    {
        var card = new LibraryCard("LIB-001", 5);

        var result = _service.CanOrderRareBook(card);

        Assert.That(result, Is.True);
    }

    [Test]
    public void CanOrderRareBook_WhenMoreThanFiveBooks_ReturnsFalse()
    {
        var card = new LibraryCard("LIB-001", 6);

        var result = _service.CanOrderRareBook(card);

        Assert.That(result, Is.False);
    }

    [Test]
    public void CanOrderRareBook_WhenCardBlocked_ReturnsFalse()
    {
        var card = new LibraryCard("LIB-001", 5);
        card.BlockCard();

        var result = _service.CanOrderRareBook(card);

        Assert.That(result, Is.False);
    }

    [Test]
    public void CanOrderRareBook_WithNullCard_ReturnsFalse()
    {
        var result = _service.CanOrderRareBook(null!);

        Assert.That(result, Is.False);
    }

    [Test]
    public void CalculateOverdueFine_WhenWithinLimit_ReturnsZero()
    {
        var card = new LibraryCard("LIB-001", 3);

        var fine = _service.CalculateOverdueFine(card, 10);

        Assert.That(fine, Is.EqualTo(0));
    }

    [Test]
    public void CalculateOverdueFine_WithExcessBooksAndOverdueDays_ReturnsCorrectFine()
    {
        var card = new LibraryCard("LIB-001", 5);

        var fine = _service.CalculateOverdueFine(card, 7);

        Assert.That(fine, Is.EqualTo(28));
    }

    [Test]
    public void CalculateOverdueFine_WhenCalculatedFineExceedsCap_ReturnsMaxFine()
    {
        var card = new LibraryCard("LIB-001", 8);

        var fine = _service.CalculateOverdueFine(card, 100);

        Assert.That(fine, Is.EqualTo(300));
    }

    [Test]
    public void CalculateOverdueFine_WithZeroOverdueDays_ReturnsZero()
    {
        var card = new LibraryCard("LIB-001", 5);

        var fine = _service.CalculateOverdueFine(card, 0);

        Assert.That(fine, Is.EqualTo(0));
    }

    [Test]
    public void CalculateOverdueFine_WithNullCard_ThrowsArgumentNullException()
    {
        Assert.That(() => _service.CalculateOverdueFine(null!, 5), Throws.TypeOf<ArgumentNullException>());
    }

    [Test]
    public void IsSuspiciousIssuance_WhenBooksGreaterThanEight_ReturnsTrue()
    {
        Assert.That(_service.IsSuspiciousIssuance(9), Is.True);
    }

    [Test]
    public void IsSuspiciousIssuance_WhenBooksEqualEight_ReturnsFalse()
    {
        Assert.That(_service.IsSuspiciousIssuance(8), Is.False);
    }

    [Test]
    public void IsSuspiciousIssuance_WhenBooksLessThanEight_ReturnsFalse()
    {
        Assert.That(_service.IsSuspiciousIssuance(5), Is.False);
    }
}
