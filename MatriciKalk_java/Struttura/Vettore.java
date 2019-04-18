package Struttura;
import Exception.Eccezione;
public class Vettore extends Struttura{
    private double[] value;
    public Vettore(double[] val, int d){
        super(d,0);
        value=val;
        setId(4);
    }
    
    public double getValue(int p){
        return value[p];
    }
    
    public void insertValue(double[] v){
        value=v;
    }
    
  public Vettore somma(Struttura mat) throws Eccezione{
    Vettore vet=(Vettore)mat;
    if(getDimAt(0)==vet.getDimAt(0)){
        double[] ris=new double[getDimAt(0)];
        for(int i=0; i<getDimAt(0);i++){
            ris[i]=value[i]+vet.getValue(i);
        }
        return new Vettore(ris,getDimAt(0));
    }
    else{
        throw new Eccezione("Dimensioni non valide. Devono essere uguali.");
    }
  }
  
  public Vettore differenza(Struttura mat)throws Eccezione{
    Vettore vet=(Vettore)mat;
    if(getDimAt(0)==vet.getDimAt(0)){
        double[] ris=new double[getDimAt(0)];
        for(int i=0; i<getDimAt(0);i++){
            ris[i]=value[i]-vet.getValue(i);
        }
        return new Vettore(ris,getDimAt(0));
    }
    else{
       throw new Eccezione("Dimensioni non valide. Devono essere uguali.");
    }
  }
  
  public Vettore moltiplicazione(Struttura mat)throws Eccezione{
    Vettore vet=(Vettore)mat;
    if(getDimAt(0)==vet.getDimAt(0)){
        double[] ris=new double[1];
        for(int i=0; i<getDimAt(0);i++){
            ris[0]+=value[i]*vet.getValue(i);
        }
        return new Vettore(ris,1);
    }
    else{
        throw new Eccezione("Dimensioni non valide. Devono essere uguali.");
    }
  }
  
  public Vettore potenza(int exp){
    double[] ris=new double[getDimAt(0)];
    for(int i=0; i<getDimAt(0);i++){
        ris[i]=Math.pow(value[i], exp);
    }
    return new Vettore(ris,getDimAt(0));
  }
}
