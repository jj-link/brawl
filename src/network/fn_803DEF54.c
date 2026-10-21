#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;

typedef struct {
    u32 position;
    s32 handle;
    unsigned char pad[0x3C];
    u32 sector;
    u16 offset;
    unsigned char pad4A[2];
    unsigned char data[0x20];
} State;

extern s32 fn_803DDF18();
extern s32 PFSEC_ReadData(s32, void *, u32, u16, u32, u32 *, s32);

static inline s32 advance(State *p, s32 arg1)
{
    u32 count;
    u32 old;
    s32 result;
    s32 error;
    s32 status;
    u32 next;

    old = p->position;
    next = old + 1;
    if (old != next || p->sector != 0xFFFFFFFFU || arg1 == 0) {
        p->position = next;
        result = fn_803DDF18(p);
        if (result != 0) {
            p->position = old;
            fn_803DDF18(p, 0);
        } else {
            if (p->sector == 0xFFFFFFFFU) {
                error = 0x10;
            } else {
                status = PFSEC_ReadData(p->handle, p->data, p->sector,
                                        p->offset, 0x20, &count, 0);
                error = 0x11;
                if (count == 0x20U) {
                    error = status;
                }
            }
            result = error & ((-error | error) >> 31);
        }
        if (result != 0) {
            return result;
        }
    }
    return 0;
}

s32 fn_803DEF54(State *p, s32 arg1)
{
    return advance(p, arg1);
}
