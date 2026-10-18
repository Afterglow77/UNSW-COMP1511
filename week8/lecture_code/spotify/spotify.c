// spotify.c
// Sofia De Bellis
// Implmentation file for spotify

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spotify.h"

struct spotify *initialise_spotify(void) {
    printf("initialise_spotify not implemented yet\n");
    return NULL;
}

void add_playlist(char *name, struct spotify *spotify) {
    printf("create_playlist not implemented yet\n");
    return;
}

struct song *create_song(char *name, enum genre genre, char *artist, int duration) {
    printf("create_song not implemented yet\n");
    return NULL;
}

void add_song(char *playlist_name, char *name, enum genre genre, char *artist, int duration) {
    printf("add_song not implemented yet\n");
    return;
}

void print_spotify(struct spotify *spotify) {
    printf("print_spotify not implemented yet\n");
    return;
}

void remove_song(struct spotify *spotify, char *playlist_name, char *name) {
    printf("remove_song not implemented yet\n");
}

void delete_playlist(struct playlist *playlist) {
    printf("delete_playlist not implemented yet\n");
}

void delete_spotify(struct spotify *spotify) {
    printf("delete_spotify not implemented yet\n");
}

void print_songs_of_genre(struct spotify *spotify, enum genre genre) {
    printf("print_songs_of_genre not implemented yet\n");
}

void merge_playlists(struct spotify *spotify, char *playlist1_name, char *playlist2_name) {
    printf("merge_playlists not implemented yet\n");
}

// Provided helper functions

void print_song(struct song *song) {
    printf("   🎵 \"%s\" by %s | %s | %d:%02d\n",
           song->name,
           song->artist,
           genre_to_string(song->genre),
           song->duration / 60,
           song->duration % 60);
    return;
}

char *genre_to_string(enum genre genre) {
    if (genre == POP) {
        return "Pop";
    } else if (genre == KPOP) {
        return "K-Pop";
    } else if (genre == HIPHOP) {
        return "Hip-Hop";
    }
    else {
        return "Indie";
    }
}

void print_playlist_duration(int total_duration) {
    printf("Total duration: %d:%02d\n", total_duration / 60, total_duration % 60);
    return;
}
