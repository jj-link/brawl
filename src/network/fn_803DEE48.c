#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct State {
    u32 position;
    s32 handle;
    u8 pad[0x38];
    s32 field40;
    u32 sector;
    u16 offset;
    u16 mask;
    u8 data[0x20];
    u8 shift;
} State;

extern s32 fn_803DDF18(State *, s32);
extern s32 PFSEC_ReadData(s32, void *, u32, u16, u32, u32 *, s32);

s32 fn_803DEE48(State *p)
{
    u32 count;
    s32 field40;
    s32 old;
    s32 error;
    s32 status;

    if (p->sector == 0xFFFFFFFFU || p->data[0] == 0 || p->position >= 0xF423F) {
        field40 = p->field40;
        old = p->position;
        p->position = (field40 + 1) << p->shift;
        status = fn_803DDF18(p, 0);
        if (status != 0) {
            p->position = old;
            p->field40 = field40;
            return 1;
        }
        if (p->sector != 0xFFFFFFFFU) {
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
            return error != 0;
        }
        return 1;
    }
    return 0;
}