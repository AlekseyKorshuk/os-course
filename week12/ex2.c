#include <linux/input.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    char* dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int fd = open(dev, O_RDONLY);
    FILE *f = fopen("ex2.txt", "w+");
    if (fd < 0) {
        perror("error");
        return 1;
    }
    struct input_event evt;
    // Remove Enter while starting the program
    read(fd, &evt, sizeof(struct input_event));
    read(fd, &evt, sizeof(struct input_event));

    printf("Press Q to exit!\n");
    while(1) {
        read(fd, &evt, sizeof(struct input_event));
        if(evt.type != 4 && evt.code != EV_SYN) {
            if (evt.value == 1){
                fprintf(f, "PRESSED 0x%.4x (%d)\n", evt.code, evt.code);
                fprintf(stderr, "PRESSED 0x%.4x (%d)\n", evt.code, evt.code);
            }
            if (evt.value == 0){
                fprintf(f, "RELEASED 0x%.4x (%d)\n", evt.code, evt.code);
                fprintf(stderr, "RELEASED 0x%.4x (%d)\n", evt.code, evt.code);
            }
            if (evt.code == 16)
                return 0;
        }
    }
    return 0;
}