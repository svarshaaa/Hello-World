import java.io.*;
import java.util.*;
import Nish.*;
class dummy
{
  public static void main(String args[])
  {
    File myobj = new File("certificate.txt");
    try
    {
    if(myobj.createNewFile())
      System.out.println("Certificate generated");
    }
    catch(IOException e)
    {
      System.out.println("Certificate ");
    }

    //writing
    try
    {
      FileWriter mw = new FileWriter("certificate.txt");
      mw.write("Beneficiary Details");
      mw.write("Beneficiary Name:"+r.name);
      mw.write("Age"+r.age);
      mw.write("ID proof:"+r.aadhar_no);
      mw.write("Beneficiary Reference ID:"+Math.random()*(10000000-90000000+1)+90000000);
      mw.close();
    }
    catch(IOException e)
    {
      System.out.println("Error");  
    }

    //reading
    try
    {
      Scanner mr = new Scanner(myobj);
      while(mr.hasNextLine())
      {
        System.out.println(mr.nextLine());
      }
      mr.close();
    }
    catch(FileNotFoundException e)
    {
      System.out.println("couldnt read certificate");
    }
  }
}