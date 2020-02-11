package entities;

public class BalancoContabil {

	private Ativo ativo;
	private Passivo passivo;
	private Patrimonio patrimonio;

	public BalancoContabil() {
	}

	public BalancoContabil(Ativo ativo, Passivo passivo, Patrimonio patrimonio) {
		this.ativo = ativo;
		this.passivo = passivo;
		this.patrimonio = patrimonio;
	}

	public Ativo getAtivo() {
		return ativo;
	}

	public void setAtivo(Ativo ativo) {
		this.ativo = ativo;
	}

	public Passivo getPassivo() {
		return passivo;
	}

	public void setPassivo(Passivo passivo) {
		this.passivo = passivo;
	}

	public Patrimonio getPatrimonio() {
		return patrimonio;
	}

	public void setPatrimonio(Patrimonio patrimonio) {
		this.patrimonio = patrimonio;
	}

}