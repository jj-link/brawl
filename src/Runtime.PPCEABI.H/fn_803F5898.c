// Runtime.PPCEABI.H/fn_803F5898.c
// MSL fclose: flush, close handle, release owned buffer.

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
    u32 xC, x10, x14, x18, x1c, x20, x24, x28, x2c, x30, x34, x38;
    u32 x3c, x40, x44, x48;
};

extern int fn_803F5954(struct FILE*);
extern void fn_803F342C(void*);

int fn_803F5898(struct FILE* file) {
    int flush_result;
    int close_result;
    int result;

    if (file == 0) {
        return -1;
    }
    if (file->w4.f4.mode == 0) {
        return 0;
    }
    flush_result = fn_803F5954(file);
    close_result = ((int (*)(u32))file->x44)(file->x0);
    file->x0 = 0;
    file->w4.f4.mode = 0;
    if (((file->w8.x8 >> 28) & 1) != 0) {
        fn_803F342C((void*)file->x1c);
    }
    result = 0;
    if (flush_result != 0 || close_result != 0) {
        result = 1;
    }
    return -result;
}
