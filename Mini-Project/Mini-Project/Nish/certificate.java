package Nish;
import java.io.*;
import java.lang.Math.*;
import Vishal.*;
import java.util.*;
public class certificate 
{
  register r;
  Booking b;

  certificate(register r)
  {
    this.r=r;
  }
  certificate(Booking b)
  {
    this.b=b;
  }
  public void display(register r)
  {
    String cert_name=r.name+"certificate";
    File myobj = new File(cert_name);
    try
    {
    if(myobj.createNewFile())
      System.out.println("Certificate generated");
    }
    catch(IOException e)
    {
      System.out.println("Error");
    }

    //writing
    try
    {
      ObjectOutputStream o = new ObjectOutputStream(myobj);
      o.writeObject(r);
    }
    catch(IOException e)
    {
      System.out.println("Error initializing stream");
    }

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