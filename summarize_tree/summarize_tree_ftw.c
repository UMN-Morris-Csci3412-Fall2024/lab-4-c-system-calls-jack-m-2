#include <ftw.h>
#include <stdio.h>

static int num_dirs, num_regular;

// Callback function for ftw() to process each file and directory
static int callback(const char *fpath, const struct stat *sb, int typeflag) {
    // Check if the current path is a directory
    if (typeflag == FTW_D) {
        num_dirs++;
    } 
    // Check if the current path is a regular file
    else if (typeflag == FTW_F) {
        num_regular++;
    }
    return 0;
}

#define MAX_FTW_DEPTH 16

int main(int argc, char** argv) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        printf("       where <path> is the file or root of the tree you want to summarize.\n");
        return 1;
    }

    // Initialize the counters
    num_dirs = 0;
    num_regular = 0;

    // Call ftw() to traverse the directory tree starting from the provided path
    ftw(argv[1], callback, MAX_FTW_DEPTH);

    // Print the results
    printf("There were %d directories.\n", num_dirs);
    printf("There were %d regular files.\n", num_regular);

    return 0;
}