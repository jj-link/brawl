#include <types.h>
#pragma force_active on
extern "C" {
void* fn_80012324(void*, s32, void*);
void fn_8027CE3C(void*, s32);
void fn_8027EABC(void*, void*, u32, s32);
}
struct GlobalHolder { void* ptr; char padding[8]; };
extern "C" GlobalHolder lbl_8049DEC8;
extern "C" void* lbl_8059FF90;
extern "C" void* lbl_805A0EC8;
struct Array {
    void** data;
    s32 count;
    u32 raw;
    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15); }
    void clear() {
        if (isOwned()) dealloc();
        data = 0;
        count = 0;
        raw = (raw & 0x40000000) | 0x80000000;
    }
};
struct Obj {
    u8 pad0[0x14];
    u8 unk14;
    u8 pad15[3];
    void* unk18;
    void* unk1C;
    Array a;
    Array b;
    u8 pad38[0x18];
    u8 unk50;
};
struct Entry {
    void* unk0;
    u16 unk4;
    u8 pad6[0x1e];
};
extern "C" void fn_80089224(Obj* arg0) {
    arg0->b.clear();
    arg0->a.clear();
    if (arg0->unk50 != 0) {
        arg0->unk14 = 0;
        return;
    }
    u32 off;
    s32 found;
    u32 i;
    found = 0;
    i = 0;
    off = 0;
    for (; i < *(u32*)((char*)lbl_8049DEC8.ptr + 0x80); off += 0x24, i++) {
        Entry* e = (Entry*)(*(char**)((char*)lbl_8049DEC8.ptr + 0x7C) + off);
        arg0->unk18 = (char*)e + 4;
        if ((u16)(*(u16*)arg0->unk18 + 0xFFF4) <= 1) {
            arg0->unk1C = fn_80012324(lbl_8059FF90, 0x1A, e->unk0);
            if (arg0->unk1C != 0) {
                if (arg0->b.count == (s32)(arg0->b.raw & 0x3FFFFFFF)) {
                    fn_8027CE3C(&arg0->b, 4);
                }
                arg0->b.data[arg0->b.count++] = arg0->unk1C;
                if (arg0->a.count == (s32)(arg0->a.raw & 0x3FFFFFFF)) {
                    fn_8027CE3C(&arg0->a, 4);
                }
                arg0->a.data[arg0->a.count++] = arg0->unk18;
                found = 1;
            }
        }
    }
    if (found == 0) {
        arg0->unk14 = 0;
    } else {
        arg0->unk14 = 1;
    }
}