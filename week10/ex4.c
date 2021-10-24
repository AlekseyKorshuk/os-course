#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define MIN_NUMBER_OF_HARDLINKS 2
#define SHOW_ONCE 0
#define FOLDER "./tmp"

void get_links(const char *path, const ino_t inode_number[], int index) {
    struct stat stats_new;
    struct dirent *ent_new;
    char buf_new[1024];
    DIR *dir_2 = opendir(path);
    while ((ent_new = readdir(dir_2)) != NULL) {
        snprintf(buf_new, sizeof(buf_new), "%s/%s", path, ent_new->d_name);
        stat(buf_new, &stats_new);
        if (inode_number[index] == stats_new.st_ino) {
            printf("%s ", ent_new->d_name);
        }
    }
    closedir(dir_2);
    printf("\n");
}


int check_once(const ino_t inode_number[], struct stat stats) {

    int flag = 0;
    for (int i = 0; i < 10; i++) {
        if (inode_number[i] == stats.st_ino) {
            flag = 1;
            break;
        }
    }
    if (flag)
        return 1;
    return 0;
}


int main() {
    const char *path = FOLDER;
    DIR *dir = opendir(path);

    struct dirent *ent;
    struct stat stats;
    char buf[1024];
    ino_t inode_number[10] = {0};
    int index = 0;
    while ((ent = readdir(dir)) != NULL) {
        snprintf(buf, sizeof(buf), "%s/%s", path, ent->d_name);
        if (stat(buf, &stats) < 0) {
            perror("stats");
            continue;
        }

        if (SHOW_ONCE == 1) {
            if (check_once(inode_number, stats) == 1)
                continue;
        }

        if (!S_ISREG(stats.st_mode))
            continue;
        if (stats.st_nlink >= MIN_NUMBER_OF_HARDLINKS) {
            inode_number[index] = stats.st_ino;
            printf("%s(%lu) -> ", ent->d_name, inode_number[index]);
        } else { continue; }

        get_links(path, inode_number, index);

        index++;
    }
    closedir(dir);

    return 0;
}