package model.entities.impl;

import model.entities.Pixel;

public class PixelCMYK implements Pixel{
	
	private Double cyan;
	private Double magenta;
	private Double yellow;
	private Double key;
	
	public PixelCMYK() {
	}

	public PixelCMYK(Double cyan, Double magenta, Double yellow, Double key) {
		this.cyan = cyan;
		this.magenta = magenta;
		this.yellow = yellow;
		this.key = key;
	}

	public Double getCyan() {
		return cyan;
	}

	public void setCyan(Double cyan) {
		this.cyan = cyan;
	}

	public Double getMagenta() {
		return magenta;
	}

	public void setMagenta(Double magenta) {
		this.magenta = magenta;
	}

	public Double getYellow() {
		return yellow;
	}

	public void setYellow(Double yellow) {
		this.yellow = yellow;
	}

	public Double getKey() {
		return key;
	}

	public void setKey(Double key) {
		this.key = key;
	}

	@Override
	public Double bright() {
		return key;
	}
}
