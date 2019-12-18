package model.entities;

import java.util.ArrayList;
import java.util.List;

public class AllMusicDatabase {

	private List<Music> allMusics = new ArrayList<>();

	public AllMusicDatabase(Music music) {
		allMusics.add(music);
	}

	public void addMusic(Music music) {
		allMusics.add(music);
	}

	public List<Music> getMusics() {
		return allMusics;
	}

	public Playlist makeSimilarPlaylist(Playlist playlist, long secondsOfDuration, String name) {

		Playlist similarPlaylist = new Playlist();
		similarPlaylist.setName(name);

		for (int i = 3; i >= 0; i--) {
			for (Music m : playlist.getMusics()) {
				for (Music n : getMusics()) {
					if (similarPlaylist.getSecondsOfDuration() <= secondsOfDuration) {
						if (!playlist.getMusics().contains(n) && !similarPlaylist.getMusics().contains(n)) {
							if (m.similarity(n) > i) {
								similarPlaylist.addMusic(n);
							}
						}
					}
				}
			}
		}

		return similarPlaylist;
	}

}
