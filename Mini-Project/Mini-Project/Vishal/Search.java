package Vishal;
import java.util.*;
public class Search
{
  //int opt;
  public String vaccine;
  private int zo;
  private int opt;
  public String zone;
  public String location;
  public 
  //String time;
  //int dose;
  Scanner s=new Scanner(System.in);
    public void zones(){
      String []z={"Adyar","Alandur","Ambattur","Kodambakkam","Madhavaram","Manali"};//"Perungudi","Royapuram","Sholinganallur","Teynampet","Thiru vi ka Nagar","Valasaravakkam"};
      for(int i=0;i<z.length;i++)
        System.out.print((i+1)+") "+z[i] + "\t");
      System.out.println("\nChoose Your Zone\n");
      zo=s.nextInt();
      zo--;
      //System.out.println("Vishal"+zo);
      zone=z[zo];
    }
    public void vac(){
      System.out.print("Choose Vaccine\n 1.COVISHIELD \t 2.COVAXIN\n");
      opt=s.nextInt();
      if(opt==1)
        vaccine="COVISHIELD";
      else if(opt==2)
        vaccine="COVAXIN";

    }
    public void display()
    {
      System.out.println("ZONE : "+zone);
      System.out.println("\nVACCINE : "+vaccine);
      System.out.println("\nCENTRE : "+location);
    }
    public void Location()
    {
        zones();
        vac();
        int vc;
        int run=1;
        String []locations={"Kotturpuram Uphc Dhandayuthapani St","Tharamani Dispensary Radha Nagar Ext","Adambakkam UPHC","Adambakkam Uphc Mannady Amman Koil St","Palavanthangal Uphc New Colony","Mugalivakkam Uphc","Padi Round Building Uphc","Div Office Padi Pudhu Nagar","Varadharajapuram Uphc Ambattur","Kumaran Nagar Uphc West Mambalam","Ashok Nagar UPHC","CIT Nagar UPHC","AE Office Arul Nagar","Puzhal UCHC GNT Road","Puthagaram - Puzhal UPHC","Manali UCHC Nedunchezian Salai","Manali New Town Uphc","New MGR Nagar - Manali UPHC"};
        int []cxvacc={1,1,1,0,1,1,0,0,1,1,1,1,1,1,1,1,1,1};
        int []cdvacc={0,1,0,0,1,0,0,0,1,1,1,1,0,1,1,0,1,1};
        int loc=(zo*3);
        int rloc=loc;
        System.out.print("Location\t\t\tAvailable Vaccines\n");
        for(int i=0;i<3;i++){
          if(vaccine.equals("COVISHIELD"))
          {
            System.out.println(locations[rloc]+ "\t" + cdvacc[rloc] +"\n");
            rloc++;
          }
          else if(vaccine.equals("COVAXIN"))
          {
            System.out.println(locations[rloc]+ "\t" + cxvacc[rloc] +"\n");
            rloc++;
          }
        }
        while(run==1)
        {
          System.out.println("Enter your choice of Vaccination Centre");
          vc=s.nextInt();
          vc--;
          if((cdvacc[vc+loc]==0 && opt==1) || (cxvacc[vc+loc]==0 && opt==2))
            System.out.println("Vaccine not available , Please Enter another centre");
          else
            {
              if(opt==1)
                cdvacc[vc+loc]--;
              else if(opt==2)
                cxvacc[vc+loc]--;
              location=locations[vc+loc];
              run=0;
            }
        }
        //display();
    }
}