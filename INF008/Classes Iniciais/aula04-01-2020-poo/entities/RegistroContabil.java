package entities;
public class RegistroContabil {

    private String nome;
    private String cnpj;
    private BalancoContabil balanco;
    private LivroLancamentoContabil livro;
    
    public RegistroContabil(String nome, String cnpj){
        this.setNome(nome);
        this.cnpj = cnpj;
        balanco = new BalancoContabil();
        livro = new LivroLancamentoContabil();
    }
    
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public String getCnpj() {
		return cnpj;
	}

	public void setCnpj(String cnpj) {
		this.cnpj = cnpj;
	}

	public BalancoContabil getBalanco() {
		return balanco;
	}

	public LivroLancamentoContabil getLivro() {
		return livro;
	}    
}
