package model.entities;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Chromossome {
	
	Gene[] alleles;
	
	public Chromossome() {
	}

	public Chromossome(Gene[] alleles) {
		super();
		this.alleles = alleles;
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
	
	public Chromossome clone() {
		return new Chromossome(alleles);
	}
	
	public Double indentityPercentage(Chromossome other) {		
		boolean bigger;
		double sum = 0.0;		
		if(this == other) {
			return 1.0;
		}		
		if(alleles.length > other.getAlleles().length) {
			bigger = true;
		}else {
			bigger = false;
		}		
		if(bigger) {
			for(int i = 0 ; i < other.getAlleles().length ; i++) {
				if(alleles[i] == null) {
					if(other.getAlleles()[i] != null) {
						sum -= 2;
					}
				}else {
					if(other.getAlleles()[i] == null) {
						sum -= 2;
					}else if(alleles[i].equals(other.getGene(i))) {
						sum += 1;
					}else {
						sum -= 1;
					}
				}
			}
		}else {
			for(int i = 0 ; i < alleles.length ; i++) {
				if(alleles[i] == null) {
					if(other.getAlleles()[i] != null) {
						sum -= 2;
					}
				}else {
					if(other.getAlleles()[i] == null) {
						sum -= 2;
					}else if(alleles[i].equals(other.getGene(i))) {
						sum += 1;
					}else {
						sum -= 1;
					}
				}
			}
		}
		return sum/other.getAlleles().length;
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
