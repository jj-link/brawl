#include <revolution/AX/AXVPB.h>
#pragma force_active on

typedef struct Entry {
    AXVPB *voice;
    u32 flags;
    s32 volume;
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 e;
    s32 base;
    u8 pad24[0x4C];
} Entry;

extern Entry *lbl_805A0B60;
extern void fn_80206308(Entry *);

void fn_80207C20(AXVPB *voice, s32 value)
{
    s32 clamped;
    Entry *entry = &lbl_805A0B60[voice->index];

    if (value < 0) {
        clamped = 0;
    } else {
        clamped = 0x7F;
        if (value <= 0x7F) {
            clamped = value;
        }
    }

    entry->d = clamped;
    fn_80206308(entry);
    entry->flags |= 0x40000000;
}
