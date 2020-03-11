package model.entities.impl;

import model.entities.Mapa;
import model.entities.Pixel;

public class MapaCMYK implements Mapa{
	
	private PixelCMYK[][] pixels;
	
	public MapaCMYK() {
	}
	
	public MapaCMYK(PixelCMYK[][] pixels) {
		this.pixels = pixels;
	}
	
	@Override
	public Pixel[][] getPixels() {
		return pixels;
	}
	
	@Override
	public Integer getRows() {
		return pixels.length;
	}

	@Override
	public Integer getColumns() {
		if(getRows() > 0)
			return pixels[1].length;
		return 0;
	}
}
