public class Passivo extends Conta {
    
    public Passivo(String nome){
        super(nome);
    }
    
    public void debitar(Double valor) {
        this.saldo -= valor;
    }
    
    public void creditar(Double valor) {
        this.saldo += valor;
    }
}