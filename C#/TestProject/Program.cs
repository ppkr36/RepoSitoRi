class Book
{
    public string title_ { get; set; }
    public string author_ { get; set; }
    public Book(string title, string author) { author_ = author; title_ = title; }
}

class Program
{
    static void Main()
    {
        Book book = new Book("title1", "author1");
        Book book2 = new Book("title2", "author2");
        Console.WriteLine(book.title_);

    }

}
