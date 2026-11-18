#pragma force_active on

#include <types.h>

struct CopyW_0x4E { u32 w[0x4E]; };
struct CopyB_0xA0 { u8  b[0xA0]; };
struct CopyW_0x0E { u32 w[0x0E]; };

struct Slot {
    u8 pad[0x4C];
    u8 player;  /* 0x4C */
    u8 index;   /* 0x4D */
    u8 pad4E;   /* 0x4E */
    u8 flag4F;  /* 0x4F */
};

struct Flag {
    u32 hi : 8; /* 0x50 */
    u32 lo : 24;
};

struct Entry {
    u8 pad[0xC6];
    u8 bit80 : 1;
    u8 padbits : 6;
    u8 bit0 : 1;
    u8 padbit2 : 1;
    u8 bit40 : 1;
    u8 padbit3 : 6;
    u8 pad2[0x218 - 0xC8];
};

extern "C" u8 fn_800C851C(void);
extern "C" u8 fn_800C8548(void);
extern "C" void netReport__FPCce(const char*, ...);
extern "C" void fn_800C8F68(const char*, ...);
extern "C" void fn_8014B130(int);
extern "C" void fn_800CF770(void*, u8);
extern "C" void** getInstance__12ntFriendInfoFv(void);
extern "C" int fn_8014FD6C(void);
extern "C" void fn_800D0398(void*);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);

extern char lbl_80457158[];
extern char g_Network[];
extern int lbl_805A03A8;
extern int lbl_805A0434;

extern "C" void fn_800CFEB8(u8* self) {
    u8* dst;
    u8* src;
    char* base = lbl_80457158;

    if (self[0xFD4] != 4) {
        u8 a = fn_800C851C();
        if (a == 0xFF)
            a = 4;
        if (self[0xFD4] != a) {
            u8 b = fn_800C851C();
            if (b == 0xFF)
                b = 4;
            if (b == 4) {
                u8 c = fn_800C851C();
                u8 d = c;
                if (c == 0xFF)
                    d = 4;
                netReport__FPCce(base + 0x10E4, self[0xFD4], d);
            } else {
                u8 c = fn_800C851C();
                u8 d = c;
                if (c == 0xFF)
                    d = 4;
                netReport__FPCce(base + 0x111C, self[0xFD4], d);
            }
            u8 e = fn_800C851C();
            u8 f = e;
            if (e == 0xFF)
                f = 4;
            fn_800C8F68(base + 0x1150, self[0xFD4], f);
            fn_8014B130(0xD);
        }
    } else {
        src = self + self[0xFD4] * 0x218;
        u8 loc = fn_800C851C();
        if (loc == 0xFF)
            loc = 4;
        dst = self + loc * 0x218;

        *(CopyW_0x4E*)(dst + 0x70) = *(CopyW_0x4E*)(src + 0x70);
        *(CopyB_0xA0*)(dst + 0x1A8) = *(CopyB_0xA0*)(src + 0x1A8);
        *(CopyW_0x0E*)(dst + 0x248) = *(CopyW_0x0E*)(src + 0x248);
        dst[0x280] = src[0x280];
        dst[0x281] = src[0x281];
        fn_800CF770(self, self[0xFD4]);

        Slot* slot = (Slot*)self;
        for (s32 i = 0; i < 4; i++) {
            if (self[0xFD4] == slot->player) {
                u8 l = fn_800C851C();
                if (l == 0xFF)
                    l = 4;
                slot->player = l;
            }
            slot = (Slot*)((u8*)slot + 8);
        }

        u8 sel = fn_800C851C();
        if (sel == 0xFF)
            sel = 4;
        char* fr = *(char**)getInstance__12ntFriendInfoFv();
        *(CopyB_0xA0*)(self + sel * 0x218 + 0x1A8) = *(CopyB_0xA0*)(fr + 0x450);

        void* net = *(void**)(g_Network + 0x30);
        u64 value;
        if (net != 0) {
            value = *(u64*)((char*)net + 0x3440);
        } else {
            value = 0;
        }
        *(u64*)(dst + 0x80) = value;

        s32 ret = fn_8014FD6C();
        ((Entry*)dst)->bit80 = ret;

        u8 t = fn_800C851C();
        if (t == 0xFF)
            t = 4;

        s32 off;
        Slot* s27;
        Flag* f26;
        s32 off18;
        s32 cnt = 0;
        if (t != 4) {
            s27 = (Slot*)self;
            f26 = (Flag*)(self + 0x50);
            off18 = t * 0x18;
            s32 k = 0;
            off = 0;
            do {
                u8* e;
                u8 g = fn_800C8548();
                if (g == 0xFF) {
                    u8 l = fn_800C851C();
                    if (l == 0xFF)
                        l = 4;
                    e = (u8*)((u32)self + l * 0x218 + 0x70);
                } else {
                    u8* p = self + g * 0x218;
                    e = p + 0x70;
                    if (!((p[0xE8] >> 7) & 1)) {
                        u8 l = fn_800C851C();
                        if (l == 0xFF)
                            l = 4;
                        e = (u8*)((u32)self + l * 0x218 + 0x70);
                    }
                }

                s32 ok;
                if (e[t + 0x68] != 1) {
                    ok = 0;
                } else {
                    s32 w = *(s32*)(off + (u32)(e + off18) + 0x84);
                    ok = ((w >> 24) == 1);
                }

                if (ok != 0) {
                    s27->player = t;
                    s27->index = cnt;
                    cnt = cnt + 1;
                    f26->hi = 1;
                    f26 = (Flag*)((u8*)f26 + 8);
                    s27->flag4F = 0;
                    s27 = (Slot*)((u8*)s27 + 8);
                }
                k += 1;
                off += 8;
            } while (k < 3);
        }

        u8 n = fn_800C851C();
        if (n == 0xFF)
            n = 4;
        Entry* rec = (Entry*)(self + n * 0x218);
        u32 old = rec->bit40;
        u32 enabled = *(s32*)((char*)lbl_805A0434 + 0x3408) < 0x40;
        rec->bit40 = enabled;
        if (old != enabled) {
            u8 m = fn_800C851C();
            if (m == 0xFF)
                m = 4;
            u8* rec2 = self + m * 0x218;
            ((Entry*)rec2)->bit0 = 0;
            fn_800D0AE0(self, rec2);
            fn_80145B98(lbl_805A03A8, 0xFE);
        }

        fn_800D0398(self);
        u16 v1050 = *(u16*)(self + 0x1050);
        *(s16*)(self + 0xFDA) = (s16)(v1050 * 0x3C);
        netReport__FPCce(base + 0x1050, v1050);

        u8 z = fn_800C851C();
        if (z == 0xFF)
            z = 4;
        self[0xFD4] = z;
    }
}
