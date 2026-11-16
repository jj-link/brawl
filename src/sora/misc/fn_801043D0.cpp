#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_obj.h>
#include <string.h>
#include <stdio.h>
#pragma force_active on

extern "C" {
extern char lbl_8059E480[3];
extern char lbl_8059E484[3];
extern char lbl_8059E540[6];
extern char lbl_8059E548[6];
extern const float lbl_805A2790;
void fn_80101948(void*, int);
int fn_801063BC();
void fn_801065E0(int, void*, void*, void*);
void fn_8019D950(void*);
void* fn_800FB65C(void*, void*, float, float);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* Construct__Q34nw4r3g3d6ScnMdlFPviiPv(void*, int, int, void*);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
MuObject* create__8MuObjectFPPQ34nw4r3g3d7ResFileiciQ25Heaps8HeapType(nw4r::g3d::ResFile**, int, char, int, HeapType);
}

struct Name {
    char s[65];
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11(void* a, void* b);
    char pad4[0xE4 - 4];
    void* fE4;
};

class OwnedObject {
public:
    virtual ~OwnedObject();
};

struct Self {
    char pad0[0x1BC];
    int f1BC;
    char pad1C0[0x27C - 0x1C0];
    Object_vptr_0* f27C;
    void* f280;
    void* f284;
    char pad288[0x2B0 - 0x288];
    char f2B0[4];
    int f2B4;
    char pad2B8[0x2CC - 0x2B8];
    MuObject* f2CC;
    char pad2D0[0x2D4 - 0x2D0];
    void* f2D4;
    char pad2D8[0x308 - 0x2D8];
    MuObject* f308;
    OwnedObject* f30C;
    void* f310;
    char pad314[0x318 - 0x314];
    void* f318;
    char pad31C[0x324 - 0x31C];
    void* f324;
};

extern "C" void fn_801043D0(Self* self) {
    Object_vptr_0* o = self->f27C;
    o->slot11(o->fE4, self->f2D4);

    MuObject* m = self->f2CC;
    char* mdl = *(char**)((char*)m + 8);
    int off = *(int*)(mdl + 0x3c);
    const char* src = off ? mdl + off : 0;
    Name n1, n2, n3, n4;
    n1.s[0] = 0;
    strcat(n1.s, src);
    n2 = n1;
    strcat(n2.s, lbl_8059E484);
    n3 = n2;
    sprintf(n3.s + strlen(n3.s), lbl_8059E480, 0);
    n4 = n3;
    m->changeNodeAnimNIf(n4.s);

    fn_80101948((char*)self + 0x2B0, self->f2B4 + 1);
    if (self->f318) {
        Destroy__Q34nw4r3g3d6G3dObjFv(self->f318);
    }
    MuObject* old308 = self->f308;
    self->f318 = 0;
    if (old308 != NULL) {
        delete old308;
        self->f308 = NULL;
    }

    nw4r::g3d::ResFile* sp8 = (nw4r::g3d::ResFile*)*(void**)((char*)self->f324 + 0x10);
    MuObject* created = create__8MuObjectFPPQ34nw4r3g3d7ResFileiciQ25Heaps8HeapType(&sp8, self->f1BC + 1, 0, 0, (HeapType)0x2A);
    old308 = self->f308;
    if (old308 != (void*)created) {
        delete old308;
        self->f308 = created;
    }

    void* var = __nw__FUlQ25Heaps8HeapType(0xC, 0x2A);
    if (var != NULL) {
        var = fn_800FB65C(var, self->f308, lbl_805A2790, lbl_805A2790);
    }
    OwnedObject* old30C = self->f30C;
    if (old30C != var) {
        delete old30C;
        self->f30C = (OwnedObject*)var;
    }

    void* id = *(void**)((char*)self->f308 + 0x10);
    void* alloc = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2A);
    void* g = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(alloc, 0, 1, id);
    void* oldG = self->f318;
    if (oldG != NULL) {
        Destroy__Q34nw4r3g3d6G3dObjFv(oldG);
    }
    self->f318 = g;
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->f284, g, lbl_8059E540);
    fn_8019D950(*(void**)((char*)self->f310 + 0x10));
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->f318, *(void**)((char*)self->f310 + 0x10), lbl_8059E548);
    int context = fn_801063BC();
    fn_801065E0(context, *(void**)((char*)self->f324 + 8), self->f308, self->f310);

    MuObject* m2 = (MuObject*)self->f280;
    char* mdl2 = *(char**)((char*)m2 + 8);
    int off2 = *(int*)(mdl2 + 0x3c);
    const char* src2 = off2 ? mdl2 + off2 : 0;
    Name m1, m2n, m3, m4;
    m1.s[0] = 0;
    strcat(m1.s, src2);
    m2n = m1;
    strcat(m2n.s, lbl_8059E484);
    m3 = m2n;
    sprintf(m3.s + strlen(m3.s), lbl_8059E480, 0);
    m4 = m3;
    m2->changeNodeAnimNIf(m4.s);
}
