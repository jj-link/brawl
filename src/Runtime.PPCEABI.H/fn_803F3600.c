typedef unsigned long u32;

struct FILE {
    u32 x0, x4, x8;
    u32 words[16];
    struct FILE* next;
};

extern struct FILE __files[];
extern int fn_803F5954(struct FILE*);

int fn_803F3600(void) {
    int result = 0;
    struct FILE* file = __files;
    while (file != 0) {
        u32 flags = file->x4;
        if (((flags >> 22) & 7) != 0 && ((flags >> 25) & 1) != 0 &&
            (file->x8 >> 29) == 1 && fn_803F5954(file) != 0) {
            result = -1;
        }
        file = file->next;
    }
    return result;
}
