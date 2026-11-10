#include <types.h>
#include <nt/nt_send.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on
struct Node {
    s32 type;
    u8 pad4[4];
    Node* next;
    u8 pad0c[2];
    u16 key;
    u8 pad10[4];
    u8 flag;
};
struct Main {
    u8 pad0[0xa8];
    s32 unkA8;
    u8 padAC[0x178 - 0xac];
    u8* unk178;
    u8 pad17c[0x194 - 0x17c];
    u32 unk194;
    u8 pad198[0x454 - 0x198];
    Node* unk454;
};
extern "C" void netReport__FPCce(const char*, ...);
extern char lbl_8045E218[];
extern Main* lbl_805A0390;
extern NtSend* lbl_805A03D4;
extern const f32 lbl_805A2AC8;
extern const f32 lbl_805A2AD4;
extern const f32 lbl_805A2B1C;
extern "C" u32 fn_80140790(u8 arg0, u32 arg1, u8* arg2) {
    Node* n;
    u8* buf;
    u8* base;
    u32 start;
    u32 key;
    u32 r7;
    f32 f3;
    if (arg1 < 0x18) {
        netReport__FPCce(lbl_8045E218);
        return arg1;
    }
    if (lbl_805A0390->unkA8 > 3) return 0x18;
    key = (u16)(arg2[5] + (arg2[4] << 8));
    n = lbl_805A0390->unk454;
    while (n != 0) {
        if (n->key == key) {
            if ((u32)(n->type - 3) > 1U) goto invalid;
            goto found;
        }
        n = n->next;
    }
invalid:
    n = 0;
found:
    if (n == 0) return 0x18;
    ((Node*)((u8*)n + arg0 * 0x18))->flag = 1;
    start = arg2[9] + (arg2[8] << 8) + ((arg2[6] << 24) + (arg2[7] << 16));
    if (start != 0) {
        base = (u8*)lbl_805A0390 + ((arg0 << 5) & 0x1FE0);
        *(f32*)(base + 0xb8) = (f32)(OSGetTick() - start);
        f3 = *(f32*)(base + 0xbc);
        if (lbl_805A2AC8 == f3) {
            *(f32*)(base + 0xbc) = *(f32*)(base + 0xb8);
        } else {
            *(f32*)(base + 0xbc) = lbl_805A2B1C * f3 + lbl_805A2AD4 * *(f32*)(base + 0xb8);
        }
    }
    buf = lbl_805A0390->unk178;
    buf[0] = 8;
    buf[1] = 0xF8;
    u8 t = buf[2] & 0xFC;
    buf[3] = 0x18;
    buf[2] = (u8)((t & 3) | 8);
    {
        u32 k = arg2[5] + (arg2[4] << 8);
        buf[4] = (u8)(k >> 8);
        buf[5] = (u8)k;
    }
    r7 = lbl_805A0390->unk194;
    buf[6] = (u8)(r7 >> 24);
    buf[7] = (u8)(r7 >> 16);
    buf[8] = (u8)(r7 >> 8);
    buf[9] = (u8)r7;
    lbl_805A03D4->pushback(arg0, buf, 0x18);
    return 0x18;
}