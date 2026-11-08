#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef struct {
    unsigned char buf[0x40];
    u32 offset;
    s32 enabled;
    s32 locked;
    s32 sync;
} SramCB;
extern SramCB lbl_804DD500;
extern s32 fn_801E42E4(s32, void *, s32, s32, s32);
extern s32 fn_801E4560(s32, void *, s32, s32);
extern s32 fn_801E46FC(s32);
extern s32 fn_801E4D4C(s32, s32, s32);
extern s32 fn_801E4E7C(s32);
extern s32 fn_801E54E0(s32, s32, void (*)(void));
extern void fn_801E55DC(s32);

void fn_801DF848(void) {
    u32 offset = lbl_804DD500.offset;
    void *buffer;
    u32 size;
    u32 cmd;
    s32 err;
    s32 err2;
    s32 result;
    size = 0x40 - offset;
    buffer = lbl_804DD500.buf + offset;
    if (fn_801E54E0(0, 1, fn_801DF848) == 0) {
        result = 0;
    } else if (fn_801E4D4C(0, 1, 3) == 0) {
        fn_801E55DC(0);
        result = 0;
    } else {
        cmd = ((offset << 6) + 0x100) | 0xA0000000;
        err = fn_801E42E4(0, &cmd, 4, 1, 0) == 0;
        err2 = err | (fn_801E46FC(0) == 0);
        err2 |= fn_801E4560(0, buffer, size, 1) == 0;
        err2 |= fn_801E4E7C(0) == 0;
        fn_801E55DC(0);
        result = !err2;
    }
    lbl_804DD500.sync = result;
    if (result) lbl_804DD500.offset = 0x40;
}