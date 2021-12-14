package Nish;
import java.util.*;
import Exxceptions.*;
public class register
{
  public String name,gender,aadhar_no;
  public int age;
  public int getInput()
  {
    String name,gender,aadhar_no;
    int age;
    Scanner s=new Scanner(System.in);
    System.out.print("Aadhar no(12 digits):");
    try{
      aadhar_no=s.next();
      if(aadhar_no.length()<12)
        throw new AadharException("Should have 12 digits\n");
      }
      catch(AadharException a)
      {
        System.out.println(a);
        return 0;
      }
    System.out.print("Name: ");
    name=s.next();
    System.out.print("Gender: ");
    gender=s.next();
    try
    {
      System.out.print("Age:");
      age=s.nextInt();
      if(age<18)
        throw new ageException("You are under 18, you cant be a member");
    }
    catch(ageException a)
    {
      System.out.println(a);
      return 0;
    }
    this.name=name;
    this.gender=gender;
    this.age=age;
    this.aadhar_no=aadhar_no;
    return 1 ;
  }  
  public void display()
  {
    System.out.println("Aadhar no:"+aadhar_no+"\nName:"+name+"\nGender:"+gender+"\nAge:"+age);
  }     
}