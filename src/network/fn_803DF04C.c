#include <types.h>
#include <revolution/VF/pf_sector.h>
#pragma force_active on

typedef struct File {
    u8 pad00[0x06];
    u8 blockSize;
    u8 pad07[0x15];
    s32 type;
    u8 pad20;
    u8 shift;
    u8 pad22[0x0E];
    u32 base;
} File;

typedef struct State {
    u32 position;
    File *file;
    u8 pad08[0x08];
    u32 *flag;
    u8 pad14[0x2C];
    u32 counter;
    u32 sector;
    u16 offset;
    u16 mask;
    u8 data[0x20];
    u8 shift;
} State;

extern s32 fn_803DDF18(State *, s32);
extern s32 fn_803E1CA8(File *, u32, u32, u32 *);

s32 fn_803DF04C(State *arg0, s32 arg1)
{
    s32 result;
    u32 cnt;
    u32 prev;
    u32 pos;
    u32 spC;
    u32 count;
    s32 r;
    s32 error;
    s32 status;

    pos = arg0->position;
    if (pos == 0) {
        return 0;
    }
    prev = pos - 1;
    if (arg0->counter != (prev >> arg0->shift)) {
        cnt = ((arg0->sector - arg0->file->base) >> arg0->file->shift) + 2;
        if (arg0->counter % arg0->file->blockSize == 0 ||
            arg0->file->blockSize == 1) {
            if (arg0->file->type == 2 ||
                (*arg0->flag > 1 &&
                 arg0->file->base <= arg0->sector)) {
                r = fn_803E1CA8(arg0->file, cnt, cnt, &spC);
                if (r != 0) {
                    return r;
                }
                if (spC == 0xFFFFFFFFU) {
                    return 0xE;
                }
            } else {
                spC = *arg0->flag;
            }
        } else {
            spC = cnt;
        }

        arg0->position = arg0->position - 1;
        arg0->counter = arg0->counter - 1;
        if (arg0->file->type == 2 ||
            (*arg0->flag > 1 && arg0->file->base <= arg0->sector)) {
            arg0->sector =
                (arg0->file->base +
                 ((spC - 2) << arg0->file->shift)) +
                (arg0->counter & (arg0->file->blockSize - 1));
        } else {
            arg0->sector = arg0->sector - 1;
        }
        arg0->offset = (u16)(((arg0->position & arg0->mask) << 5) & 0xFFE0);
        return 0;
    }

    if (pos != prev || arg0->sector != 0xFFFFFFFFU || arg1 == 0) {
        arg0->position = prev;
        result = fn_803DDF18(arg0, arg1);
        if (result != 0) {
            arg0->position = pos;
            fn_803DDF18(arg0, 0);
        } else {
            if (arg0->sector == 0xFFFFFFFFU) {
                error = 0x10;
            } else {
                status = PFSEC_ReadData(arg0->file, arg0->data,
                                        arg0->sector, arg0->offset, 0x20,
                                        (int *)&count, 0);
                error = 0x11;
                if (count == 0x20U) {
                    error = status;
                }
            }
            result = error & ((-error | error) >> 31);
        }
        switch (result) {
        case 0:
            goto zero;
        default:
            goto done;
        }
    }
zero:
    result = 0;
done:
    return result;
}