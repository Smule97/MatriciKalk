package Struttura;
import Exception.Eccezione;
public class MatriceUnitaria extends Matrice{
	
	public MatriceUnitaria(double[] val, int d1) {
	    super(val,d1,d1);
	    setId(3);
	}

	public Matrice somma(Struttura m)throws Eccezione{
	    Matrice mat=(Matrice)m;
	    if(getDimAt(0)==mat.getDimAt(0)){
	        double[] ris=new double[getDimAt(0)*getDimAt(1)];
	        for(int i=0; i<getDimAt(0);i++){
	            for(int j=0; j<getDimAt(1); j++){
	                if(i==j){
	                    ris[j+i*getDimAt(0)]=getValue(i,j) + mat.getValue(i,j);
	                }
	                else{
	                    ris[j+i*getDimAt(0)]=mat.getValue(i,j);
	                }
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
	                if(i==j){
	                    ris[j+i*getDimAt(0)]=getValue(i,j) - mat.getValue(i,j);
	                }
	                else{
	                    ris[j+i*getDimAt(0)]=mat.getValue(i,j);
	                }
	            }
	        }
	        return new Matrice(ris,getDimAt(0),getDimAt(1));
	    }
	    else{
	        throw new Eccezione("Dimensioni non valide. Devono essere uguali.");
	    }
	}

	public MatriceUnitaria potenza(int exp){
	    double[] ris=new double[getDimAt(0)*getDimAt(1)];
	    for(int i=0; i<getDimAt(0);i++){
	        for(int j=0; j<getDimAt(1); j++){
	            if(i==j)
	                ris[j+i*getDimAt(0)]=Math.pow(getValue(i,j) , exp);
	        }
	    
            }
	    return new MatriceUnitaria(ris,getDimAt(0));	    
	}
        
        
}

