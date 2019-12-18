package application;

import model.entities.AllMusicDatabase;
import model.entities.Music;
import model.entities.Playlist;
import model.enums.Harmony;

public class Program {
	
	public static void main (String[] args){
		
		Music m1 = new Music("Fear of the dark", 300, "Rock", "Sony", Harmony.C, new String[] {"Bruce Dickinson", "Iron Maiden"});
		Music m2 = new Music("Tears of the dragon", 380, "Rock", "Sony", Harmony.C, new String[] {"Bruce Dickinson"});
		Music m3 =  new Music("The unforgiven", 410, "Rock", "Universal", Harmony.D, new String[] {"Metallica"});
		Music m4 = new Music("Symphony of destruction", 390, "Rock", "Universal", Harmony.C, new String[] {"Megadeath"});
		Music m5 = new Music("Hells Bells", 370, "Rock", "Sony", Harmony.C, new String[] {"AC/DC"});
		
		AllMusicDatabase db = new AllMusicDatabase(m1);
		db.addMusic(m2);
		db.addMusic(m3);
		db.addMusic(m4);
		db.addMusic(m5);
		
		Playlist pl = new Playlist("Original playlist", m1);
		Playlist newPlaylist = db.makeSimilarPlaylist(pl, 900, "Similar playlist");
		
		System.out.println(pl.getName() + ":");
		for(Music m : pl.getMusics()) {
			System.out.println(m);
		}
		System.out.println("Seconds of playlist duration: " + pl.getSecondsOfDuration());
		
		System.out.println();
		System.out.println(newPlaylist.getName() + ":");
		for(Music m : newPlaylist.getMusics()) {
			System.out.println(m);
		}
		System.out.println("Seconds of playlist duration: " + newPlaylist.getSecondsOfDuration());
	}

}
