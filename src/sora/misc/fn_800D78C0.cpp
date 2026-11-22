#include <types.h>
#pragma force_active on
extern "C" u8 fn_800C851C(void);
extern "C" u8 fn_800C8548(void);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_804596A8[];
extern char lbl_804596FC[];
extern int lbl_805A03A8;
struct Flag { u8 rest : 7; u8 bit : 1; };
struct Flag7 { u8 bit : 1; u8 rest : 7; };
extern "C" void fn_800D78C0(char* base) {
    u8 idx = fn_800C851C();
    if (idx == 0xFF) idx = 4;
    u8* p31 = (u8*)(base + 8);
    s32* p30 = (s32*)(base + 0x58);
    s32* p29 = (s32*)(base + 0x54);
    int counter;
    char* p27 = base + 0x70 + idx * 0x218;
    int flag = 0;
    counter = 1;
    do {
        u8 b0 = p31[0x4C];
        u8 b1 = p31[0x4D];
        s32 state = *p30 >> 24;
        u8 b3 = p31[0x4F];
        u8 cur = fn_800C851C();
        if (cur == 0xFF) cur = 4;
        if (b0 == cur && state == 3) {
            char* sub = p27 + (b1 << 3);
            s32* w = (s32*)(sub + 0x38);
            *w = *w & 0x00FFFFFF;
            *(u8*)(sub + 0x3B) = 0;
            *(u8*)(sub + 0x3A) = 0x3E;
            *(u8*)(sub + 0x3B) = 0;
            *(u8*)(sub + 0x3C) = 0;
            *(u16*)(sub + 0x3E) = 0;
            *(u8*)(sub + 0x39) = b3;
            p31[0x4C] = 0xFF;
            p31[0x4D] = 0;
            p29[1] = p29[1] & 0x00FFFFFF;
            p31[0x4E] = 0;
            p31[0x4F] = 0;
            ((Flag7*)((char*)p29 + 5))->bit = 0;
            u8 cur2 = fn_800C851C();
            u8 reportIndex = cur2;
            if (reportIndex == 0xFF) reportIndex = 4;
            netReport__FPCce(lbl_804596A8, (int)reportIndex, (int)b1);
            flag = 1;
        }
        counter++;
        p31 += 8;
        p30 += 2;
        p29 += 2;
    } while (counter < 4);
    if (flag) {
        u8 idx2 = fn_800C8548();
        if (idx2 == 0xFF) {
            netReport__FPCce(lbl_804596FC);
            return;
        }
        u8 idx3 = fn_800C851C();
        if (idx3 == 0xFF) idx3 = 4;
        char* p = base + idx3 * 0x218;
        ((Flag*)(p + 0xC6))->bit = 0;
        fn_800D0AE0(base, p);
        fn_80145B98(lbl_805A03A8, (int)idx2);
    }
}
