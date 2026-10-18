// spotify.c
// Sofia De Bellis
// Implmentation file for spotify 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spotify.h"

struct spotify *initialise_spotify(void) {
    struct spotify *new_spotify = malloc(sizeof(struct spotify));
    new_spotify->playlists = NULL;
    return new_spotify;
}

void add_playlist(char *name, struct spotify *spotify) {
    // 1. create new the new playlist, with malloc
    struct playlist *new_playlist = malloc(sizeof(struct playlist));
    strcpy(new_playlist->name, name);
    new_playlist->num_songs = 0;
    new_playlist->songs = NULL;
    new_playlist->next = NULL;

    // 2. insert when no playlists in spotify
    if (spotify->playlists == NULL) {
        spotify->playlists = new_playlist;
        return;
    }

    // 3. insert when there are existing playlists in spotify
    new_playlist->next = spotify->playlists;
    spotify->playlists = new_playlist;
    return;
}

struct song *create_song(char *name, enum genre genre, char *artist, int duration) {
    struct song *new_song = malloc(sizeof(struct song));

    strcpy(new_song->name, name);
    strcpy(new_song->artist, artist);
    new_song->genre = genre;
    new_song->duration = duration;
    new_song->next = NULL;

    return new_song;
}

void add_song(char *playlist_name, char *name, enum genre genre, char *artist, int duration, struct spotify *spotify) {
    struct song *new_song = create_song(name, genre, artist, duration);
    struct playlist *playlist = find_playlist(playlist_name, spotify);

    // if list empty
    if (playlist->songs == NULL) {
        playlist->songs = new_song;
        printf("%s added to %s!\n", new_song->name, playlist->name);
        return;
    }

    // traversing to find the last node in the list
    struct song *current_song = playlist->songs;
    while (current_song->next != NULL) {
        current_song = current_song->next;
    }

    // inserting the new node
    current_song->next = new_song;
    printf("%s added to %s!\n", new_song->name, playlist->name);
    return;
}

struct playlist *find_playlist(char *playlist_name, struct spotify *spotify) {
    struct playlist *current = spotify->playlists;

    while (current != NULL) {
        if (strcmp(current->name, playlist_name) == 0) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void print_spotify(struct spotify *spotify) {
    struct playlist *current_playlist = spotify->playlists;

    printf("\n PRINTING SPOTIFY\n");
    while (current_playlist != NULL) {
        printf("🎧 %s 🎧\n", current_playlist->name);

        struct song *current_song = current_playlist->songs;
        while (current_song != NULL) {
            print_song(current_song);
            current_song = current_song->next;
        }

        current_playlist = current_playlist->next;
    }

    return;
}

void remove_song(struct spotify *spotify, char *playlist_name, char *name) {
    struct playlist *playlist = find_playlist(playlist_name, spotify);
        
    struct song *curr_song = playlist->songs;

    // BUG: This only checks and removes the head if it's the only node.
    // If the head matches and there are more nodes, it doesn't handle it.
    // Instead, it should check the head separately regardless of list length.
    // if (strcmp(curr_song->name, name) == 0) {
    //     printf("%s removed from %s!\n", curr_song->name, playlist->name);
    //     free(curr_song);
    //     // BUG: This sets songs to NULL even if more nodes follow.
    //     playlist->songs = NULL; 
    //     return;
    // }


    // Handle head separately
    if (curr_song != NULL && strcmp(curr_song->name, name) == 0) {
        playlist->songs = curr_song->next;
        printf("%s removed from %s!\n", curr_song->name, playlist->name);
        free(curr_song);
        return;
    }

    // If the node we want to remove is anywhere in the list
    while (curr_song != NULL && curr_song->next != NULL) {
        if (strcmp(curr_song->next->name, name) == 0) {
            struct song *to_delete = curr_song->next;
            curr_song->next = to_delete->next;
            printf("%s removed from %s!\n", to_delete->name, playlist->name);
            free(to_delete);
            return;
        }
        curr_song = curr_song->next;
    }

    return;
}

// Not implmeented in lecture - added later
void remove_playlist(struct spotify *spotify, char *playlist_name) {
    struct playlist *playlist = find_playlist(playlist_name, spotify);

    struct song *current_song = playlist->songs;

    while(current_song != NULL) {
        struct song *to_remove = current_song;
        current_song = current_song->next;
        remove_song(spotify, playlist_name, to_remove->name);
    }

    struct playlist *current_playlist = spotify->playlists;
    if (strcmp(current_playlist->name, playlist_name) == 0) {
        struct playlist *to_delete = spotify->playlists;
        spotify->playlists = to_delete->next;
        free(to_delete);
    }

    while(current_playlist->next != NULL) {
        if (strcmp(current_playlist->next->name, playlist_name) == 0) {
            struct playlist *to_delete = current_playlist->next;
            current_playlist->next = to_delete->next;
            printf("Removed %s from Spotify!\n", playlist_name);
            free(to_delete);
            return;
        }
        current_playlist = current_playlist->next;
    }

}

// Not implmeented in lecture - added later
void delete_spotify(struct spotify *spotify) {
    struct playlist *current_playlist = spotify->playlists;

    while(current_playlist != NULL) {
        struct song *current_song = current_playlist->songs;

        while (current_song != NULL) {
            struct song *song_to_remove = current_song;
            current_song = current_song->next;
            free(song_to_remove);
        }

        struct playlist *playlist_to_remove  = current_playlist;
        current_playlist = current_playlist->next;
        free(playlist_to_remove);
    }

    free(spotify);
}


// Not implmeented in lecture - added later
void print_songs_of_genre(struct spotify *spotify, enum genre genre) {
    struct playlist *current_playlist = spotify->playlists;

    printf("🎼 Songs saved of genre %s\n", genre_to_string(genre));

    int num_found = 0;
    while (current_playlist != NULL) {
        struct song *current_song = current_playlist->songs;

        while (current_song != NULL) {
            if (current_song->genre == genre) {
                printf("%s found in %s\n", current_song->name, current_playlist->name);
                num_found++;
            }
            current_song = current_song->next;
        }

        current_playlist = current_playlist->next;
    }

    if (num_found == 0) {
        printf("No songs of genre %s found in any playlists!\n", genre_to_string(genre));
    }
}

// Not implmeented in lecture - added later
void merge_playlists(struct spotify *spotify, char *playlist1_name, char *playlist2_name) {
    struct playlist *playlist1 = find_playlist(playlist1_name, spotify);
    struct playlist *playlist2 = find_playlist(playlist2_name, spotify);

    struct song *curr1 = playlist1->songs;

    if (curr1 == NULL) {
        playlist1->songs = playlist2->songs;
        playlist2->songs = NULL;
        remove_playlist(spotify, playlist2->name);
        return;
    }

    while (curr1->next != NULL) {
        curr1 = curr1->next;
    }

    curr1->next = playlist2->songs;
    playlist2->songs = NULL;
    remove_playlist(spotify, playlist2->name);
    return;
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
