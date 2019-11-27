package model.entities;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Chromossome {
	
	private Gene[] alleles;
	
	public Chromossome() {
	}

	public Chromossome(int size) {
		super();
		this.alleles = new Gene[size];
	}

	public Gene[] getAlleles() {
		return alleles;
	}

	public void setAlleles(Gene[] alleles) {
		this.alleles = alleles;
	}
	
	public Gene getGene(int index) {
		return alleles[index];
	}
        
        public void setGene(int index, Gene gene){
            alleles[index] = gene;
        }
	
	public Chromossome clone() {
            Chromossome clone = new Chromossome(alleles.length);            
            for(int i = 0 ; i < alleles.length ; i++){
                if(getGene(i) != null){
                   clone.setGene(i, alleles[i].clone());
                }
            }
            return clone;
	}
	
	public Double indentityPercentage(Chromossome other) {		
		boolean bigger;
		double sum = 0.0;		
		if(this == other) {
			return 1.0;
		}		
                int max = alleles.length > other.getAlleles().length ? other.getAlleles().length : alleles.length;
                    for(int i = 0 ; i < max ; i++) {
                            if(getGene(i) == null || other.getGene(i) == null) {
                                    if(getGene(i) != null || other.getGene(i) != null) {
                                            sum -= 2;
                                    }
                            }else {
                                    if(getGene(i).equals(other.getGene(i))) {
                                            sum += 1;
                                    }else {
                                            sum -= 1;
                                    }
                            }
                    }
		return sum/alleles.length;
	}
	
	public void merge(Chromossome other, int crossingIndex) {
		
		// this.alleles crossing
		List<Gene> newAlleles = Arrays.asList(Arrays.copyOfRange(alleles, 0, crossingIndex))
				.stream().collect(Collectors.toList());		
		newAlleles.addAll(Arrays.asList(Arrays.copyOfRange(other.getAlleles(), crossingIndex, other.getAlleles().length))
				.stream().collect(Collectors.toList()));				
		// other.alleles crossing
		List<Gene> newOtherAlleles = Arrays.asList(Arrays.copyOfRange(other.getAlleles(), 0, crossingIndex))
				.stream().collect(Collectors.toList());		
		newOtherAlleles.addAll(Arrays.asList(Arrays.copyOfRange(alleles, crossingIndex, alleles.length))
				.stream().collect(Collectors.toList()));
		//new alleles setting
		this.setAlleles(newAlleles.stream().toArray(Gene[]::new));
		other.setAlleles(newOtherAlleles.stream().toArray(Gene[]::new));
	}
	
	@Override
	public String toString() {
		return Arrays.toString(alleles);
	}
	
}
