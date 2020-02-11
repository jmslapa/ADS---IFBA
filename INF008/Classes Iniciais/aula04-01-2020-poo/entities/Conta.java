package entities;
public abstract class Conta {
    
    protected String nome;
    protected Double saldo;
    
    public Conta(String nome){
        this.nome = nome;
    }
    
    public String getNome() {
        return this.nome;
    }
    
    public void setNome(String nome) {
        this.nome = nome;
    }
    
    public abstract void debitar(Double valor);
    
    public abstract void creditar(Double valor);
}