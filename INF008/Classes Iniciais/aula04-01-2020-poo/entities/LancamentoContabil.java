package entities;
public class LancamentoContabil {

	private String desc;
	private Double valor;
    private Conta creditar;
    private Conta debitar;
    
    public LancamentoContabil(String desc, Double valor, Conta creditar, Conta debitar){
        this.creditar = creditar;
        this.debitar = debitar;
    }

	public Conta getCreditar() {
		return creditar;
	}

	public void setCreditar(Conta creditar) {
		this.creditar = creditar;
	}

	public Conta getDebitar() {
		return debitar;
	}

	public void setDebitar(Conta debitar) {
		this.debitar = debitar;
	}

	public String getDesc() {
		return desc;
	}

	public void setDesc(String desc) {
		this.desc = desc;
	}

	public Double getValor() {
		return valor;
	}

	public void setValor(Double valor) {
		this.valor = valor;
	} 
}