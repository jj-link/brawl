typedef unsigned long u32;
typedef unsigned char u8;

struct FILE {
    u32 x0, x4, x8, xc, x10, x14, x18, x1c, x20, x24, x28, x2c, x30, x34, x38, x3c;
    u32 x40, x44, x48;
};

static inline void __prep_buffer(struct FILE* file) {
    unsigned long size = file->x20;
    file->x24 = file->x1c;
    file->x28 = size - (file->x18 & file->x2c);
    file->x34 = file->x18;
}

int fn_803F5098(struct FILE* file, int* written, int mode);

int fn_803F5098(struct FILE* file, int* written, int mode) {
    int r3;
    u32 i;
    u8* p;
    __prep_buffer(file);
    if (mode == 1) {
        file->x28 = file->x20;
    }
    r3 = ((int (*)(u32, u32, u32*, u32))file->x3c)(file->x0, file->x1c, &file->x28, file->x48);
    if (r3 == 2) {
        file->x28 = 0;
    }
    if (written != 0) {
        *written = file->x28;
    }
    if (r3 != 0) {
        return r3;
    }
    file->x18 = file->x18 + file->x28;
    if (((file->x4 >> 19) & 1) == 0) {
        p = (u8*)file->x1c;
        for (i = file->x28; i != 0; i--) {
            u8 c = *p;
            p = p + 1;
            if (c == 0xa) {
                file->x18 = file->x18 + 1;
            }
        }
    }
    return 0;
}
