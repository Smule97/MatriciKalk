package Struttura;
import Exception.Eccezione;
public class Matrice extends Struttura {
	private double[] value;
	
	public Matrice(double[] val, int d1, int d2){
            super(d1,d2);
	    value=val;
	    setId(1);
	}

	public double getValue(int x, int y){
	    return value[y+x*getDimAt(1)];
	}

	public void setValue(int x, int y,double val){
	    value[y+x*getDimAt(1)]=val;
	}

	public void insertValue(double[] v){
	    value=v;
	}

	public Matrice somma(Struttura m)throws Eccezione{
	    Matrice mat=(Matrice)m;
	    if(getDimAt(0)==mat.getDimAt(0) && getDimAt(1)==mat.getDimAt(1)){
	        double[] ris=new double[getDimAt(0)*getDimAt(1)];
	        for(int i=0; i<getDimAt(0);i++){
	            for(int j=0; j<getDimAt(1); j++){
	                ris[j+i*getDimAt(0)]=getValue(i,j) + mat.getValue(i,j);
	            }
	        }
	        return new Matrice(ris,getDimAt(0),getDimAt(1));
	    }
	    else{
	       throw new Eccezione("Dimensioni non valide. Devono essere uguali.");
	    }
	}

	public Matrice differenza(Struttura m)throws Eccezione{
	    Matrice mat=(Matrice)m;
	    if(getDimAt(0)==mat.getDimAt(0) && getDimAt(1)==mat.getDimAt(1)){
	    	double[] ris=new double[getDimAt(0)*getDimAt(1)];
	        for(int i=0; i<getDimAt(0);i++){
	            for(int j=0; j<getDimAt(1); j++){
	                ris[j+i*getDimAt(0)]=getValue(i,j)-mat.getValue(i,j);
	            }
	        }
	        return new Matrice(ris,getDimAt(0),getDimAt(1));
	    }
	    else{
	        throw new Eccezione("Dimensioni non valide. Devono essere uguali.");
	    }
	}

	public Matrice moltiplicazione(Struttura m)throws Eccezione{
	    Matrice mat=(Matrice)m;
            if(getDimAt(1)==mat.getDimAt(0)){
                double[] ris=new double[getDimAt(0)*mat.getDimAt(1)];
                int cont=0;

                for(int i=0; i<getDimAt(0); i++){
                    for(int j=0; j<mat.getDimAt(1); j++){
                        ris[cont]=0;
                        for(int k=0; k<getDimAt(1); k++){
                            ris[cont] += mat.getValue(k,j) * getValue(i,k);
                        }
                        cont++;
                    }
                }
                return new Matrice(ris,getDimAt(0),mat.getDimAt(1));
            }
            else{
                throw new Eccezione("Dimensioni non valide.");
            }

	}

	public Matrice potenza(int exp){
            double[] ris=new double[getDimAt(0)*getDimAt(1)];
	    for(int i=0; i<getDimAt(0)*getDimAt(0);i++){
                ris[i]=Math.pow(value[i] , exp);
	    }
	    return new Matrice(ris,getDimAt(0),getDimAt(1));
	  
	}

	public boolean ortogonale()throws Eccezione{
            double[] trasposta=new double[getDimAt(0)*getDimAt(1)];
	    int cont=0;
	    if(getDimAt(0)==getDimAt(1)){
	        for(int i=0;i<getDimAt(0);i++){
	            for(int j=0;j<getDimAt(0);j++){
	                trasposta[cont]=getValue(j,i);
	                cont++;
	            }
	        }
	        Matrice tmp=moltiplicazione(new Matrice(trasposta,getDimAt(1),getDimAt(0)));
	        boolean veroZero=true, veroUno=true;;
	        cont=0;
	        for(int i=0; i<getDimAt(0);i++){
	            for(int j=0;j<getDimAt(0);j++){
	                if(i==j){
	                    if(tmp.getValue(i,j)!=1)
	                        veroUno=false;
	                }
	                else{
	                    if(tmp.getValue(i,j)!=0)
	                        veroUno=false;
	                }
	            }
	        }
	        if(veroUno && veroZero){
	            return true;
	        }
	        else{
	            throw new Eccezione("La matrice non e' ortogonale.");
	        }
	    }
	    else{
	        throw new Eccezione("Dimensioni non valide. Devono essere uguali.");
	    }
	}

	public Vettore moltiplicazioneMV(Vettore v)throws Eccezione{
	    Vettore vet=(Vettore)v;
	    if(getDimAt(1)==vet.getDimAt(0)){
                double[] ris=new double[getDimAt(0)];

                for (int i=0;i<getDimAt(0);i++) {
                    ris[i]=0;
                    for (int j=0;j<getDimAt(1);j++) {
                        ris[i]+=getValue(i,j) * vet.getValue(j);
                    }
                }

                return new Vettore(ris,getDimAt(0));
            }
	    else{
	        throw new Eccezione("Dimensioni non valide. Devono essere uguali.");
	    }

	}
}