#include <types.h>
#pragma force_active on

extern s32 fn_803D64B8(u8*, u8*, int);
extern char lbl_805644C0[];

typedef struct {
    u8* first;
    u8* second;
    u8* third;
    u32 mode;
} Arg;
typedef void (*FnT)(s32, u16*);

s32 fn_803D6A50(Arg* arg0, s32 arg1, u32 arg2, s32 arg3, u16 arg4) {
    u16 out;
    u16 value;
    u16* cursor;
    u8* bytes;

    if (arg0->mode == 1U || arg2 == 3U) {
        if (arg2 == 1U) {
            bytes = arg0->first + arg3;
        } else if (arg2 == 2U) {
            bytes = arg0->second + arg3;
        } else {
            bytes = arg0->third + arg3;
        }
        return fn_803D64B8(bytes, (u8*)arg1, arg4);
    }
    if (arg2 == 1U) {
        cursor = (u16*)arg0->first + arg3;
    } else {
        cursor = (u16*)arg0->second + arg3;
    }
    for (;;) {
        (*(FnT*)(lbl_805644C0 + 0x48))(arg1, &out);
        value = *cursor;
        arg1++;
        arg4--;
        cursor++;
        if (value != out) break;
        if (arg4 == 0) break;
        if (cursor[-1] == 0) break;
        if (out == 0) break;
    }
    return cursor[-1] - out;
}
