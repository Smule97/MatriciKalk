package Exception;
public class Eccezione extends Exception{
	
    public Eccezione(String error){
		super(error);
	}
	public String getError(){
		return this.getMessage();
	}
}
