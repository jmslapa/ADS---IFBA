package model.entities.impl;

import model.entities.Pixel;

public class PixelRGB implements Pixel{
	
	private Double red;
	private Double green;
	private Double blue;
	
	public PixelRGB() {
	}
	
	public PixelRGB(Double red, Double green, Double blue) {
		this.red = red;
		this.green = green;
		this.blue = blue;
	}

	public Double getRed() {
		return red;
	}

	public void setRed(Double red) {
		this.red = red;
	}

	public Double getGreen() {
		return green;
	}

	public void setGreen(Double green) {
		this.green = green;
	}

	public Double getBlue() {
		return blue;
	}

	public void setBlue(Double blue) {
		this.blue = blue;
	}

	@Override
	public Double bright() {
		return (red*0.3 + green*0.59 + blue*0.11)/255;
	}
}
