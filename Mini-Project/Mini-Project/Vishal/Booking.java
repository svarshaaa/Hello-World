package Vishal;
import java.util.*;
import Exxceptions.*;
import java.time.LocalDate;
import java.time.temporal.ChronoUnit;
public class Booking extends Search{
  String time;
  int dose;
  String date1;
  String date2;
  Scanner s=new Scanner(System.in); 
    public void display()
    {
      System.out.println("ZONE : "+zone);
      System.out.println("\nVACCINE : "+vaccine);
      System.out.println("\nCENTRE : "+location);
      System.out.println("\nTIME : "+time);
      System.out.println("\nDOSE : "+dose);
      System.out.println("\nDate for Dose1 : "+date1);
      System.out.println("\nDate for Dose2 : "+date2);
    }
    public void slot(){
      String []slots={"11:00AM-1:00PM","9:00AM-11:00AM","1:00PM-3:00PM"};
      for(int i=0;i<slots.length;i++)
        System.out.print(slots[i] + "\t");
      System.out.print("\nEnter the time slot -");
      int sl=s.nextInt();
      time=slots[sl-1]; 
    }
    public void dose1()
    {
      System.out.println("Enter date ****YYYY-MM-DD****");
      date1=s.next();
      dose=1; 
      Location();
      slot();
    }
    public void dose2()
    {
      dose=2;
      System.out.println("Enter date ****YYYY-MM-DD****");
      date2=s.next();
        try{
              LocalDate dateBefore = LocalDate.parse(date1);
	            LocalDate dateAfter = LocalDate.parse(date2);
	            long noOfDaysBetween = ChronoUnit.DAYS.between(dateBefore, dateAfter);
	            System.out.println(noOfDaysBetween);
              if(noOfDaysBetween<86)
                  throw new DoseException("You are not eligible to take dose 2");
              else
              {
                slot();
                Location();
              } 
        }
        catch(DoseException e){
          System.out.println(e);
        }
      }
    
}