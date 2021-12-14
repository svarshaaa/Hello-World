package Exxceptions;

public class AadharException extends Exception {
 
    String msg;
    public AadharException(String m)
    {
        msg=m;
    }
    public String toString()
    {
        return msg;
    }
}
