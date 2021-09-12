import java.io.*;
class monk3
{
    BufferedReader br;
    int T,N;long K,C;
    String A,B;
    monk3()
    {
        br=new BufferedReader(new InputStreamReader(System.in));
        T=0;
        K=0;
        N=0;
        C=0;
        A="";
        B="";
    }
    void input()throws IOException
    {
        String s1=br.readLine();
        String s[]=s1.split(" ");
        N=Integer.parseInt(s[0]);
        K=Long.parseLong(s[1]);
        A=br.readLine();
    }
    String checkBiggest(String a,int n)
    {
        String b=a;
        for(long i=0;i<n;i++)
        {
            a=shift(a,n);
            if(a.compareTo(b)>0)
            b=a;
        }
        return(b);
    }
    String shift(String a,int n)
    {
        String a1="";
        for(int i=0;i<n;i++)
        {
            if(i+1<n)
            a1+=a.charAt(i+1);
            else
            a1+=a.charAt(i+1-n);
        }
        return(a1);
    }
    void howManyInOne()
    {
        String a1=A;
        for(int i=0;i<N;i++)
        {
            if(a1.equals(B))
            C++;
            a1=shift(a1,N);
        }
    }
    void calc()throws IOException
    {
        T=Integer.parseInt(br.readLine());
        for(int i=0;i<T;i++)
        {
            input();
            B=checkBiggest(A,N);
            howManyInOne();
            long c=0, f=0;
            if(K>C)
            f=(long)(K/C-1)*(N);
            if(K%C==0)
            K=C;
            else
            K=(long)K%C;
            while(true)
            {
                if(A.compareTo(B)==0)
                c++;
                if(c==K)
                break;
                f++;
                A=shift(A,N);
            }
            System.out.println(f);
        }
    }
    public static void main(String args[])throws IOException
    {
        monk3 o = new monk3();
        o.calc();
    }
}