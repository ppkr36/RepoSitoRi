class Program
{
    static void Main()
    {

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


        string[] variants = { "КАМЕНЬ", "НОЖНИЦЫ", "БУМАГА" };

        int pc = new Random().Next(0, 3);
       
            Console.WriteLine("1 - камень 2 - ножницы 3 - бумага");
            int user_input = int.Parse(Console.ReadLine());
            Console.WriteLine($"PC: {variants[pc]} || User: {variants[user_input - 1]}");

            bool win = user_input % 3 == pc;
            bool tie = user_input - 1 == pc;

            if (win) Console.WriteLine("Победил user");
            else if (tie) Console.WriteLine("Это ничья");
            else Console.WriteLine("Победил пк");

        

    }
       
}