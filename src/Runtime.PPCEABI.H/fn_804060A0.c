#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;
typedef signed int s32;

typedef struct RingBuffer {
    u8 *read;
    u8 *write;
    u8 *base;
    u32 capacity;
    u32 available;
    u32 free;
    s32 lock;
} RingBuffer;

extern s32 fn_8025FA94(void);
extern s32 fn_8025FB38(u8 *buffer, u32 size);
extern int fn_80406210(RingBuffer *self, u8 *dest, u32 size);
extern int fn_80406318(RingBuffer *self, const u8 *src, u32 size);
extern u32 fn_80406470(RingBuffer *self);
extern s32 lbl_805A1310;
extern RingBuffer lbl_8059C3E8;

u32 gdev_cc_read(u8 *dest, s32 arg1) {
    u8 buffer[0x500];
    u32 result = 0;
    s32 count;

    if (lbl_805A1310 == 0) {
        return -0x2711;
    }

    while (fn_80406470(&lbl_8059C3E8) < arg1) {
        result = 0;
        count = fn_8025FA94();
        if (count != 0) {
            result = fn_8025FB38(buffer, arg1);
            if (result == 0) {
                fn_80406318(&lbl_8059C3E8, buffer, count);
            }
        }
    }

    if (result == 0) {
        fn_80406210(&lbl_8059C3E8, dest, arg1);
    }
    return result;
}
