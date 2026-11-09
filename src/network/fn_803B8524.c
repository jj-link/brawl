#include <types.h>

#pragma force_active on

typedef struct {
    u16 unk0;
    u8 pad02[10];
    u32 unkC;
    u8 pad10[8];
    u16 unk18;
    u8 pad1A[6];
    u8 unk20;
    u8 pad21;
    u8 unk22;
    u8 pad23[5];
    u32 unk28;
    u8 pad2C[8];
    u32 unk34;
    u8 pad38[0x1838];
    u32 unk1870;
    u8 pad1874[0x1C];
    s32 (*unk1890)(u32);
} UnkStruct;

extern int fn_803BFFC8(void *, void *, int, int, int);

s32 fn_803B8524(UnkStruct *arg0, u32 arg1, s32 *arg2)
{
    union {
        u16 word;
        struct {
            u8 first;
            u8 second;
        } bytes;
    } sp8;
    s32 status;
    u16 within;
    u32 block;
    u32 tries;
    u16 flags;
    u16 offset;

    if (arg0 == 0) {
        *arg2 = -1;
        return 10;
    }

    if ((arg1 < 2 || arg1 >= arg0->unk34 + 2) &&
        arg1 != 0 && arg1 != 1) {
        *arg2 = -1;
        return 14;
    }

    flags = arg0->unk18;
    offset = arg1 + ((s32)arg1 >> 1);
    block = (u16)(arg0->unk28 + ((s32)offset >> arg0->unk20));
    tries = 1;
    within = (u16)(offset & (arg0->unk0 - 1));

    if (flags & 0x80) {
        tries = flags & 7;
    }

    do {
        if (within < arg0->unk0 - 1) {
            status = fn_803BFFC8(arg0, &sp8.word, (u16)block,
                                within, 2);
        } else {
            status = fn_803BFFC8(arg0, &sp8.word, (u16)block,
                                within, 1);
            if (status == 0) {
                status = fn_803BFFC8(arg0, &sp8.bytes.second,
                                    (u16)block + 1, 0, 1);
            }
        }

        if (status == 0x1000 && arg0->unk1890 != 0) {
            s32 result = arg0->unk1890(arg0->unk1870);

            if (result == 0) {
                continue;
            }
            if (result == 1 && arg0->unk22 >= 2 &&
                tries < arg0->unk22) {
                tries++;
                block += (u16)arg0->unkC;
                continue;
            }
        }

        if (status != 0) {
            *arg2 = -1;
            return status;
        }
    } while (status != 0);

    {
        u16 word = sp8.word;
        u16 swapped = ((word >> 8) & 0xFF) |
                      ((word << 8) & 0xFF00);

        if (arg1 & 1) {
            *arg2 = (swapped >> 4) & 0xFFF;
        } else {
            *arg2 = swapped & 0xFFF;
        }
    }

    return 0;
}
