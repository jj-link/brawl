#include <types.h>
#include <snd/snd_system.h>
#include <nw4r/g3d/g3d_anmclr.h>
#include <string.h>
#pragma force_active on

struct State {
    char pad0[0x64c];
    void* objects;
    char pad1[0x670 - 0x650];
    u32 mode;
    u32 idx;
    u32 maxIdx;
    u32 count;
    u32 n680;
    u32 n684;
    char pad2[0x738 - 0x688];
    u32 m738;
    u32 m73c;
    u32 m740;
    u32 m744;
    u32 m748;
    u32 m74c;
    u32 m750;
    u32 m754;
    u32 m758;
    u32 m75c;
    u8 b760;
};
struct Data42 { u32 values[42]; };
struct TableSpace {
    Data42 first;
    Data42 third;
    Data42 second;
};
struct Obj154 { char pad[0x154]; void* p154; };
struct Obj158 { char pad[0x158]; void* p158; };
struct Obj14 { char pad[0x14]; void* p14; };
struct Obj18 { char pad[0x18]; nw4r::g3d::AnmObjMatClrRes* anim; };

extern "C" {
extern u32 lbl_18_data_1820[42];
extern const float lbl_18_rodata_348;
extern const float lbl_18_rodata_34C;
void fn_18_17B0(State*, int, int, float);
void fn_18_925C(State*);
u64 fn_803F1798(u64, u32);
}

extern "C" int fn_18_8648(State* self, u32 flags) {
    u32 sel;
    u64 activeMask;
    int changed = 0;
    u32 bit;
    if (self->mode < 5) {
        if (self->idx == 0) sel = 0;
        else sel = self->mode + (self->idx - 1) * 5 + 2;
    } else {
        if (self->idx == 0) sel = 1;
        else {
            sel = 0x2b;
            if (self->idx <= self->count) sel = self->mode + (self->idx - 1) * 2 + 0x1c;
        }
    }

    u32 cursor = 0xffffffffu;
    u32 selectedCount = 0;
    u32 flagsOr = 0;
    bit = 0;

    TableSpace tables;
    tables.first = *(Data42*)lbl_18_data_1820;
    tables.second = tables.first;

    activeMask = *(u64*)&self->m738;

    u32* tablePtr = tables.second.values;
    for (; bit < 0x1f; ++bit, ++tablePtr) {
        u64 mask = fn_803F1798(1ULL, *tablePtr);
        if (activeMask & mask) {
            ++selectedCount;
            if (cursor == 0xffffffffu) cursor = bit;
            flagsOr |= 1;
        }
    }
    u32 bit2 = 0;
    for (bit2 = 0; bit2 < 0xa; ++bit2) {
        u64 mask = fn_803F1798(1ULL, bit2 + 0x28);
        if (activeMask & mask) {
            ++selectedCount;
            if (cursor == 0xffffffffu) cursor = bit2 + 0x28;
            flagsOr |= 2;
        }
    }
    if (activeMask & 0x4000000000000ULL) {
        if (cursor == 0xffffffffu) cursor = 0x32;
        flagsOr |= 4;
    }

    if (flags & 1) {
        if (self->idx == 0) {
            u32 m = self->mode;
            if (m < 5) {
                u32 n = self->n680;
                if (n != 0 && m >= n) self->idx = self->maxIdx - 1;
                else self->idx = self->maxIdx;
            } else if (self->b760) {
                self->idx = self->count + 1;
            } else if (m == 6 && self->n684 == 1) {
                self->idx = self->count - 1;
            } else self->idx = self->count;
        } else {
            if (self->mode >= 5 && self->idx >= self->count + 1) {
                if (self->mode == 6 && self->n684 == 1) self->idx = self->count - 1;
                else self->idx = self->count;
            } else self->idx--;
        }
        changed = 1;
    } else if (flags & 2) {
        if (self->mode < 5) {
            if (self->idx == self->maxIdx || (self->n680 != 0 && self->mode >= self->n680 && self->idx == self->maxIdx - 1)) self->idx = 0;
            else self->idx++;
        } else {
            if (self->idx >= self->count + 1) self->idx = 0;
            else if (self->idx == self->count - 1 && self->n684 != 0 && self->mode - 5 >= self->n684) {
                if (self->b760) self->idx = self->count + 1;
                else self->idx = 0;
            } else if (self->idx == self->count && !self->b760) self->idx = 0;
            else self->idx++;
        }
        changed = 1;
    } else if (flags & 4) {
        u32 v = self->idx;
        changed = 1;
        if (v == 0) {
            if (self->mode < 5) self->mode = 5;
            else self->mode = 0;
        } else {
            u32 m = self->mode;
            if (m == 0) {
                u32 c = self->count;
                if (v > c) {
                    if (!self->b760) {
                        u32 n = self->n680;
                        if (n == 0) self->mode = 4;
                        else if (v == self->maxIdx && n == 1) changed = 0;
                        else self->mode = n - 1;
                    } else self->mode = 5;
                } else if (v == c && self->n684 == 1) self->mode = 5;
                else self->mode = 6;
            } else if (v == self->maxIdx && m >= 5) {
                u32 n = self->n680;
                if (n == 0) self->mode = 4;
                else self->mode = n - 1;
            } else if (m == 6 && v == 6) self->mode -= 2;
            else self->mode--;
        }
    } else if (flags & 8) {
        changed = 1;
        if (self->idx == 0) {
            if (self->mode < 5) self->mode = 5;
            else self->mode = 0;
        } else {
            if (self->mode == 6) self->mode = 0;
            else if (self->mode >= 5 && self->idx > self->count) self->mode = 0;
            else if (self->idx == self->count && self->mode == 5 && self->n684 == 1) self->mode = 0;
            else if (self->idx == self->maxIdx && self->mode == self->n680 - 1) {
                if (self->b760) self->mode = 5;
                else {
                    if (self->mode == 0) changed = 0;
                    self->mode = 0;
                }
            } else if (self->mode == 4 && self->idx > self->count) {
                if (self->b760) self->mode++;
                else self->mode = 0;
            } else self->mode++;
        }
    } else if (flags & 0x200) {
        if (self->idx == 0) {
            if (self->mode < 5) {
                Obj154* objects = (Obj154*)self->objects;
                Obj14* a = (Obj14*)objects->p154;
                Obj18* b = (Obj18*)a->p14;
                if (b->anim->GetFrame() == lbl_18_rodata_34C) {
                    g_sndSystem->playSE((SndID)0x24, -1, 0, 0, -1);
                    *(u64*)&self->m738 |= *(u64*)&self->m740;
                    for (u32 i = 0; i < 0x1f; ++i)
                        fn_18_17B0(self, i + 0x57, 0x10, lbl_18_rodata_34C);
                    fn_18_17B0(self, 0x55, 0x10, lbl_18_rodata_348);
                } else if (selectedCount == 1) {
                    g_sndSystem->playSE((SndID)3, -1, 0, 0, -1);
                } else {
                    g_sndSystem->playSE((SndID)0x24, -1, 0, 0, -1);
                    *(u64*)&self->m738 &= *(u64*)&self->m748;
                    for (u32 i = 0; i < 0x1f; ++i)
                        fn_18_17B0(self, i + 0x57, 0x10, lbl_18_rodata_348);
                    fn_18_17B0(self, 0x55, 0x10, lbl_18_rodata_34C);
                    if (flagsOr == 1 || flagsOr == 5) {
                        u64 mask = fn_803F1798(1ULL, cursor);
                        *(u64*)&self->m738 |= mask;
                        fn_18_17B0(self, cursor + 0x57, 0x10, lbl_18_rodata_34C);
                    }
                }
            } else {
                Obj158* objects = (Obj158*)self->objects;
                Obj14* a = (Obj14*)objects->p158;
                Obj18* b = (Obj18*)a->p14;
                if (b->anim->GetFrame() == lbl_18_rodata_34C) {
                    g_sndSystem->playSE((SndID)0x24, -1, 0, 0, -1);
                    *(u64*)&self->m738 |= *(u64*)&self->m750;
                    for (u32 i = 0; i < 0xa; ++i)
                        fn_18_17B0(self, i + 0x76, 0x10, lbl_18_rodata_34C);
                    fn_18_17B0(self, 0x56, 0x10, lbl_18_rodata_348);
                } else if (selectedCount == 1) {
                    g_sndSystem->playSE((SndID)3, -1, 0, 0, -1);
                } else {
                    g_sndSystem->playSE((SndID)0x24, -1, 0, 0, -1);
                    *(u64*)&self->m738 &= *(u64*)&self->m758;
                    for (u32 i = 0; i < 0xa; ++i)
                        fn_18_17B0(self, i + 0x76, 0x10, lbl_18_rodata_348);
                    fn_18_17B0(self, 0x56, 0x10, lbl_18_rodata_34C);
                    if (flagsOr == 2 || flagsOr == 6) {
                        u64 mask = fn_803F1798(1ULL, cursor);
                        *(u64*)&self->m738 |= mask;
                        fn_18_17B0(self, cursor + 0x4e, 0x10, lbl_18_rodata_34C);
                    }
                }
            }
        } else {
            u32 slot = sel - 2;
            tables.third = tables.first;
            u32 selectedBit = tables.third.values[slot];
            u64 mask = fn_803F1798(1ULL, selectedBit);
            u32 doPaint = 1;
            if (activeMask & mask) {
                if (selectedCount == 2) {
                    fn_18_17B0(self, 0x55, 0x10, lbl_18_rodata_34C);
                    fn_18_17B0(self, 0x56, 0x10, lbl_18_rodata_34C);
                    doPaint = 0;
                }
                if (selectedCount == 1 && selectedBit != 0x32) {
                    g_sndSystem->playSE((SndID)3, -1, 0, 0, -1);
                } else {
                    g_sndSystem->playSE((SndID)0x24, -1, 0, 0, -1);
                    fn_18_17B0(self, slot + 0x57, 0x10, lbl_18_rodata_348);
                    *(u64*)&self->m738 ^= mask;
                }
            } else {
                g_sndSystem->playSE((SndID)0x24, -1, 0, 0, -1);
                fn_18_17B0(self, slot + 0x57, 0x10, lbl_18_rodata_34C);
                *(u64*)&self->m738 ^= mask;
            }
            if (doPaint == 1) {
                u64 active;
                u64 limit = *(u64*)&self->m740;
                active = *(u64*)&self->m738 & limit;
                if (active == 0) fn_18_17B0(self, 0x55, 0x10, lbl_18_rodata_34C);
                else if (limit == active)
                    fn_18_17B0(self, 0x55, 0x10, lbl_18_rodata_348);

                u64 active2;
                u64 limit2 = *(u64*)&self->m750;
                active2 = *(u64*)&self->m738 & limit2;
                if (active2 == 0) fn_18_17B0(self, 0x56, 0x10, lbl_18_rodata_34C);
                else if (limit2 == active2)
                    fn_18_17B0(self, 0x56, 0x10, lbl_18_rodata_348);
            }
        }
    }

    if (changed) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        fn_18_925C(self);
        return 1;
    }
    return 0;
}
