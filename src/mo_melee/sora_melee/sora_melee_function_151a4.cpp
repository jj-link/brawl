#pragma force_active on

#include <types.h>
#include <nw4r/g3d/g3d_anmchr.h>

#define V1(n) virtual void unused_##n();
#define V2(n) V1(n##a) V1(n##b)
#define V4(n) V2(n##a) V2(n##b)
#define V8(n) V4(n##a) V4(n##b)
#define V16(n) V8(n##a) V8(n##b)
#define V32(n) V16(n##a) V16(n##b)
#define V64(n) V32(n##a) V32(n##b)

struct ResFile {
    void* data;
};

struct Pad8 {
    u8 pad[8];
};

struct A {
    u8 pad[0xE8];
    void* m_e8;
};

class B {
public:
    V1(b0)
    virtual nw4r::g3d::AnmObjChrRes* get3(s32);
};

class W : public Pad8 {
public:
    V4(w) V2(w2) V1(w3)
    virtual void* get9(s32, s32);
};

class Y : public Pad8 {
public:
    V8(y) V4(y2) V1(y3)
    virtual A* get15();
};

class C {
public:
    V4(c) V1(c2)
    virtual u32 get7();
};

class Z {
public:
    V8(z) V2(z2) V1(z3)
    virtual s32 get13(s32);
    V32(zz) V4(zy) V2(zx) V1(zw)
    virtual void* get53(s32, s32);
};

struct X {
    W* m0;
    Y* m4;
    u8 pad8[0x54 - 8];
    Z* m54;
    u8 pad58[0xC0 - 0x58];
    C* mC0;
};

struct Mid168 {
    u8 pad[0xD8];
    X* mD8;
};

class Self {
public:
    V16(s) V2(s2) V1(s3)
    virtual void* get21(s32, s32);
    V64(t) V32(u) V8(v)
    virtual void* get126(s32, s32);
    u8 pad4[0x34 - 4];
    u8 m34[0x148 - 0x34];
    B* m148;
    u8 pad14c[0x164 - 0x14c];
    u8 pad164 : 6;
    u8 flag : 1;
    u8 lowFlag : 1;
    u8 pad165[3];
    Mid168* m168;
    u8 m16c;
};

extern "C" {
void fn_8018E808(ResFile*);
void Init__Q34nw4r3g3d7ResFileFPv(ResFile*);
void fn_8018E5D4(ResFile*, const ResFile*);
u32 fn_8018E4A4(ResFile*);
u32 fn_8018E3C0(ResFile*);
void* fn_8018D5D4(ResFile*, void*);
void* GetResAnmChr__Q34nw4r3g3d7ResFileFi(ResFile*, s32);
MEMAllocator* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(u32);
u8* fn_27_20FE4(void*, s32, s32);

static inline void* loadRes(Self* self, void* first) {
    ResFile file;
    ResFile copy;
    ResFile otherCopy;
    ResFile other;
    file.data = first;
    if (self->m16c == 0 && file.data != 0) {
        fn_8018E808(&file);
        Init__Q34nw4r3g3d7ResFileFPv(&file);
        copy = file;
        fn_8018E5D4(&file, &copy);
        if (!self->flag && fn_8018E4A4(&file) == 1) {
            void* p2 = self->m168->mD8->m0->get9(0, 0xFFFF);
            if (p2 != 0) {
                other.data = p2;
                Init__Q34nw4r3g3d7ResFileFPv(&other);
                otherCopy = other;
                fn_8018E5D4(&file, &otherCopy);
            }
        }
    }
    return file.data;
}

static inline void bindIdx(nw4r::g3d::AnmObjChrRes* res, nw4r::g3d::ResMdl m, u32 a2) {
    res->Bind((int*)&m, a2, 1);
}

nw4r::g3d::AnmObjChrRes* fn_27_151A4(Self* self, s32 a1, u32 a2, u32 a3, int* a4, s32 a5) {
    void* mdl;
    nw4r::g3d::AnmObjChrRes* res;
    ResFile heap;
    void* anm;
    void* first;
    s32 r23;

    mdl = self->m168->mD8->m4->get15()->m_e8;
    res = 0;
    if (a2 == -1) {
        res = self->m148->get3(a1);
    }
    if (res == 0) {
        u8 flagByte = fn_27_20FE4(self->m34, a1, a5)[1];
        r23 = a1 & -(self->m16c == 0);
        if ((flagByte & 8) != 0 && self->m168->mD8->m54->get13(0) != 0) {
            first = self->m168->mD8->m54->get53(0, r23);
        } else {
            first = self->get126(r23, a1);
        }
        heap.data = loadRes(self, first);
        if (heap.data != 0 && fn_8018E3C0(&heap) == 1) {
            MEMAllocator* alloc = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(self->m168->mD8->mC0->get7());
            if (self->m16c == 0) {
                anm = GetResAnmChr__Q34nw4r3g3d7ResFileFi(&heap, 0);
            } else {
                anm = fn_8018D5D4(&heap, self->get21(a1, a5));
            }
            nw4r::g3d::ResAnmChr anim(anm);
            nw4r::g3d::ResMdl model(mdl);
            res = nw4r::g3d::AnmObjChrRes::Construct(alloc, a4, anim, model, false);
            if (res == 0) {
                return 0;
            }
            if (a3 == 1) {
                if (a2 == -1) {
                    res->Bind(nw4r::g3d::ResMdl(mdl));
                } else {
                    bindIdx(res, nw4r::g3d::ResMdl(mdl), a2);
                }
            }
        }
    }
    return res;
}
}
