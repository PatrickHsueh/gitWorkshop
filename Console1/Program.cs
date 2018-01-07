using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Console1
{
    class Program
    {
        static void Main(string[] args)
        {
            test();
        }

        public static void test()
        {
            String directory = @"g:\xx\";
            String[] linesOld = File.ReadAllLines(Path.Combine(directory, "PDC1_old.csv"));
            String[] linesNew = File.ReadAllLines(Path.Combine(directory, "PDC1.csv"));

            IEnumerable<String> onlyNew = linesNew.Except(linesOld);

            File.WriteAllLines(Path.Combine(directory, "Result.txt"), onlyNew, Encoding.ASCII);
        }
    }
}
