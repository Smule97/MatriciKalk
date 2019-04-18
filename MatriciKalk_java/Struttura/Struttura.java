package Struttura;

import Exception.Eccezione;
import java.math.*;
import java.util.Vector;

public abstract class Struttura {
    private Vector<Integer> dim=new Vector<Integer>();
    private int id;
    
    public Struttura(int[] vet, int n){
        for(int i=0; i<n; i++)
            dim.add(vet[i]);
    }
    
    public Struttura(int d1, int d2){
        dim.add(d1);
        dim.add(d2);
    }
     public int getDimAt(int p){
         return dim.elementAt(p);
     }
     
     public int getId(){
         return id;
     }
    
     public abstract Struttura somma(Struttura mat)throws Eccezione;
     public abstract Struttura differenza(Struttura mat)throws Eccezione;
     public abstract Struttura moltiplicazione(Struttura mat)throws Eccezione;
     public abstract Struttura potenza(int exp);
     
    protected void setId(int i){
        id=i;
    }
}
