import Struttura.*;
import Exception.Eccezione;

class Stampa{
    public void StampaMat(Matrice mat){
        for(int i=0; i<mat.getDimAt(0); i++){
            for(int j=0; j<mat.getDimAt(1); j++)
                System.out.print(mat.getValue(i, j)+" ");
             System.out.println("");
        }
        System.out.println("");
    }
    
    public void StampaVect(Vettore vect){
         for(int j=0; j<vect.getDimAt(0); j++)
                System.out.println(vect.getValue(j));
    }
}


public class Esempio {
    
    public static void main(String[] args) {
       double[] val1={1,2,3,4,5,6,7,8,9};
       double[] val2={1,2,3,0,4,5,0,0,6};
       double[] val3={1,0,0,2,3,0,4,5,6};
       double[] val4={1,2,3};
       double[] val5={1,0,0,0,1,0,0,0,1};
       
       Stampa st=new Stampa();
      
       
       try{
            Matrice mat=new Matrice(val1,3,3);
            MatriceTriangolare mt1=new MatriceTriangolare(val2,'s',3);
            MatriceTriangolare mt2=new MatriceTriangolare(val3,'i',3);
            MatriceUnitaria mu=new MatriceUnitaria(val5,3);
            Vettore vect=new Vettore(val4,3);
            
            System.out.println("Somma tra due matrici");
            st.StampaMat(mat.somma(mat));
            System.out.println("Somma tra Matrice unitaria e matrice");
            st.StampaMat(mat.somma(mu));
            System.out.println("Differenza tra matrice tr. superiore e inferiore");
            st.StampaMat(mt1.differenza(mt2));
            System.out.println("Moltiplicazione tra due matrici triangolari");
            st.StampaMat(mt1.moltiplicazione(mt2));
            System.out.println("Elevamento a potenza di una matrice");
            st.StampaMat(mt2.potenza(7));
            System.out.println("Moltiplicazione tra vettore e matrice");
            st.StampaVect(mat.moltiplicazioneMV(vect));
            System.out.println("Moltiplicazione tra vettori");
            Vettore v1=vect.moltiplicazione(vect);
            st.StampaVect(v1);
            System.out.println("Differenza tra vettori con dimmensione errata");
            st.StampaVect(vect.differenza(v1));
       }
       catch(Eccezione e){
           System.out.println("Eccezione: " + e.getError());
       }
    }
    
}
