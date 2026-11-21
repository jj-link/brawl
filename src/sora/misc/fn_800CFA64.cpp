#include <types.h>
#include <mt/mt_prng.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

extern "C" u8 fn_800C851C();
extern "C" int fn_800C8524();
extern "C" u8 fn_800C8548();
extern "C" void fn_800D0398(void*);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(void*, int);
extern "C" int fn_80149140(void*);
extern "C" void fn_803F8C5C(u32);
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_80457158[];
extern void* lbl_805A03A8;
extern mtRand lbl_805A0420;
extern void* lbl_805A0434;

struct BitFlag { u8 top : 1; u8 rest : 7; };
struct Flags { u8 high : 4; u8 low : 4; };
struct Slot { u8 a, b, c, d; u32 x; };
struct Entry {
    u8 pad0[0x68];
    u8 states[4];
    u8 pad1[0x0c];
    u8 active : 1;
    u8 rest : 7;
};

extern "C" void fn_800CFA64(void* self) {
    const char* report = lbl_80457158;
    u8* base = (u8*)self;
    u8 idx = fn_800C851C();
    if (idx == 0xff) idx = 4;
    u8* p = base + idx * 0x218;
    p[0xc2] = 0xff;
    p[0xc6] &= ~0x40;
    p[0xc6] &= ~0x0c;
    p[0xc6] &= ~0x20;
    ((Flags*)(p + 0xc8))->high = 0;
    p[0xca] = 0;
    p[0xc4] = fn_80149140(lbl_805A0434);
    base[0xe8] &= ~0x60;
    base[0x300] &= ~0x60;
    base[0x518] &= ~0x60;
    base[0x730] &= ~0x60;
    u8* w_ptr = base + 0x51;
    u8* base_ptr = base;
    u8* slot_ptr = base + 0x4c;
    for (int counter = 0; counter < 4; counter++) {
        if ((w_ptr[0] >> 7) & 1) {
            base_ptr[0x4c] = 0xff;
            base_ptr[0x4d] = 0;
            *(u32*)(slot_ptr + 4) &= 0xffffff;
            base_ptr[0x4e] = 0;
            base_ptr[0x4f] = 0;
            ((BitFlag*)(slot_ptr + 5))->top = 0;
        }
        w_ptr += 8;
        base_ptr += 8;
        slot_ptr += 8;
    }
    for (u8 i = 0; i < 4; i++) {
        u8* entry = base + i * 0x218;
        int valid;
        if (i >= 4U) {
            valid = 0;
        } else {
            u8 selected = fn_800C8548();
            Entry* target;
            if (selected == 0xff) {
                u8 local = fn_800C851C();
                if (local == 0xff) local = 4;
                target = (Entry*)(base + local * 0x218 + 0x70);
            } else {
                target = (Entry*)((unsigned long)base + selected * 0x218 + 0x70);
                if (!target->active) {
                    u8 local = fn_800C851C();
                    if (local == 0xff) local = 4;
                    target = (Entry*)(base + local * 0x218 + 0x70);
                }
            }
            valid = !(((u8*)target)[i + 0x68] - 1);
        }
        if (valid)
            netReport__FPCce(report + 0x10b0, i, entry[0xc5], (s8)entry[0xaa], (s8)entry[0xc2], (entry[0xc6] >> 6) & 1, entry[0xca], *(u16*)(base + 0xfda) / 60);
    }
    idx = fn_800C8548();
    u8* selected;
    if (idx == 0xff) selected = 0;
    else selected = (u8*)((unsigned long)base + idx * 0x218 + 0x70);
    if (selected) {
        for (u8 i = 0; i < 4; i++) {
            if (selected[i + 0x68] == 1)
                netReport__FPCce(report + 0x10d8, i, (s8)selected[i * 0x18 + 0x86]);
        }
    }
    lbl_805A0420.mtRand::init(OSGetTick());
    u32 seed = lbl_805A0420.mtRand::generate();
    fn_803F8C5C(seed);
    srandi(seed);
    netReport__FPCce(report + 0xf5c, seed);
    idx = fn_800C851C();
    if (idx == 0xff) idx = 4;
    p = base + idx * 0x218;
    p[0x1a0] = seed >> 24;
    p[0x1a1] = seed >> 16;
    p[0x1a2] = seed >> 8;
    p[0x1a3] = seed;
    if (fn_800C8524()) {
        p = base + fn_800C8548() * 0x218;
        p[0x280] |= 0x40;
    }
    fn_800D0398(self);
    idx = fn_800C851C();
    if (idx == 0xff) idx = 4;
    p = base + idx * 0x218;
    p[0xc6] |= 1;
    fn_800D0AE0(self, p);
    fn_80145B98(lbl_805A03A8, 0xfe);
}