using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp5
{
    class Program
    {
        static void INP(int [,]W, int n)
        {
            Console.WriteLine("Nhap gia tri cho ma tran trong so ");
            for (int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    Console.Write("W["+i+"]["+j+"]=");
                    W[i, j] = int.Parse(Console.ReadLine());
                }
            }
        }
        static int [,]FloydWarshal(int[,] W, int n)
        {
            int inf = 1000;
            int row = n;
            int[,] D = new int[4, 4];
            int[,] pi = new int[4, 4];
            D = W;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if (W[i, j] < inf)
                        pi[i, j] = j;
                    else
                        pi[i, j] = 0;
                }
            }
            for(int k=0;k<n;k++)
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=0; j<n;j++)
                    {
                        if (D[i, j] > D[i, k] + D[k, j])
                            D[i, j] = D[i, k] + D[k, j];
                            pi[i, j] = pi[i, k];
                    }
                }
            }
            return D;
        }
        static void Main(string[] args)
        {
            int [,]W = new int[4,4];
            int[,] Res = new int[4, 4];
            int n;
            Console.WriteLine("Nhap do rong ma tran ");
            n = int.Parse(Console.ReadLine());
            INP(W, n);
            Res = FloydWarshal(W, n);
            Console.WriteLine("W("+n+")");
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Console.Write(Res[i,j]+" ");
                }
                    Console.WriteLine();
            }
            Console.ReadKey();
        }
    }
}
