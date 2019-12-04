package model.entities;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Playlist {
	
	private String name;
	private Date duration;
	private List<Music> list = new ArrayList<>();
	
	public Playlist(String name, Music music) {
		this.name = name;
		list.add(music);
	}
	
	public String getName() {
		return name;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public Date getDuration() {
		SimpleDateFormat sdf = new SimpleDateFormat("mm:ss");
		for()
	}
	
	public List<Music> getMusics(){
		return list;
	}
	
	public void addMusic(Music music) {
		list.add(music);
	}
}
