#pragma force_active on
typedef int s32;
typedef unsigned char u8;

typedef struct Buffer {
    char *data;
    s32 capacity;
    s32 used;
} Buffer;

extern s32 fn_8035A590(s32);
extern s32 fn_8036A24C(s32, Buffer *, u8 *, s32);
extern s32 fn_8036A3E4(s32, s32, u8 *, s32, s32 *, s32 *, char *);
extern char lbl_8059F69C;

s32 fn_8036A594(s32 arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    s32 result;
    s32 consumed;
    s32 total;
    s32 remaining;
    s32 err;

    remaining = arg3;
    total = 0;
    if (arg3 == 0) {
        return 0;
    }
    if (*(s32 *)(arg1 + 0x34) - *(s32 *)(arg1 + 0x38) == 0 &&
        fn_8035A590(*(s32 *)(arg1 + 0x3C)) == 0) {
        do {
            err = fn_8036A3E4(arg0, *(s32 *)(arg1 + 0x8), arg2 + total, remaining,
                              &result, &consumed, &lbl_8059F69C);
            if (err != 0) {
                return err;
            }
            if (consumed != 0) {
                total += consumed;
                remaining -= consumed;
            }
        } while (consumed != 0 && remaining != 0);
    }
    if (remaining != 0) {
        err = fn_8036A24C(arg0, (Buffer *)(arg1 + 0x2C), arg2 + total, remaining);
        if (err != 0) {
            return err;
        }
    }
    return 0;
}
