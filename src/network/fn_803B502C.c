#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    u32 position;
    s32 handle;
    u8 pad[0x38];
    s32 field40;
    u32 offset;
    u16 length;
    u8 pad4A[2];
    u8 data[0x20];
    u8 pad6C;
} State;

extern s32 fn_803B3C2C(State *, s32);
extern s32 fn_803C0080(s32, void *, u32, u16, u32, u32 *, s32);

s32 fn_803B502C(State *p)
{
    u32 count;
    s32 old2;
    u32 old;
    s32 result;
    s32 error;
    s32 status;

    if (p->offset == 0xFFFFFFFFU || p->data[0] == 0 || p->position >= 999999) {
        old2 = p->field40;
        old = p->position;
        p->position = (old2 + 1) << p->pad6C;
        result = fn_803B3C2C(p, 0);
        if (result != 0) {
            p->position = old;
            p->field40 = old2;
            return 1;
        }
        if (p->offset != 0xFFFFFFFFU) {
            if (p->offset == 0xFFFFFFFFU) {
                error = 0x10;
            } else {
                status = fn_803C0080(p->handle, p->data, p->offset, p->length, 0x20, &count, 0);
                error = 0x11;
                if (count == 0x20U) {
                    error = status;
                }
            }
            return error != 0;
        }
        return 1;
    }
    return 0;
}