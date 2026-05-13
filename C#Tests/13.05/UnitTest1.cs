using System;
using System.Linq;
using System.Reflection;
using NUnit.Framework;
namespace _13._05;
public class BankAccount
{
    private double _balance;
    private string _accountNumber;
    private bool _isBlocked;
    private List<string> _transactionHistory;

    public BankAccount(string accountNumber, double initialBalance)
    {
        if (string.IsNullOrEmpty(accountNumber))
            throw new ArgumentException("Номер счета не может быть пустым");
        
        if (initialBalance < 0)
            throw new ArgumentException("Начальный баланс не может быть отрицательным");
        
        _accountNumber = accountNumber;
        _balance = initialBalance;
        _isBlocked = false;
        _transactionHistory = new List<string>();
        _transactionHistory.Add($"Счет открыт. Баланс: {initialBalance} руб.");
    }

    // Пополнение счета
    public void Deposit(double amount)
    {
        if (_isBlocked)
            throw new InvalidOperationException("Счет заблокирован. Операция недоступна");
        
        if (amount <= 0)
            throw new ArgumentException("Сумма пополнения должна быть положительной");
        
        _balance += amount;
        _transactionHistory.Add($"Пополнение: +{amount} руб. Баланс: {_balance} руб.");
    }

    // Снятие денег
    public void Withdraw(double amount)
    {
        if (_isBlocked)
            throw new InvalidOperationException("Счет заблокирован. Операция недоступна");
        
        if (amount <= 0)
            throw new ArgumentException("Сумма снятия должна быть положительной");
        
        if (amount > _balance)
            throw new InvalidOperationException("Недостаточно средств");
        
        _balance -= amount;
        _transactionHistory.Add($"Снятие: -{amount} руб. Баланс: {_balance} руб.");
    }

    // Перевод на другой счет
    public void Transfer(BankAccount targetAccount, double amount)
    {
        if (targetAccount == null)
            throw new ArgumentNullException(nameof(targetAccount), "Счет получателя не указан");
        
        if (_isBlocked)
            throw new InvalidOperationException("Счет отправителя заблокирован");
        
        if (targetAccount._isBlocked)
            throw new InvalidOperationException("Счет получателя заблокирован");
        
        if (amount <= 0)
            throw new ArgumentException("Сумма перевода должна быть положительной");
        
        if (amount > _balance)
            throw new InvalidOperationException("Недостаточно средств для перевода");
        
        // Снимаем с текущего счета
        _balance -= amount;
        _transactionHistory.Add($"Перевод: -{amount} руб. на счет {targetAccount._accountNumber}");
        
        // Зачисляем на целевой счет
        targetAccount._balance += amount;
        targetAccount._transactionHistory.Add($"Поступление перевода: +{amount} руб. со счета {_accountNumber}");
    }

    // Проверка баланса
    public double GetBalance()
    {
        return _balance;
    }

    // Блокировка счета
    public void BlockAccount()
    {
        _isBlocked = true;
        _transactionHistory.Add("Счет заблокирован");
    }

    // Разблокировка счета
    public void UnblockAccount()
    {
        _isBlocked = false;
        _transactionHistory.Add("Счет разблокирован");
    }

    // Проверка, заблокирован ли счет
    public bool IsBlocked()
    {
        return _isBlocked;
    }

    // Получение истории операций
    public string[] GetTransactionHistory()
    {
        return _transactionHistory.ToArray();
    }

    // Номер счета (только для чтения)
    public string GetAccountNumber()
    {
        return _accountNumber;
    }
}

public class BankService
{
    // Проверка, может ли клиент получить кредит (баланс > 10000 и счет не заблокирован)
    public bool CanGetCredit(BankAccount account)
    {
        if (account == null)
            return false;
        
        return account.GetBalance() > 10000 && !account.IsBlocked();
    }

    // Расчет комиссии за обслуживание (0.5% в месяц от баланса, мин 50 руб, макс 500 руб)
    public double CalculateMonthlyFee(BankAccount account)
    {
        if (account == null)
            throw new ArgumentNullException(nameof(account));
        
        double balance = account.GetBalance();
        double fee = balance * 0.005; // 0.5%
        
        if (fee < 50)
            fee = 50;
        else if (fee > 500)
            fee = 500;
        
        return fee;
    }

    // Проверка, является ли сумма транзакции подозрительной (> 100000)
    public bool IsSuspiciousTransaction(double amount)
    {
        return amount > 100000;
    }
}
[TestFixture]
public class BankTest
{
    private BankService _bankservice;
    private BankAccount _bankaccount1;
    private BankAccount _bankaccount2;

    [SetUp]
    public void Setup()
    {
        _bankservice = new BankService();
        _bankaccount1 = new BankAccount("12345", 1000.0);
        _bankaccount2 = new BankAccount("67890", 500.0);
    }

    [Test]
    public void Test1()
    {
        Assert.That(_bankaccount1.GetBalance(), Is.EqualTo(1000.0).Within(0.001));
    }

    [Test]
    public void Test2()
    {
        Assert.That(_bankaccount1.IsBlocked(), Is.False);
    }

    [Test]
    public void Test3()
    {
        Assert.That(_bankaccount1.GetAccountNumber(), Is.EqualTo("12345"));
    }

    [Test]
    public void Test4()
    {
        Assert.That(_bankaccount1.GetTransactionHistory()[0].Contains("Счет открыт"), Is.True);
    }

    [Test]
    public void Test5()
    {
        Assert.Throws<ArgumentException>(() => new BankAccount("", 1000.0));
    }

    [Test]
    public void Test6()
    {
        _bankaccount1.Deposit(500.0);
        Assert.That(_bankaccount1.GetBalance(), Is.EqualTo(1500.0).Within(0.001));
    }

    [Test]
    public void Test7()
    {
        _bankaccount1.Deposit(500.0);
        Assert.That(_bankaccount1.GetTransactionHistory().Any(h => h.Contains("Пополнение")), Is.True);
    }

    [Test]
    public void Test8()
    {
        Assert.Throws<ArgumentException>(() => _bankaccount1.Deposit(-100.0));
        Assert.That(_bankaccount1.GetBalance(), Is.EqualTo(1000.0).Within(0.001));
    }

    [Test]
    public void Test9()
    {
        _bankaccount1.Withdraw(300.0);
        Assert.That(_bankaccount1.GetBalance(), Is.EqualTo(700.0).Within(0.001));
    }

    [Test]
    public void Test10()
    {
        _bankaccount1.Withdraw(300.0);
        Assert.That(_bankaccount1.GetTransactionHistory().Any(h => h.Contains("Снятие")), Is.True);
    }

    [Test]
    public void Test11()
    {
        InvalidOperationException ex = Assert.Throws<InvalidOperationException>(() => _bankaccount1.Withdraw(1500.0));
        Assert.That(ex.Message, Is.EqualTo("Недостаточно средств"));
        Assert.That(_bankaccount1.GetBalance(), Is.EqualTo(1000.0).Within(0.001));
    }

    [Test]
    public void Test12()
    {
        _bankaccount1.BlockAccount();
        Assert.That(_bankaccount1.IsBlocked(), Is.True);
    }

    [Test]
    public void Test13()
    {
        _bankaccount1.BlockAccount();
        Assert.Throws<InvalidOperationException>(() => _bankaccount1.Withdraw(100.0));
    }

    [Test]
    public void Test14()
    {
        _bankaccount1.Transfer(_bankaccount2, 300.0);
        Assert.That(_bankaccount1.GetBalance(), Is.EqualTo(700.0).Within(0.001));
    }

    [Test]
    public void Test15()
    {
        _bankaccount1.Transfer(_bankaccount2, 300.0);
        Assert.That(_bankaccount2.GetBalance(), Is.EqualTo(800.0).Within(0.001));
    }

    [Test]
    public void Test16()
    {
        _bankaccount1.Transfer(_bankaccount2, 300.0);
        Assert.That(_bankaccount1.GetTransactionHistory().Any(h => h.Contains("Перевод")), Is.True);
    }

    [Test]
    public void Test17()
    {
        _bankaccount1.Transfer(_bankaccount2, 300.0);
        Assert.That(_bankaccount2.GetTransactionHistory().Any(h => h.Contains("Поступление перевода")), Is.True);
    }

    [Test]
    public void Test18()
    {
        Assert.Throws<ArgumentException>(() => _bankaccount1.Withdraw(-100.0));
    }

    [Test]
    public void Test19()
    {
        _bankaccount1.BlockAccount();
        Assert.Throws<InvalidOperationException>(() => _bankaccount1.Deposit(100.0));
    }

    [Test]
    public void Test20()
    {
        Assert.Throws<ArgumentNullException>(() => _bankaccount1.Transfer(null!, 100.0));
    }

    [Test]
    public void Test21()
    {
        _bankaccount1.BlockAccount();
        Assert.Throws<InvalidOperationException>(() => _bankaccount1.Transfer(_bankaccount2, 100.0));
    }

    [Test]
    public void Test22()
    {
        _bankaccount2.BlockAccount();
        Assert.Throws<InvalidOperationException>(() => _bankaccount1.Transfer(_bankaccount2, 100.0));
    }

    [Test]
    public void Test23()
    {
        Assert.Throws<ArgumentException>(() => _bankaccount1.Transfer(_bankaccount2, -100.0));
    }

    [Test]
    public void Test24()
    {
        Assert.Throws<InvalidOperationException>(() => _bankaccount1.Transfer(_bankaccount2, 1500.0));
    }

    [Test]
    public void Test25()
    {
        Assert.Throws<ArgumentException>(() => new BankAccount("12345", -100.0));
    }

    [Test]
    public void Test26()
    {
        Assert.Throws<ArgumentNullException>(() => _bankservice.CalculateMonthlyFee(null!));
    }

    [Test]
    public void Test27()
    {
        _bankaccount1.UnblockAccount();
        Assert.That(_bankaccount1.IsBlocked(), Is.False);
    }
}