// Runtime.PPCEABI.H/fn_803F5954.c
// MSL per-stream flush helper.

typedef unsigned long u32;
typedef unsigned char u8;

struct FILE {
    u32 x0;
    union {
        u32 x4;
        struct {
            u32 :2;
            u32 f2 : 3;
            u32 :2;
            u32 mode : 3;
            u32 :22;
        } f4;
    } w4;
    union {
        u32 x8;
        u8 x8b[4];
        struct {
            u32 io : 3;
            u32 buf : 1;
            u32 :27;
        } f8;
    } w8;
    u32 xC, x10, x14, x18, x1c, x20, x24, x28, x2c, x30, x34, x38, x3c;
    u32 x40, x44, x48;
    struct FILE* next;
};

extern int fn_803F3684(void);
extern u32 fn_803F5CE0(struct FILE*);
extern int __flush_buffer(struct FILE*, int);

int fn_803F5954(struct FILE* file) {
    u32 saved_pos;
    int flush_result;

    if (file == 0) {
        return fn_803F3684();
    }
    if (file->w8.x8b[2] != 0 || file->w4.f4.mode == 0) {
        return -1;
    }
    if (file->w4.f4.f2 == 1) {
        return 0;
    }
    if (file->w8.f8.io >= 3) {
        file->w8.f8.io = 2;
    }
    if (file->w8.f8.io == 2) {
        file->x28 = 0;
    }
    if (file->w8.f8.io != 1) {
        file->w8.f8.io = 0;
        return 0;
    }
    if (file->w4.f4.mode != 1) {
        saved_pos = 0;
    } else {
        saved_pos = fn_803F5CE0(file);
    }
    flush_result = __flush_buffer(file, 0);
    if (flush_result != 0) {
        file->w8.x8b[2] = 1;
        file->x28 = 0;
        return -1;
    }
    file->x18 = saved_pos;
    file->w8.f8.io = 0;
    file->x28 = 0;
    return 0;
}
