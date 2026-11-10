#include <types.h>
#pragma force_active on

extern "C" float lbl_9_rodata_0[];
extern "C" void* fn_800B03F0(void*, int);
extern "C" void fn_9_8E8(void*, void*, int, void*);
extern "C" void fn_9_9D8(void*);
extern "C" void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
extern "C" void* Construct__Q34nw4r3g3d6ScnMdlFPviiPv(void*, int, int, void*);
extern "C" void setFrameNode__8MuObjectFf(void* obj, float frame);

struct Anm {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setFrame(float f);
};

struct Self {
    char pad0[0x40];
    void* m40;
    void* m44;
    void* m48;
    char pad4c[0x78 - 0x4c];
    void* m78;
    void* m7c;
    void* m80;
    char pad84[0x18c - 0x84];
    void* m18c;
    char pad190[0x19c - 0x190];
    void* m19c;
    char pad1a0[0x1ac - 0x1a0];
    void* res[3];
    char pad1b8[0x17f0 - 0x1b8];
    void* m17f0;
};

#define FLD(p, off) (*(void**)((char*)(p) + (off)))
#define ANM(p, b) ((Anm*)FLD(FLD(p, 0x14), b))

extern "C" void fn_9_74C(Self* self) {
    float* const base = lbl_9_rodata_0;
    self->res[0] = fn_800B03F0(self->m17f0, 0x28);
    self->res[1] = fn_800B03F0(self->m17f0, 0x32);
    self->res[2] = fn_800B03F0(self->m17f0, 0x14);
    fn_9_8E8(self, base + 10, 0xd, self->res);
    fn_9_9D8(self);
    self->m19c = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(
        getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2b), 0, 0xb,
        FLD(self->m48, 0x10));
    ANM(self->m40, 0xc)->setFrame(base[36]);
    ANM(self->m40, 0x18)->setFrame(base[36]);
    ANM(self->m44, 0x14)->setFrame(base[36]);
    ANM(self->m44, 0x18)->setFrame(base[36]);
    ANM(self->m80, 0x18)->setFrame(base[36]);
    ANM(self->m18c, 0xc)->setFrame(base[36]);
    ANM(self->m18c, 0x18)->setFrame(base[36]);
    setFrameNode__8MuObjectFf(self->m78, base[36]);
    setFrameNode__8MuObjectFf(self->m7c, base[37]);
}
