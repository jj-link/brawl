#include <types.h>
#pragma force_active on
extern "C" u8 fn_800C851C(void);
extern "C" u8 fn_800C8548(void);
extern "C" void fn_800D0AE0(void*, void*);
extern "C" void fn_80145B98(int, int);
extern int lbl_805A03A8;
struct Color { u8 a, b, c, d; };
struct Entry { char pad[0xC6]; u8 flags_hi : 7; u8 flags_lo : 1; char pad2[0xD4 - 0xC7]; Color color; char pad3[0xED - 0xD8]; Color other; };
extern "C" void fn_800D81C4(char* self, const Color& color, bool flag) {
    bool doUpdate = flag;
    u8 idx = fn_800C851C();
    if (idx == 0xFF) idx = 4;
    ((Entry*)(self + idx * 0x218))->other = ((Entry*)(self + idx * 0x218))->color = color;
    u8 idx2 = fn_800C8548();
    char* other = idx2 == 0xFF ? 0 : self + 0x70 + idx2 * 0x218;
    if (other) *(Color*)(other + 0x7D) = color;
    if (!doUpdate) return;
    u8 idx3 = fn_800C851C();
    if (idx3 == 0xFF) idx3 = 4;
    Entry* entry2 = (Entry*)(self + idx3 * 0x218);
    entry2->flags_lo = 1;
    fn_800D0AE0(self, entry2);
    fn_80145B98(lbl_805A03A8, 0xFE);
}