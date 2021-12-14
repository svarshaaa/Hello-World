import Nish.*;
import Vishal.*;
import java.util.*;
class Main
{
  static int n=-1;
  static register r[]=new register[4];
  public static int searchAadhar(String aadhar)
  {
    for(int i=0;i<=n;i++)
    {
        if(r[i].aadhar_no.equals(aadhar))
        {    
            return 1;
        }       
    }
    return 0;
  }
  public static void main(String[] args) 
  {
    Booking b[]=new Booking[4];
    int ch;
    String o;
    Scanner s=new Scanner(System.in);
    do{
      System.out.println("1)Register a member 2)Display details 3)Book a slot 5)exit");
      ch=s.nextInt();
      if(ch==1)
      {
        n++;
        r[n]=new register();
        if(r[n].getInput()==1)
        {
          System.out.println("Member was registered successfully");    
        }
        else
        {
          n--;
          System.out.println("Member registration was not successful");
        }
      }
      else if(ch==2)
      {
        for(int i=0;i<n;i++)
          r[i].display();
      }
      else if(ch==3)
      {
        System.out.print("Enter Aadhar:");
        String a=s.next();
        if(searchAadhar(a)!=1)
          System.out.println("Sorry , you arent a registered member");
        else
        {
            b[n]=new Booking();
            System.out.println("Enter Dose Number");
            int dose=s.nextInt();
            if(dose==1)
              b[n].dose1();
            if(dose==2)
              b[n].dose2();
            b[n].display();
            System.out.println("Do you want to confirm your booking ?");
            System.out.println("\nYES/NO\n");
            char opt=s.next().charAt(0);
            OTP ot=new OTP();
            if(opt=='y')
            {
              String otpe=ot.generateOTP();
              System.out.println(otpe);
              System.out.println("Enter the otp to confirm booking");
              o=s.next();
              if(o.equals(otpe))
                System.out.println("BOOKING SUCCESSFUL");
              else
                System.out.println("OTP not matching");
            }
        }
      }
    }while(ch!=5);
  }
}