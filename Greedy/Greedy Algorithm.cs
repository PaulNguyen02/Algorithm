using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        static int []value = { 500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000 };
        static void Greedy(int M)
        {
            int count;
            for(int i=0; i< value.Length ;i++)
            {
                count = 0;
                while(M>=value[i])
                {
                    M -= value[i];
                    count++;
                    Console.WriteLine(value[i] + " " + count);
                }
                
            }
        }
        static void Main(string[] args)
        {
            Greedy(155000);
            Console.ReadKey();
        }
    }
}
