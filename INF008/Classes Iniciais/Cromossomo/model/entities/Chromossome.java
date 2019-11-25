package model.entities;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

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
		
		Gene[] a1 = Arrays.copyOfRange(alleles, crossingIndex, alleles.length);
		Gene[] a2 = Arrays.copyOfRange(other.getAlleles(), crossingIndex, other.getAlleles().length);
		
		List<Gene> newAlleles = new ArrayList<>();
		newAlleles.addAll(Arrays.asList(Arrays.copyOfRange(alleles, 0, crossingIndex)));
		newAlleles.addAll(Arrays.asList(a2));
		
		List<Gene> newOtherAlleles = new ArrayList<>();
		newOtherAlleles.addAll(Arrays.asList(Arrays.copyOfRange(other.getAlleles(), 0, crossingIndex)));
		newOtherAlleles.addAll(Arrays.asList(a1));
		
		// this.alleles
		Gene[] allelesAux = new Gene[newAlleles.size()];
		for(int i = 0 ; i < allelesAux.length ; i++) {
			allelesAux[i] = newAlleles.get(i);
		}
		this.setAlleles(allelesAux);
		
		// other.alleles
		Gene[] otherAllelesAux = new Gene[newOtherAlleles.size()];
		for(int i = 0 ; i < otherAllelesAux.length ; i++) {
			otherAllelesAux[i] = newOtherAlleles.get(i);
		}
		other.setAlleles(otherAllelesAux);
	}
	
	@Override
	public String toString() {
		return Arrays.toString(alleles);
	}
	
}
