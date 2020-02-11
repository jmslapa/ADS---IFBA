package entities;
public class Patrimonio extends Conta{
    
    public Patrimonio(String nome){
        super(nome);
    }
    
    public void debitar(Double valor) {
        this.saldo -= valor;
    }
    
    public void creditar(Double valor) {
        this.saldo += valor;
    }
}