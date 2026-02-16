using System.Globalization;
class Human
{
    public string Name;
    public int Age;
    private double Height;
    private double Weight;
    
    public int GetWeight() { return Weight;}
    public void SetWeight(int Neweight)
    {
        Weight = Neweight;
    }


    public Human(string Name, int Age)
    {
        this.Name = Name;
        this.Age = Age;
    }

    
}                                                                                                                                                                                      
//class Car                                                                                                                                                                                
//{                                                                                                                                                                                      
//    public string Brand;                                                                                                                                                               
//    public string Model;                                                                                                                                                              
//    public int Year;                                                                                                                                                                   
//    public int Price;                                                                                                                                                                   
//    public string Color;                                                                                                                                                                
                                                                                                                                                                                      

                                                                                                                                                                                          
//    public Car(string Brand, string Model, int Year, int Price, string Color)                                                                                                                       
//    {
//        this.Brand = Brand;
//        this.Model = Model; 
//        this.Year = Year;   
//        this.Price = Price;
//        this.Color = Color;
//    }
//    public void display_info()
//    {
//        Console.WriteLine($"{Brand} {Model}, {Year} - года, цвет - {Color}, цена - {Price}");
//    }
//}
//class Program
//{
    
//    static void Main()
//    {
//        Car car_1 = new Car("машина", "мощная", 2026, 2400000, "Чёрный" );
//        Car car_2 = new Car("автомобиль", "быстрый", 1924, 1000000, "Красный" );
//        Car car_3 = new Car("машина", "два", 2005, 562362361, "Жёлтый" );

//        car_1.display_info();
//        car_2.display_info();
//        car_3.display_info();
         //Human petya = new Human("Петя", 30);
        //Human vasya = new Human("Вася", 30);
        //petya.Hello(vasya);
        //vasya.Hello(petya);

        //Console.WriteLine("введите количество задач");
        //int amount = int.Parse(Console.ReadLine());
        //string[] Tasks = new string[amount];
        //for(int i = 0; i < Tasks.Length; i++)
        //{
        //    Console.WriteLine("Введите " + (i+1) + " Задачу");
        //    Tasks[i] = Console.ReadLine();
        //}
        //Console.WriteLine();
        //for (int i = 0; i < Tasks.Length; i++)
        //{
        //    Console.WriteLine(Tasks[i]);
        //}


        //static void Main()
        //{
        //    int[,,,] nums = new int[5, 5, 5, 5];
        //    for (int i = 0; i < nums.GetLength(0); i++)
        //        for (int j = 0; j < nums.GetLength(1); j++)
        //            for (int k = 0; k < nums.GetLength(2); k++)
        //                for (int o = 0; o < nums.GetLength(3); o++)
        //                    nums[i, j, k, o] = 242;
        //    foreach (int num in nums)
        //        Console.Write(num);
        //}

        //int[,] nums = { { 44, 55, 66 }, { 99, 99, 99 } };


        //int[][] nums =
        //{
        //    new int[]{4,6,7,8,9,22},
        //    new int[]{442,55,77,809},
        //    new int[]{4}
        //};
        //Console.WriteLine(nums[1][3]);


        //    Random rand = new Random();
        //    int[][] nums = new int[3][];
        //    nums[0] = new int[5];
        //    nums[1] = new int[5];
        //    nums[2] = new int[5];

        //    int sum = 0;

        //    for (int i = 0; i < nums.Length; i++)
        //        for (int j = 0; j < nums[i].Length; j++)
        //        {
        //            nums[i][j] = rand.Next(0,101);
        //            sum += nums[i][j];
        //            Console.Write(nums[i][j] + " ");

        //        }

        //    Console.WriteLine("\n" + sum);


        //string[] variants = { "КАМЕНЬ", "НОЖНИЦЫ", "БУМАГА" };

        //int pc = new Random().Next(0, 3);

        //    Console.WriteLine("1 - камень 2 - ножницы 3 - бумага");
        //    int user_input = int.Parse(Console.ReadLine());
        //    Console.WriteLine($"PC: {variants[pc]} || User: {variants[user_input - 1]}");

        //    bool win = user_input % 3 == pc;
        //    bool tie = user_input - 1 == pc;

        //    if (win) Console.WriteLine("Победил user");
        //    else if (tie) Console.WriteLine("Это ничья");
        //    else Console.WriteLine("Победил пк");

        //Random rand = new Random();
        //int[][] nums = new int[1][];
        //nums[0] = new int[5];
        //for (int i = 0; i < nums.Length; i++)
        //    for (int j = 0; j < nums[i].Length; j++)
        //    {
        //        nums[i][j] = rand.Next(0, 101);
        //    }
        //int[,] ars = new int[1, 5];
        //for (int i = 0; i < ars.GetLength(0); i++)
        //    for (int j = 0; j < ars.GetLength(1); j++)
        //    {
        //        ars[i, j] = nums[i][j];
        //    }
        //foreach (int i in ars)
        //{
        //    Console.WriteLine(i);
        //}
        //int num = 0;
        // task1

        //    Random rand = new Random();
        //    int[] nums = new int[15];
        //    for (int i = 0; i < nums.Length; i++)
        //    {
        //        nums[i] = rand.Next(1, 101);
        //        if ((nums[i] % 2) == 0)
        //        {
        //            Console.WriteLine(nums[i]);
        //        }

        //    }
        //}

        //task2
        //int count_p = 0, count_o = 0, count_0 = 0;
        //    Random rand = new Random();
        //int[] nums = new int[20];
        //for (int i = 0; i < nums.Length; i++)
        //{
        //    nums[i] = rand.Next(0, 101)-50;
        //    if (nums[i] < 0) count_o++;
        //    if (nums[i] > 0) count_p++;
        //    if (nums[i] == 0) count_0++;
        //    Console.WriteLine(nums[i]);
        //}
        //Console.WriteLine(count_p + " -Кол-во положительных\n" +count_o + " -Кол-во отрицательных\n"+ count_0 +" -Кол-во нулей"  );

        //task3
        //    Random rand = new Random();
        //    int sum = 0;
        //    int[] nums = new int[10];
        //    for (int i = 0; i < nums.Length; i++)
        //    {
        //        nums[i] = rand.Next(1, 11);
        //        if (i % 2 == 0)
        //        {
        //            sum += nums[i];
        //        }
        //        Console.WriteLine(nums[i]);
        //    }
        //    Console.WriteLine("\n" +sum);
        //

        //task4
        // Random rand = new Random();
        //int[] nums = new int[12];
        //for (int i = 0; i < nums.Length; i++)
        //{
        //    nums[i] = rand.Next(1, 101);
        //    Console.WriteLine(nums[i]);

        //}
        //for (int i = 0; i < nums.Length; i++)
        //{
        //if (nums[i] == nums.Max())
        //{
        //    Console.WriteLine("\nМаксимальный элемент - " + nums[i] + "под индексом " + i);
        //}
        //}
    }

}
