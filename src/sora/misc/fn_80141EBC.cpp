#include <types.h>
#include <string.h>
#pragma force_active on

struct NetEntry {
    u8 flag;
    u8 pad1;
    u8 mode;
    u8 pad3;
    u16 unk4;
    u8 pad6[0x14 - 0x6];
    u32 tick;
    u32 stamp;
    u16 unk1C;
    u16 pad1E;
};

extern "C" {
void netReport__FPCce(const char*, ...);
u32 OSGetTick(void);
void fn_80022DD0(s32, u16);
void fn_800C8F68(const char*, ...);
void fn_8014B130(int);
void fn_80143F7C(s32, int);
void* fn_801410CC(void*, int);
extern char lbl_8045E018[];
extern u8 lbl_8059E742;
extern void* lbl_805A0390;
extern s32 lbl_805A03A8;
extern u8 lbl_805A0418[8];
extern const f32 lbl_805A2ADC;
extern const f32 lbl_805A2AEC;
}

inline void update(unsigned char* self) {
    self[0x11] = 0;
    self[0x12] = 0;
    for (unsigned char j = 0; j < 4; j++) {
        if (*(signed char*)(self + 0xB0 + j * 0x20) != 0) {
            self[0x12] |= 1 << j;
            self[0x11]++;
        }
    }
}

extern "C" s32 fn_80141EBC(void* arg0) {
    char* base = lbl_8045E018;
    u8* self = (u8*)arg0;
    u8* head;
    u32 tick = OSGetTick();

    if (*(void**)(self + 0x454) == NULL) {
        return -1;
    }

    s32 r22 = *(s32*)(self + 0x50) + 3;
    NetEntry* e;
    u8 i;

    for (i = 0, e = (NetEntry*)(self + 0xB0); i < 4; i++, e++) {
        if (i == lbl_8059E742) continue;
        if ((s8)e->flag == 0) continue;

        u32 ms;
        s32 elapsed;
        elapsed = (s32)tick - (s32)e->stamp;
        ms = *(u32*)0x800000F8 / 4 / 1000;

        if (elapsed > (s32)(ms * 20000)) {
            netReport__FPCce(base + 0x440, (u32)elapsed / ms, 0x4E20, i);

            u32 k;
            for (k = 0; k < 4; k++) {
                netReport__FPCce(
                    base + 0x46C,
                    tick,
                    *(u32*)(self + (u8)k * 0x20 + 0xC8),
                    *(u8*)(self + (u8)k * 0x20 + 0xB2));
            }

            *(u8*)(self + (u8)i * 0x20 + 0xB0) = 0;
            update(self);

            fn_80143F7C(lbl_805A03A8, i);

            s32 j;
            u8* p;
            u32 r18m;
            u32 b19;
            b19 = 1u << i;
            r18m = *(u8*)(self + 0x12) & ~b19;
            p = (u8*)(self + 0x250);

            for (j = 0; j < 0x40; j++, p += 8) {
                if (p[0] != 0) {
                    p[0] = (u8)(p[0] | b19);
                    if (r18m == (r18m & p[0])) {
                        netReport__FPCce(
                            base + 0x4A0, *(u16*)(p + 2), p[1], 0x22B8, i);
                        fn_80022DD0(0, *(u16*)(p + 2));
                        p[0] = 0;
                        p[1] = 0;
                        *(u16*)(p + 2) = 0;
                        *(u32*)(p + 4) = 0;
                    }
                }
            }

            fn_800C8F68(base + 0x4D8);
            fn_8014B130(10);
        } else {
            *(u32*)(self + 0x170) = 0;
            u8* r19 = *(u8**)(self + 0x178);
            r19[0] = 8;
            r19[1] = 0xF8;
            r19[2] = (u8)((r19[2] & 3) | 0x14);

            u16 r16 = *(u16*)(self + 0x148);
            u8* p = (u8*)fn_801410CC(arg0, i);
            if (p != NULL) {
                r16 = *(u16*)(p + 0xE);
            }

            r19[8] = (u8)(r16 >> 8);
            r19[9] = (u8)r16;

            f32 f1 = (f32)((s32)e->unk1C - (s32)r16);
            u32 q1 = *(u32*)((char*)lbl_805A0390 + 0x1B4) /
                     (*(u32*)0x800000F8 / 4 / 1000);
            f32 val = f1 + (lbl_805A2ADC + ((f32)q1 / lbl_805A2AEC));
            *(f32*)((char*)lbl_805A0390 + 0x20C) = (f32)(s16)val;

            u8* q;
            if (p == NULL) goto clearTime;
            q = p + i * 0x18;
            if (*(u32*)(q + 0x20) == 0) goto clearTime;
            {
                u32 v = *(u32*)(q + 0x20) + (OSGetTick() - *(u32*)(q + 0x24));
                r19[4] = (u8)(v >> 24);
                r19[5] = (u8)(v >> 16);
                r19[6] = (u8)(v >> 8);
                r19[7] = (u8)v;
            }
            goto timeReady;

        clearTime:
            r19[4] = 0;
            r19[5] = 0;
            r19[6] = 0;
            r19[7] = 0;

        timeReady:
            ;

            u32 r18 = 0;
            u8* r17 = r19 + 0xD;
            head = *(u8**)(self + 0x454);
            u32 off = i * 0x18;

            while (head != NULL) {
                if (head[off + 0x15] == 0) break;
                head = *(u8**)(head + 8);
            }

            if (head != NULL) {
                s32 h = *(u16*)(head + 0xE);
                r19[0xA] = (u8)(h >> 8);
                r19[0xB] = (u8)h;

                u32 n = 0x10;
                while (head != NULL && n != 0) {
                    r17[0] = head[0x10];
                    r17[1] = head[0x11];
                    r17[2] = head[0x12];

                    memcpy(
                        r17 + 3,
                        *(u8**)(head + 0x74) +
                            (*(u32*)(self + 0x54)) *
                                lbl_805A0418[2 * lbl_8059E742],
                        *(u32*)(self + 0x50));

                    e->unk4 = 0;
                    r17 += r22;
                    n--;
                    r18++;
                    e->mode = 1;
                    e->tick = tick;
                    *(u32*)head = 3;
                    head[0xD] = 1;
                    head = *(u8**)(head + 8);
                }
            }

            u8* ch;
            s32 sz;
            r19[0xC] = (u8)r18;
            sz = (s32)(r22 * r18) + 0xD;

            if (sz >= 0x400) {
                netReport__FPCce(base + 0x4F0);
            } else {
                r19[2] = (u8)((r19[2] & 0xFC) | (((u32)sz >> 8) & 3));
                r19[3] = (u8)sz;

                ch = self + i * 0x14;
                void* src = *(void**)(self + 0x178);
                if ((s32)(*(u32*)(ch + 0x5C) - *(u32*)(ch + 0x60)) >= sz) {
                    memcpy(
                        *(u8**)(ch + 0x68) + *(u32*)(ch + 0x60),
                        src,
                        sz);
                    *(u32*)(ch + 0x60) = *(u32*)(ch + 0x60) + sz;
                }
            }
        }
    }

    return 0;
}
