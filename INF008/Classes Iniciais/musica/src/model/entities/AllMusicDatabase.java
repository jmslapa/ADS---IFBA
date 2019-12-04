package model.entities;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class AllMusicDatabase {
	
	private static List<Music> allMusics = new ArrayList<>();

	public AllMusicDatabase(List<Music> allMusics) {
		this.allMusics = allMusics;
	}
	
	public static List<Music> getMusics(){
		return allMusics;
	}
	
	public static List<Music> makeSimilarPlaylist(Playlist playlist, Date duration) {
		
		List<Music> similarPlaylist = new ArrayList<>();
		
		for(Music m : playlist.getMusics()) {
			for
		}
		
		return similarPlaylist;
	}
	

}
