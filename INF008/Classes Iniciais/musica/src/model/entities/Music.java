package model.entities;

import java.util.Arrays;

import model.enums.Harmony;

public class Music {
	
	private String title;
	private long secondsOfDuration;
	private String genre;
	private String recorder;
	private Harmony harmony;
	private String[] artists;	
	
	public Music(String title, int secondsOfDuration, String genre, String recorder, Harmony harmony, String[] artists) {
		this.title = title;
		this.secondsOfDuration = secondsOfDuration;
		this.genre = genre;
		this.recorder = recorder;
		this.harmony = harmony;
		this.artists = artists;
	}

	public String getTitle() {
		return title;
	}

	public void setTitle(String title) {
		this.title = title;
	}

	public long getSecondsOfDuration() {
		return secondsOfDuration;
	}

	public String getGenre() {
		return genre;
	}

	public String getRecorder() {
		return recorder;
	}

	public Harmony getHarmony() {
		return harmony;
	}

	public String[] getArtists(){
		return artists;
	}
	
	public boolean equals(Music other) {
		if(this == other) {
			return true;
		}
		if(this == null || other == null) {
			if(this != null || other != null) {
				return false;
			}
		}
		if(title == other.getTitle() && Arrays.equals(artists, other.artists)) {
			return true;
		}else {
			return false;
		}
	}
	
	public Double similarity(Music other) {
		double sim = 0.0;
		int count = 0;
		int max, min;
		
		if(artists.length > other.getArtists().length) {
			max = artists.length;
			min = other.getArtists().length;
		}else {
			max = other.getArtists().length;
			min = artists.length; 
		}			
		
		if(harmony == other.getHarmony()) {
			sim += 1.0;
		}
		if(recorder == other.getRecorder()) {
			sim += 1.0;
		}
		if(genre == other.getGenre()) {
			sim += 1.0;
		}
		for(int i = 0 ; i < min ; i++) {
			if(artists[i] == other.getArtists()[i]) {
				count++;
			}
		}
		double p = count / max;
		
		return sim + p;
	}

}
