package application;

import model.entities.Chromossome;
import model.entities.Gene;

public class Program {
	
	public static void main(String[] args) {
		
		Gene[] v1 = new Gene[] {new Gene(1), new Gene(2), new Gene(3), new Gene(4), new Gene(5)};
		
		Chromossome c1 = new Chromossome(5);
                c1.setAlleles(v1);
		Chromossome c2 = c1.clone();		
		
		System.out.println("Chromossome 1: " + c1);
		System.out.println("Chromossome 2: " + c2);
		System.out.println("Compatibility: " + c1.indentityPercentage(c2));
		
		c2.setAlleles(new Gene[] {new Gene(10), new Gene(20), new Gene(30), new Gene(40), new Gene(50), new Gene(60), new Gene(70)});
		System.out.println();
		System.out.println("Chromossome 1: " + c1);
		System.out.println("Changed chromossome 2: " + c2);
		System.out.println("Compatibility: " + c1.indentityPercentage(c2));
		
		c1.merge(c2, 3);
		System.out.println();
		System.out.println("CROSSING OF ALLELE 3 GENES ONWARDS");
		System.out.println("Transgenic chromossome 1: " + c1);
		System.out.println("Transgenic chromossome 2: " + c2);
	}
	
}
