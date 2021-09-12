import java.util.*;
class a
{
    int n;
    Scanner sc;
    public static void main(String args[])
    {
        a o=new a();
        o.init();
        System.out.println("Factorial of "+o.n+" is "+o.fact(o.n));
    }
    a()
    {
        n=0;
        sc=new Scanner(System.in);
    }
    void init()
    {
        System.out.println("Enter a number:");
        n=sc.nextInt();
    }
    int fact(int p)
    {
        if(p==1)
        return 1;
        else
        return p*fact(p-1);
    }
}