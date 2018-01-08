﻿using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Diagnostics;
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


            String xxx = AppendAll(onlyNew, "");

            int counter = 0;
            foreach (var item in onlyNew)
            {
                String xx = UTF8toASCII(item);
                counter++;
            }
            //File.WriteAllText(Path.Combine(directory, "Result.txt"), onlyNew, Encoding.ASCII);
            // File.WriteAllLines(Path.Combine(directory, "Result.txt"), onlyNew, Encoding.ASCII);
        }

        public static String convertToAnsi(String input)
        {
            Encoding utf8 = Encoding.UTF8;
            Encoding ascii = Encoding.ASCII;

            String output = ascii.GetString(Encoding.Convert(utf8, ascii, utf8.GetBytes(input)));
            Debug.WriteLine(input);
            Debug.WriteLine(output);
            return output;
        }

        public static String UTF8toASCII(String text)
        {
            System.Text.Encoding utf8 = System.Text.Encoding.UTF8;
            Byte[] encodedBytes = utf8.GetBytes(text);
            Byte[] convertedBytes =
                    Encoding.Convert(Encoding.UTF8, Encoding.ASCII, encodedBytes);
            System.Text.Encoding ascii = System.Text.Encoding.ASCII;

            return ascii.GetString(convertedBytes);
        }
        
        ///*
        public static String AppendAll(IEnumerable<String> collection, String seperator)
        {
            using (var enumerator = collection.GetEnumerator())
            {
                if (!enumerator.MoveNext())
                {
                    return String.Empty;
                }

                var builder = new StringBuilder().Append(enumerator.Current);

                while (enumerator.MoveNext())
                {
                    builder.Append(seperator).Append(enumerator.Current);
                }

                return builder.ToString();
            }
        }
        //*/


    }
}
