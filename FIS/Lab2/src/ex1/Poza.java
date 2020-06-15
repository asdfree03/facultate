/*
package ex1;
import java.util.*;
public class Poza {
}
interface Employee{
    public double computeSalary(){}
    public void addTimeCard(TimeCard tc){}
}
class RealEmployee implements Employee{
    private int id;
    private double perHour;
    private ArrayList<TimeCard> itsCards = new ArrayList<TimeCard>();
    public RealEmployee(int id,double perHour){
        this.id = id;
        this.perHour = perHour;
    }
    public double computeSalary(){

    }
    public void addTimeCard(TimeCard tc){

    }
}
class ProxyEmployee implements Employee{
    private static String password;
    private static String readPasswd;
    private RealEmployee employee;
    public ProxyEmployee(int id, double perHour){
        employee = new RealEmployee(id,perHour);
    }
    public static void setPassword(String passwd){
        this.password = passwd;
    }
     public static void readPaswword(){
         System.out.printf(password);
    }
    private static boolean checkPassword(){
        if(password) return true;
        return false;
    }
    public double computeSalary(){
        employee.computeSalary();
    }
    public void addTimeCard(TimeCard tc){}
    employee.addTimeCard(tc);
}
 class TimeCard{
    private double workedHours;
    public TimeCard(double workedHours){}
    public double generatedIncome(double perHour){}
        }

        */
