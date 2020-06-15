import java.util.*;
class Problema{
    private double dificultate;
    public Problema() {
        this.dificultate = Math.random();
    }

    public double getDificultate() {
        return dificultate;
    }
}
abstract class Concurent{
    protected int nr_prob = 0;
    protected int timp_tot = 0;
    protected double grad_preg;
    public Concurent() {
        this.grad_preg = Math.random();
    }

    public int getNr_prob() {
        return nr_prob;
    }

    public int getTimp_tot() {
        return timp_tot;
    }

    abstract public void rezolvaProblema(Problema p);
}
class Concurent_Incepator extends Concurent{
      public void rezolvaProblema(Problema p){
          if(this.grad_preg >= p.getDificultate()){
              this.nr_prob++;
              this.timp_tot+= p.getDificultate()>0.5 ? (1-this.grad_preg)*2000 : (1-this.grad_preg)*1000;
          }
      }
}
class Concurent_Experimentant extends Concurent{
    private ArrayList<Concurs> concursuri = new ArrayList<Concurs>();
    public void rezolvaProblema(Problema p){
        Iterator<Concurs> ir = concursuri.iterator();
        while(ir.hasNext()){
            Concurs c = ir.next();
            if(c.aFost(p)) timp_tot+=0;
            else timp_tot+=p.getDificultate()>0.5 ? (1-this.grad_preg)*2000 : (1-this.grad_preg)*1000;
        }
    }
}
abstract class Concurs{
    protected ArrayList<Concurent> concurenti = new ArrayList<Concurent>();
    protected ArrayList<Problema> probleme;
    public Concurs(int nr){
        probleme = new ArrayList<Problema>(nr);
    }
    public boolean aFost(Problema p){
        if(probleme.contains(p)) return true;
        return false;
    }
    public Concurent getCastigator(){
        Iterator<Concurent> ic = concurenti.iterator();
        Concurent castigator = concurenti.get(0);
        int nmax = castigator.getNr_prob();
        while(ic.hasNext()){
            Concurent c = ic.next();
            if(c.getNr_prob()>nmax) {
                castigator = c;
                nmax = c.getNr_prob();
            }
            else if(c.getNr_prob() == castigator.getNr_prob()){
                if(castigator.getTimp_tot()>c.getTimp_tot()) {
                    castigator = c;
                }
            }
        }
        return castigator;
    }
    public void start(){
        for(Concurent c : concurenti){
            for(Problema p : probleme) c.rezolvaProblema(p);
        }
    }
}
class Concurs_Simplu extends Concurs{
    public Concurs_Simplu(ArrayList<Concurent> concurenti, int nr) {
        super(nr);
        this.concurenti = concurenti;
    }
}
class Concurs_Regional extends Concurs{
    private ArrayList<Concurs> concursuri = new ArrayList<Concurs>();
    public Concurs_Regional(int nr,ArrayList<Concurs> concursuri,ArrayList<Concurent> concurenti) {
        super(nr);
        this.concursuri = concursuri;
        this.concurenti = concurenti;
    }
    public void start(){
        ArrayList<Concurent> castigatori1 = new ArrayList<Concurent>();
        for(Concurs c: concursuri){
            c.start();
            castigatori1.add(c.getCastigator());
        }
        concurenti = castigatori1;
        super.start();
    }

}


class StatLitereMici{
    public Integer numaraLitereMici(String s){

    }
}
class StatCifre{
    public Integer numaraCifre(String s){}
}
class Executor{
    public ArrayList<String> execute(String[] stringuri,Object[] instante){
        ArrayList<Integer> rezultat = new ArrayList<Integer>();
        for(int i = 0;i<stringuri.length;i++){
            if(instante[i] instanceof StatCifre){
                StatCifre aux = ((StatCifre)instante[i]);
                rezultat.add(aux.numaraCifre(stringuri[i]));
            }
            else ...
        }
    }
}
public class Main{
    public static void main(String[] args) {

    }
}