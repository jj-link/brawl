#include <types.h>
#pragma force_active on

typedef struct File {
    u8 pad0[6];
    u8 sectors;
    u8 pad7[0x15];
    s32 type;
    u8 pad20;
    u8 shift;
    u8 pad22[0xe];
    u32 base;
} File;

typedef struct State {
    u32 position;
    File *file;
    u8 pad08[8];
    u32 *info;
    u8 pad14[0x2c];
    u32 index;
    u32 sector;
    u16 offset;
    u16 mask;
    u8 data[0x20];
    u8 shift;
} State;

extern s32 fn_803B3C2C(State *, s32);
extern s32 fn_803B7B00(File *, u32, u32, u32 *);
extern s32 fn_803C0080(File *, void *, u32, u16, u32, u32 *, s32);

s32 fn_803B5230(State *self, s32 arg1)
{
    u32 cluster;
    u32 count1;
    u32 count2;
    u32 old;
    u32 next;
    u32 temp;
    File *file;
    u8 sectors;
    u32 candidate;
    u32 sector;
    u32 base;
    s32 result;
    s32 status;
    s32 readResult;

    if (self == 0)
        return 10;
    old = self->position;
    if (old == 0)
        return 0;
    temp = self->index;
    next = old - 1;
    if (temp != (next >> self->shift)) {
        file = self->file;
        sector = self->sector;
        sectors = file->sectors;
        base = file->base;
        candidate = ((sector - base) >> file->shift) + 2;
        if ((temp % sectors == 0) || sectors == 1) {
            if (file->type == 2 ||
                ((temp = *self->info) > 1 && base <= sector)) {
                result = fn_803B7B00(file, candidate, candidate, &cluster);
                if (result != 0)
                    return result;
                if (cluster == 0xffffffffU)
                    return 14;
            } else {
                cluster = temp;
            }
        } else {
            cluster = candidate;
        }
        self->position--;
        self->index--;
        file = self->file;
        if (file->type == 2 ||
            (*self->info > 1 && file->base <= self->sector))
            self->sector = file->base + ((cluster - 2) << file->shift) +
                           (self->index & (file->sectors - 1));
        else
            self->sector--;
        next = self->position;
        self->offset = (next & self->mask) << 5;
        if (self->sector != 0xffffffffU || arg1 == 0) {
            self->position = next;
            result = fn_803B3C2C(self, arg1);
            if (result != 0) {
                self->position = next;
                fn_803B3C2C(self, 0);
            } else {
                if (self->sector == 0xffffffffU) {
                    status = 16;
                } else {
                    readResult = fn_803C0080(self->file, self->data,
                                            self->sector, self->offset, 32,
                                            &count1, 0);
                    status = 17;
                    if (count1 == 32)
                        status = readResult;
                }
                result = status & ((-status | status) >> 31);
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
    if (old != next || self->sector != 0xffffffffU || arg1 == 0) {
        self->position = next;
        result = fn_803B3C2C(self, arg1);
        if (result != 0) {
            self->position = old;
            fn_803B3C2C(self, 0);
        } else {
            if (self->sector == 0xffffffffU) {
                status = 16;
            } else {
                readResult = fn_803C0080(self->file, self->data, self->sector,
                                        self->offset, 32, &count2, 0);
                status = 17;
                if (count2 == 32)
                    status = readResult;
            }
            result = status & ((-status | status) >> 31);
        }
        switch (result) {
        case 0:
            goto zero2;
        default:
            goto done2;
        }
    }
zero2:
    result = 0;
done2:
    return result;
}
