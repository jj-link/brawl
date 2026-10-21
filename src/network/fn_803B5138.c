#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u32 position;
    s32 handle;
    unsigned char pad[0x3C];
    u32 offset;
    u16 length;
    u16 pad4A;
    unsigned char data[0x20];
} State;

extern s32 fn_803B3C2C(State *, s32);
extern s32 fn_803C0080(s32, void *, u32, u16, u32, u32 *, s32);

static inline s32 do_work(State *arg0, s32 arg1)
{
    u32 count;
    u32 old;
    u32 next;
    s32 result;
    s32 status;

    old = arg0->position;
    next = old + 1;
    if (old != next || arg0->offset != 0xFFFFFFFFU || arg1 == 0) {
        arg0->position = next;
        result = fn_803B3C2C(arg0, arg1);
        if (result != 0) {
            arg0->position = old;
            fn_803B3C2C(arg0, 0);
        } else {
            if (arg0->offset == 0xFFFFFFFFU) {
                status = 0x10;
            } else {
                s32 temp = fn_803C0080(arg0->handle, arg0->data,
                                      arg0->offset, arg0->length,
                                      0x20, &count, 0);
                status = 0x11;
                if (count == 0x20)
                    status = temp;
            }
            result = status != 0 ? status : 0;
        }
        if (result != 0)
            return result;
    }
    return 0;
}

s32 fn_803B5138(State *arg0, s32 arg1)
{
    return do_work(arg0, arg1);
}
