#include <types.h>
#pragma force_active on

extern s32 fn_803A98A8(u8*, s32);
extern char lbl_8053B248[];

typedef struct {
    u16* data;
    u32 unk4;
    u32 unk8;
    u32 mode;
} Arg;

typedef void (*FnT)(s32, u16*);

s32 fn_803A9D54(const Arg* arg0, s32 arg1) {
    u16 value;
    u16 out;
    u16* cursor;

    if (arg0->mode == 1U) {
        return fn_803A98A8((u8*)arg0->data, arg1);
    }

    cursor = arg0->data;
    for (;;) {
        (*(FnT*)(lbl_8053B248 + 0x24))(arg1, &out);
        value = *cursor;
        arg1++;
        cursor++;
        if (value != out) {
            break;
        }
        if (cursor[-1] == 0) {
            break;
        }
        if (out == 0) {
            break;
        }
    }

    return cursor[-1] - out;
}
