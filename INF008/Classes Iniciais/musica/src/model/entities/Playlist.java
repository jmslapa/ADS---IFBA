package model.entities;

import java.util.ArrayList;
import java.util.List;

public class Playlist {
	
	private String name;
	private long secondsOfDuration;
	private List<Music> list = new ArrayList<>();
	
	public Playlist() {
	}
	
	public Playlist(String name, Music music) {
		this.name = name;
		list.add(music);
		secondsOfDuration = music.getSecondsOfDuration();
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public long getSecondsOfDuration() {
		return secondsOfDuration;
	}
	
	public List<Music> getMusics(){
		return list;
	}
	
	public void addMusic(Music music) {
		list.add(music);
		secondsOfDuration += secondsOfDuration;
	}
}
