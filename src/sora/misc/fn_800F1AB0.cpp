#include <types.h>
#pragma force_active on

struct FnObj {
    u8 pad00[0x2C];
    u8 unk2C;
    u8 pad2D[0x13];
    s32 unk40;
    u8 pad44[0x1C];
    s32 unk60;
    u8 pad64[4];
    s32 unk68;
    u8 pad6C[4];
    s32 unk70;
    u8 pad74[0x10];
    void* unk84;
    void* unk88;
    u8 pad8C[0x20];
    void* unkAC;
    u8 padB0[0xC];
    void* unkBC;
    u8 padC0[4];
    void* unkC4;
    u8 padC8[8];
    s32 unkD0;
    s32 unkD4;
    u8 unkD8;
};

struct GfThreadObj {
    void* vt;
    u8 pad4[0x340 - 4];
    s32 unk340;
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(u32 size, int heap);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(void* heap, int type, s32 align);
void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(void* heap, int type);
void* fn_800C35CC(void* self, u32 mode, s32* a, s32* b, s32 c, s32 d, s32 e, s32 f, s32 g, s32 h, s32 i);
void fn_800F1DD4(void* self, void* file, s32 base, s32 c, s32 heap);
void fn_800F1ECC(void* self, s32 data, s32 arg2, s32 arg3);
void* fn_80152970(void* self, void* heap);
void createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(void* self, void* runnable, u32 a, u32 b, int heap);
extern u8 __vt__8gfThread[];
extern u8 __vt__16gfJpegEncodeWork[];
extern void* g_GameGlobal;
extern u8 lbl_805A25BC[4];
extern u8 lbl_80408C70[];

void fn_800F1AB0(FnObj* self, s32 a1, s32* a2, s32* a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 s9, s32 s10, u8 s11) {
    s32 sp1C;
    s32 sp18;
    u8 mode;
    void* obj;
    GfThreadObj* thread;
    void (*fn)(void*);

    self->unk2C = (u8)(self->unk2C & 0xFFFFFFFD);
    self->unkD0 = a1;
    fn_800F1DD4(self, a2, a6, a7, s9);
    fn_800F1ECC(self, a4, a7, s9);
    self->unk40 = a5;
    self->unk70 = 0;
    if (a1 == 2) {
        u8* p = *(u8**)((u8*)g_GameGlobal + 0x40);
        self->unkD8 = p[0x249C];
        self->unk68 = (*(s32*)(p + 0x24A0)) != 0;
    }
    self->unkD4 = s10;
    if (s10 == 0xFF) {
        self->unkD4 = s9;
    }
    mode = lbl_805A25BC[a1];
    obj = __nw__FUlQ25Heaps8HeapType(0x394, a7);
    if (obj != NULL) {
        sp1C = *a3;
        sp18 = *a2;
        obj = fn_800C35CC(obj, mode, &sp18, &sp1C, a4, a5, a6 + 5, a7, a7, 1, 0xF0);
    }
    self->unkAC = obj;
    if (s11 != 0) {
        self->unk60 = 1;
        self->unk84 = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll((void*)self->unkD4, 0x12C000, 0x20);
        self->unk88 = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl((void*)self->unkD4, 0x19008);
        obj = __nw__FUlQ25Heaps8HeapType(0x14, a7);
        if (obj != NULL) {
            obj = fn_80152970(obj, (void*)self->unkD4);
        }
        self->unkBC = obj;
        thread = (GfThreadObj*)__nw__FUlQ25Heaps8HeapType(0x360, a7);
        if (thread != NULL) {
            thread->vt = __vt__8gfThread;
            createThread__8gfThreadFP10gfRunnableUlUlQ25Heaps8HeapType(thread, thread, 0x11, 0x2000, 0x3A);
            thread->vt = __vt__16gfJpegEncodeWork;
            thread->unk340 &= 0xFFFFFF;
        }
        self->unkC4 = thread;
    } else {
        self->unk60 = 3;
        self->unk84 = NULL;
    }
    fn = *(void (**)(void*))(lbl_80408C70 + (self->unk60 << 3));
    if (fn != NULL) {
        fn(self);
    }
}
}
