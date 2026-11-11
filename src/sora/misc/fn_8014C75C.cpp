#include <types.h>
#pragma force_active on
struct Hdr { u16 magic; u16 crc; u16 rev; u8 pad6; u8 pad7; };
struct Obj { Hdr* hdr; int size; u8 flag; u8 f9; };
extern "C" {
s16 NETCalcCRC16(void*, s32);
s32 fn_80351304(void*);
u32 fn_80351610(void*);
void fn_8035161C(void*);
s16 srSystemGetRevisionNumber__Fv(void);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
void* memset(void*, int, unsigned long);
}
extern Obj* lbl_805A044C;

static inline void adjust(unsigned int* field, unsigned int remainder) {
    if (remainder) *(long*)field += 32 - remainder;
}

extern "C" s32 fn_8014C75C(Hdr** out) {
    s32 r30;
    s32 r5;
    if (out == 0) return 0;
    if (lbl_805A044C == 0) {
        Obj* o = (Obj*)__nw__FUlQ25Heaps8HeapType(12, 0x2d);
        if (o) {
            unsigned int* sizeField = (unsigned int*)((char*)o + 4);
            *sizeField = 0x2804;
            adjust(sizeField, *sizeField & 31);
            o->hdr = (Hdr*)alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(0x2d, o->size);
            memset(o->hdr, 0, o->size);
            o->flag = 0;
            o->f9 = 0;
        }
        lbl_805A044C = o;
    }
    Obj* self = lbl_805A044C;
    if (self->hdr == 0) {
        r30 = 0;
    } else {
        r30 = self->flag;
        if (r30 == 0 && fn_80351304((u8*)self->hdr + 0x10) != 0 &&
            fn_80351610((u8*)self->hdr + 0x10) != 0) {
            r30 = 1;
        }
    }
    if (r30 == 0) {
        r5 = 0;
    } else {
        fn_8035161C((u8*)self->hdr + 0x10);
        self->flag = 0;
        self->hdr->magic = 0x2804;
        s16 rev = srSystemGetRevisionNumber__Fv();
        Hdr* t = self->hdr;
        t->rev = rev;
        self->hdr->pad6 = 0;
        self->hdr->crc = 0;
        s16 c = NETCalcCRC16(self->hdr, 0x2804);
        r5 = 1;
        self->hdr->crc = c;
        *out = self->hdr;
    }
    return r5;
}
