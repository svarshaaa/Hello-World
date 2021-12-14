package Exxceptions;
public class DoseException extends Exception
{
  String msg;
  public DoseException(String m)
  {
    msg=m;
  }
  public String toString()
  {
    return msg;
  }
}