package entities;
import java.util.*;

public class LivroLancamentoContabil {

    List<LancamentoContabil> list;
    
    public LivroLancamentoContabil() {
    	list = new ArrayList<LancamentoContabil>();
    }
    
    public void addLancamento(LancamentoContabil lancamento) {
    	list.add(lancamento);
    }
    
    public List<LancamentoContabil> getBalanco() {
    	return list;
    }
    
    
}