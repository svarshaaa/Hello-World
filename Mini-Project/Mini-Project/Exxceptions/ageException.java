package Exxceptions;
public class ageException extends Exception
{
  String msg;
  public ageException(String m)
  {
    msg=m;
  }
  public String toString()
  {
    return msg;
  }
}
