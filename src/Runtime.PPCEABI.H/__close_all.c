typedef unsigned long u32;
typedef unsigned char u8;

struct FILE {
    u32 x0;
    union {
        u32 x4;
        struct {
            u32 unused0 : 7;
            u32 mode : 3;
            u32 unused1 : 22;
        } bits;
    } flags;
    u32 x8;
    u8 xC, xD, xE, xF;
    u32 x10, x14, x18, x1c, x20, x24, x28, x2c, x30, x34, x38, x3c;
    u32 x40, x44, x48;
    struct FILE* next;
};
extern struct FILE __files[];
extern int fn_803F5898(struct FILE*);
extern void fn_803F342C(struct FILE*);

void __close_all(void) {
    struct FILE* file = __files;
    u32 mode = 3;
    struct FILE* null_file = 0;
    while (file != 0) {
        if (((file->flags.x4 >> 22) & 7) != 0) {
            fn_803F5898(file);
        }
        {
            struct FILE* current = file;
            file = file->next;
            if (current->xC != 0) {
                fn_803F342C(current);
            } else {
                current->flags.bits.mode = mode;
                if (file != 0 && file->xC != 0) {
                    current->next = null_file;
                }
            }
        }
    }
}
