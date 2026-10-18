// spotify.h
// Sofia De Bellis
// Header file for spotify

/////////////////////////////////////////////
// Constants
/////////////////////////////////////////////
#define MAX_LEN 100

/////////////////////////////////////////////
// Enums
/////////////////////////////////////////////
enum genre {
    POP,
    KPOP,
    HIPHOP,
    INDIE
};

/////////////////////////////////////////////
// Structs
/////////////////////////////////////////////
struct spotify {
    // a pointer to the first playlist in spotify
    struct playlist *playlists;
};

struct playlist {
    // name of the playlist
    char name[MAX_LEN];
    // count of the number of songs in the playlist
    int num_songs;
    // a pointer to the first song in the playlist
    struct song *songs;
    // a pointer to the next playlist in the list
    struct playlist *next;
};

struct song {
    // name of the song
    char name[MAX_LEN];
    // genre of the song
    enum genre genre;
    // artist of the song
    char artist[MAX_LEN];
    // duration of the song (in seconds)
    int duration;
    // a pointer to the next song in the list
    struct song *next;
};

/////////////////////////////////////////////
// Provided function stubs
/////////////////////////////////////////////

// Creates and initializes a new spotify system
struct spotify *initialise_spotify(void);

// Creates a new playlist and adds it to spotify
void add_playlist(char *name, struct spotify *spotify);

// Creates a new song with the given details
// Returns a pointer to the newly created song
struct song *create_song(char *name, enum genre genre, char *artist, int duration);

// Adds a new song to the specified playlist
void add_song(char *playlist_name, char *name, enum genre genre, char *artist, int duration, struct spotify *spotify);

// Prints out the entire spotify system (all playlists)
void print_spotify(struct spotify *spotify);

// Removes a song from the specified playlist
void remove_song(struct spotify *spotify, char *playlist_name, char *name);

// Deletes the entire playlist and frees all allocated memory
void delete_playlist(struct playlist *playlist);

// Deletes the spotify system and frees all memory
void delete_spotify(struct spotify *spotify);

// Prints all songs of a specific genre from all playlists in spotify
void print_songs_of_genre(struct spotify *spotify, enum genre genre);

// Merges two playlists into one
void merge_playlists(struct spotify *spotify, char *playlist1_name, char *playlist2_name);

/////////////////////////////////////////////
// Additional function prototypes here
/////////////////////////////////////////////

// find a playlist in the spotify system
struct playlist *find_playlist(char *playlist_name, struct spotify *spotify);

/////////////////////////////////////////////
// Provided helper functions
/////////////////////////////////////////////

// Provided function
// Prints out the details of a specific song
// Usage:
//      `print_song(song);`
void print_song(struct song *song);

// Porvided function
// Converst genre enum to a string for printing
// Usgae:
//      `char *genre = genre_to_string(genre);`
char *genre_to_string(enum genre genre);

// Provided function
// Prints the total duration of the playlist in minutes and seconds
// Usage:
//      `print_playlist_duration(total_duration);`
void print_playlist_duration(int total_duration);
