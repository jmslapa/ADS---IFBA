public class RegistroContabil {

    private String nome;
    private Integer cnpj;
    private BalancoContabil balanco;
    private LivroLancamentoContabil livro;
    
    public RegistroContabil(String nome, Integer cnpj){
        this.nome = nome;
        this.cnpj = cnpj;
    }
}
