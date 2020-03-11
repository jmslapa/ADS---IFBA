package model.entities;

public class Fragmento {
	
	private Pixel[][] pixels;
	
	public Fragmento() {
	}

	public Fragmento(Pixel[][] pixels) {
		super();
		this.pixels = pixels;
	}

	public Pixel[][] getPixels() {
		return pixels;
	}

	public void setPixels(Pixel[][] pixels) {
		this.pixels = pixels;
	}	
}
