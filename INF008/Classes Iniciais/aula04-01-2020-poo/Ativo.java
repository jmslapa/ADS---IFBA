public class Ativo extends Conta {
    
    public Ativo(String nome){
        super(nome);
    }
    
    public void debitar(Double valor) {
        this.saldo += valor;
    }
    
    public void creditar(Double valor) {
        this.saldo -= valor;
    }
}