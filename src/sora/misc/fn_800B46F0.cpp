#pragma force_active on
struct ResMdl { void* data; };
struct ResAnmChr { void* data; };
struct AnmObj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual void Bind(ResMdl);
};
struct Info { char pad[0x20]; int idx; };
struct Anm { char pad[0x28]; void* cb; Info* info; };
struct Holder { char pad[0xC]; Anm* anm; };
struct Scn {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void f(int, int);
};
struct MEMAllocator;
struct MuObject {
    char pad0[4];
    char unk4[4];
    void* unk8;
    char padC[4];
    Scn* mdl;
    Holder* anim;
    char pad18[0x3C];
    int heap;
    bool changeNodeAnimNIf(const char*);
};
extern "C" {
void* fn_8018D5D4(void*);
void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(Holder*, Scn*);
void bindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(Holder*, Scn*);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
AnmObj* Construct__Q34nw4r3g3d12AnmObjChrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmChrQ34nw4r3g3d6ResMdlb(void*, int*, ResAnmChr, ResMdl, bool);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_800B458C();
extern int lbl_8059C648;
}
inline void make(ResAnmChr a, ResMdl m, Holder* h, int heap) {
    int size;
    void* al = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(heap);
    if (a.data) {
        AnmObj* o = Construct__Q34nw4r3g3d12AnmObjChrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmChrQ34nw4r3g3d6ResMdlb(al, &size, a, m, false);
        if (o) {
            o->Bind(m);
            if (h->anm) Destroy__Q34nw4r3g3d6G3dObjFv(h->anm);
            h->anm = (Anm*)o;
        }
    }
}
bool MuObject::changeNodeAnimNIf(const char*) {
    ResAnmChr a;
    a.data = fn_8018D5D4(unk4);
    if (!a.data) return false;
    unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(anim, mdl);
    ResMdl m;
    m.data = unk8;
    make(a, m, anim, heap);
    bindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(anim, mdl);
    Anm* x = anim->anm;
    int i = x->info->idx;
    void* p;
    if (i == 0) p = (void*)fn_800B458C;
    else p = ((void**)&lbl_8059C648)[i];
    x->cb = p;
    Scn* s = mdl;
    s->f(2, 0);
    s->f(5, 0);
    return true;
}
