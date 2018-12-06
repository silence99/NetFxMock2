using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace NetFxMock.Test
{
    class Program
    {
        static void Main(string[] args)
        {
            var t = new TestClass();
            var typ = t.GetType();
            var display = typ.GetMethod("Display");
            var replace = typ.GetMethod("Replace");
            MockUtils.SetMock(t, display.MethodHandle.Value, replace.MethodHandle.Value);
        }
    }

    class TestClass
    {
        public void Display(string a)
        {
            Console.WriteLine(a);
        }
        public void Replace(string a)
        {
            Console.WriteLine("replaced method");
        }
    }
}
