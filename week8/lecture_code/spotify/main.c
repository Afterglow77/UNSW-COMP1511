// main.c
// Sofia De Bellis
// Simple Spotify 

#include <stdio.h>
#include "spotify.h"

int main(void) {
    // Initialize the spotify system
    struct spotify *spotify = initialise_spotify();

    // Create multiple playlists and add them to spotify
    add_playlist("COMP(1511|1911)'s Favourites", spotify);
    add_playlist("K-Pop Hits", spotify);
    add_playlist("Chill Vibes", spotify);

    // // Add songs to the favourites playlist
    add_song("COMP(1511|1911)'s Favourites", "Touch", KPOP, "Katseye", 129);
    add_song("COMP(1511|1911)'s Favourites", "Ms Jackon", HIPHOP, "Outkast", 299);
    add_song("COMP(1511|1911)'s Favourites", "Love Story", POP, "Taylor Swift", 230);
    add_song("COMP(1511|1911)'s Favourites", "Golden", KPOP, "HUNTR/X", 180);

    // Add songs to the K-Pop playlist
    add_song("K-Pop Hits", "Dynamite", KPOP, "BTS", 199);
    add_song("K-Pop Hits", "Pink Venom", KPOP, "BLACKPINK", 195);
    add_song("K-Pop Hits", "Touch", KPOP, "Katseye", 129);

    // Add songs to the chill playlist
    add_song("Chill Vibes", "Kyoto", INDIE, "Phoebe Bridgers", 242);
    add_song("Chill Vibes", "Good Days", HIPHOP, "SZA", 260);

    print_spotify(spotify);

    // // Remove songs from the favourites playlist
    remove_song(spotify, "COMP(1511|1911)'s Favourites", "Touch");
    remove_song(spotify, "COMP(1511|1911)'s Favourites", "Good Days");

    print_spotify(spotify);

    print_songs_of_genre(spotify, KPOP);

    merge_playlists(spotify, "COMP(1511|1911)'s Favourites", "K-Pop Hits");

    print_spotify(spotify);

    delete_spotify(spotify);

    return 0;
}
