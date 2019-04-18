package Struttura;
import Exception.Eccezione;
public class MatriceTriangolare extends Matrice{
	private char tipo;
	
	public MatriceTriangolare(double[] val,char t, int d1){
            super(val,d1,d1);
            tipo=t;
	    setId(2);
	}

	public char getTipo(){
	    return tipo;
	}
	
	public Matrice somma(Struttura m) throws Eccezione{
	    MatriceTriangolare mat=(MatriceTriangolare)m;
	    if(mat.getDimAt(0)==getDimAt(0)){
	        double[] ris=new double[getDimAt(0)*getDimAt(1)];
	        int cont=0;
	        if(tipo==mat.getTipo()){
	            if(tipo=='s'){
	                for(int i=0; i<getDimAt(0);i++){
	                    for(int j=0; j<getDimAt(1);j++){
	                        j+=cont;
	                        ris[j+i*getDimAt(0)]=getValue(i,j) + mat.getValue(i,j);
	                    }
	                    cont++;
	                }
	            }
	            else if(tipo=='i'){
	                cont=getDimAt(1)-1;
	                for(int i=0; i<getDimAt(0);i++){
	                    for(int j=getDimAt(1); j>0;j--){
	                        j-=cont;
	                        ris[j+i*getDimAt(0)]=getValue(i,j) + mat.getValue(i,j);
	                    }
	                    cont--;
	                }
	            }
	            return new MatriceTriangolare(ris,tipo,getDimAt(0));
	        }
	        else{
	            return super.somma(m);
	        }
	    }
	    else{
	        throw new Eccezione("Dimensioni non valide. Devono essere uguali.");
	    }
	}

	public Matrice differenza(Struttura m) throws Eccezione{
	    MatriceTriangolare mat=(MatriceTriangolare)m;
	    if(mat.getDimAt(0)==getDimAt(0)){
	        double[] ris=new double[getDimAt(0)*getDimAt(1)];
	        int cont=0;
	        if(tipo==mat.getTipo()){
	            if(tipo=='s'){
	                for(int i=0; i<getDimAt(0);i++){
	                    for(int j=0; j<getDimAt(1);j++){
	                        j+=cont;
	                        ris[j+i*getDimAt(1)]=getValue(i,j) - mat.getValue(i,j);
	                    }
	                    cont++;
	                }
	            }
	            else if(tipo=='i'){
	                cont=getDimAt(1)-1;
	                for(int i=0; i<getDimAt(0);i++){
	                    for(int j=getDimAt(1); j>0;j--){
	                        j-=cont;
	                        ris[j+i*getDimAt(1)]=getValue(i,j) - mat.getValue(i,j);
	                    }
	                    cont--;
	                }
	            }
	            return new MatriceTriangolare(ris,tipo,getDimAt(0));
	        }
	        else{
                    return super.differenza(m);
	        }
	    }
	    else{
	        throw new Eccezione("Dimensioni non valide. Devono essere uguali.");
	    }
	}

	public MatriceTriangolare potenza(int exp){
	    double[] ris=new double[getDimAt(0)*getDimAt(1)];
	    for(int i=0; i<getDimAt(0)*getDimAt(1);i++){
	        ris[i]=0;
	    }
	    if(tipo=='s'){
	        for(int i=0; i<getDimAt(0);i++){
	            for(int j=i; j<getDimAt(1);j++){
	                ris[j+i*getDimAt(0)]=Math.pow(getValue(i,j) , exp);
	            }
	        }
	    }
	    else if(tipo=='i'){
	        for(int i=0; i<getDimAt(0);i++){
	            for(int j=0; j<i+1;j++){
	                ris[j+i*getDimAt(0)]=Math.pow(getValue(i,j) , exp);
	            }
	        }

	    }
	    return new MatriceTriangolare(ris,tipo,getDimAt(0));
	}

	
}