package model.entities;

import java.util.ArrayList;
import java.util.List;

public class Atlas {
	
	private List<Mapa> mapas;
	
	public Atlas() {
	}
	
	public Atlas(Mapa mapa) {
		this.mapas = new ArrayList<Mapa>();
	}
	public List<Mapa> getMapas() {
		return mapas;
	}

	public void addMapa(Mapa mapa) {
		this.mapas.add(mapa);
	}	
}
	
	