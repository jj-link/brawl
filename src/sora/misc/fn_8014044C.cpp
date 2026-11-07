#include <types.h>
#include <nt/nt_report.h>

struct Entry {
    u8 flag;
    u8 pad1;
    u16 id;
    u32 tick;
};

struct Obj {
    char pad000[0x130];
    s32 unk130;
    char pad134[0x10];
    u16 unk144;
    char pad146[6];
    u32 unk14C;
    char pad150[0x5A];
    s8 unk1AA;
    s8 unk1AB;
    char pad1AC[0x40];
    s32 unk1EC;
    s32 unk1F0;
    f32 unk1F4;
    char pad1F8[0x58];
    Entry unk250[0x40];
};

extern "C" {
void fn_8014BF68(char* p, int x);
u32 OSGetTick(void);
f32 fn_8014B130(int x);
u64 fn_800C8F68(const char* fmt, ...);
void netReport__FPCce(const char* fmt, ...);
}

extern int lbl_805A0434;
extern u8 lbl_8059E742;
extern char lbl_8045E188[];
extern NtReport lbl_8045E1C0;

#pragma force_active on
extern "C" void fn_8014044C(Obj* obj) {
    if (obj->unk14C == 0xB4) {
        int p = lbl_805A0434;
        fn_8014BF68((char*)p, 0);
        *(s32*)(p + 0x3430) = 0;
    }

    if (obj->unk14C % 60 == 1) {
        s32 prev = obj->unk1EC;
        s32 var = 100;
        obj->unk1AA = (s8)(obj->unk144 - prev);
        obj->unk1EC = obj->unk144;
        obj->unk1AB = (u8)(obj->unk130 - obj->unk1F0);
        obj->unk1F0 = obj->unk130;
        u8 b = *((u8*)obj + (lbl_8059E742 << 5) + 0xB1);
        if (b > 8) {
            var = 100 - (b - 8) * 10;
            if (var < 20) {
                var = 20;
            }
        }
        u8 c = obj->unk1AB;
        if (c > 3) {
            var -= (c - 3) * 10;
        }
        if (var < 0) {
            var = 0;
        }
        obj->unk1F4 = (f32)var;
    } else if (obj->unk14C % 60 == 2) {
        u32 tick = OSGetTick();
        Entry* e = obj->unk250;
        for (int i = 0; i < 0x40; i++, e++) {
            if (e->flag != 0 && (u32)(tick - e->tick) >= ((*(u32*)0x800000F8 >> 2) * 10)) {
                netReport__FPCce(lbl_8045E188, 0xA, e->id, e->flag);
                u64 ret = fn_800C8F68(lbl_8045E188, 0xA, e->id, e->flag);
                lbl_8045E1C0.report((const char*)(u32)ret);
                fn_8014B130(0xA);
            }
        }
    }
}
