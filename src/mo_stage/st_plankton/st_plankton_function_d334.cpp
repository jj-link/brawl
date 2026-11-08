#pragma force_active on

typedef unsigned int u32;
typedef unsigned char u8;

struct Res {
    void* data;
    Res(void* p) : data(p) {}
};

struct AnmObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void bind(Res m);
};

struct ModelAnim {
    u32 resFile;
    u32 spacer;
    AnmObj* vis;
    AnmObj* chr;
    AnmObj* texPat;
    AnmObj* texSrt;
    AnmObj* matClr;
};

struct ScnMdl {
    char pad[0xE8];
    void* resource;
};

struct Self {
    char pad[0x44];
    ScnMdl** model;
    ModelAnim** anim;
    char pad2[0x170 - 0x4C];
    u8 flag;
};

extern "C" {
int __cntlzw(u32);
u32 GetResAnmChrNumEntries__Q34nw4r3g3d7ResFileFv(void*);
u32 GetResAnmVisNumEntries__Q34nw4r3g3d7ResFileFv(void*);
u32 GetResAnmTexPatNumEntries__Q34nw4r3g3d7ResFileFv(void*);
u32 GetResAnmTexSrtNumEntries__Q34nw4r3g3d7ResFileFv(void*);
u32 GetResAnmClrNumEntries__Q34nw4r3g3d7ResFileFv(void*);
void* fn_8018D6D8(void*, u32);
void* fn_8018D8E0(void*, u32);
void* fn_8018DCF0(void*, u32);
void* fn_8018DEF8(void*, u32);
void* fn_8018DAE8(void*, u32);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(u32);
AnmObj* Construct__Q34nw4r3g3d12AnmObjChrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmChrQ34nw4r3g3d6ResMdlb(void*, int*, Res, Res, bool);
AnmObj* Construct__Q34nw4r3g3d12AnmObjVisResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmVisQ34nw4r3g3d6ResMdl(void*, int*, Res, Res);
AnmObj* Construct__Q34nw4r3g3d15AnmObjTexPatResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexPatQ34nw4r3g3d6ResMdlb(void*, int*, Res, Res, bool);
AnmObj* Construct__Q34nw4r3g3d15AnmObjTexSrtResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexSrtQ34nw4r3g3d6ResMdlb(void*, int*, Res, Res, bool);
AnmObj* Construct__Q34nw4r3g3d15AnmObjMatClrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmClrQ34nw4r3g3d6ResMdlb(void*, int*, Res, Res, bool);
void Destroy__Q34nw4r3g3d6G3dObjFv(AnmObj*);
void unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
void unbindVisibleAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
void unbindTexAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
void unbindTexSrtAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
void unbindMatColAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(void*, void*);
void bind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdlP16gfModelAnimation(void*, void*);
void setFrame__16gfModelAnimationFd(void*, double);
void setUpdateRate__16gfModelAnimationFf(void*, float);
void setLoop__16gfModelAnimationFd(void*, int);
u32 getFrameCount__16gfModelAnimationFd(void*);
extern const float lbl_74_rodata_1C0;
extern const float lbl_74_rodata_1C4;
}

static inline u32 gt(u32 n, u32 idx) { return (n << __cntlzw(n ^ idx)) >> 31; }

static inline void setChr(u32 idx, Res res, ModelAnim* anim) {
    int size;
    Res a(fn_8018D6D8(anim, idx));
    void* alloc = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);
    if (a.data) {
        AnmObj* obj = Construct__Q34nw4r3g3d12AnmObjChrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmChrQ34nw4r3g3d6ResMdlb(alloc, &size, a, res, false);
        if (obj) {
            obj->bind(res);
            if (anim->chr) Destroy__Q34nw4r3g3d6G3dObjFv(anim->chr);
            anim->chr = obj;
        }
    }
}
static inline void setChr2(u32 idx, Res res, ModelAnim* anim) {
    if (idx < GetResAnmChrNumEntries__Q34nw4r3g3d7ResFileFv(anim)) setChr(idx, res, anim);
}

static inline void setVis(u32 idx, Res res, ModelAnim* anim) {
    int size;
    Res a(fn_8018D8E0(anim, idx));
    void* alloc = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);
    if (a.data) {
        AnmObj* obj = Construct__Q34nw4r3g3d12AnmObjVisResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmVisQ34nw4r3g3d6ResMdl(alloc, &size, a, res);
        if (obj) {
            obj->bind(res);
            if (anim->vis) Destroy__Q34nw4r3g3d6G3dObjFv(anim->vis);
            anim->vis = obj;
        }
    }
}
static inline void setVis2(u32 idx, Res res, ModelAnim* anim) {
    if (idx < GetResAnmVisNumEntries__Q34nw4r3g3d7ResFileFv(anim)) setVis(idx, res, anim);
}

static inline void setTexPat(u32 idx, Res res, ModelAnim* anim) {
    int size;
    Res a(fn_8018DCF0(anim, idx));
    if (a.data) {
        void* alloc = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);
        AnmObj* obj = Construct__Q34nw4r3g3d15AnmObjTexPatResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexPatQ34nw4r3g3d6ResMdlb(alloc, &size, a, res, false);
        if (obj) {
            obj->bind(res);
            if (anim->texPat) Destroy__Q34nw4r3g3d6G3dObjFv(anim->texPat);
            anim->texPat = obj;
        }
    }
}
static inline void setTexPat2(u32 idx, Res res, ModelAnim* anim) {
    if (idx < GetResAnmTexPatNumEntries__Q34nw4r3g3d7ResFileFv(anim)) setTexPat(idx, res, anim);
}

static inline void setTexSrt(u32 idx, Res res, ModelAnim* anim) {
    int size;
    Res a(fn_8018DEF8(anim, idx));
    if (a.data) {
        void* alloc = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);
        AnmObj* obj = Construct__Q34nw4r3g3d15AnmObjTexSrtResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexSrtQ34nw4r3g3d6ResMdlb(alloc, &size, a, res, false);
        if (obj) {
            obj->bind(res);
            if (anim->texSrt) Destroy__Q34nw4r3g3d6G3dObjFv(anim->texSrt);
            anim->texSrt = obj;
        }
    }
}
static inline void setTexSrt2(u32 idx, Res res, ModelAnim* anim) {
    if (idx < GetResAnmTexSrtNumEntries__Q34nw4r3g3d7ResFileFv(anim)) setTexSrt(idx, res, anim);
}

static inline void setClr(u32 idx, Res res, ModelAnim* anim) {
    int size;
    Res a(fn_8018DAE8(anim, idx));
    if (a.data) {
        void* alloc = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);
        AnmObj* obj = Construct__Q34nw4r3g3d15AnmObjMatClrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmClrQ34nw4r3g3d6ResMdlb(alloc, &size, a, res, false);
        if (obj) {
            obj->bind(res);
            if (anim->matClr) Destroy__Q34nw4r3g3d6G3dObjFv(anim->matClr);
            anim->matClr = obj;
        }
    }
}
static inline void setClr2(u32 idx, Res res, ModelAnim* anim) {
    if (idx < GetResAnmClrNumEntries__Q34nw4r3g3d7ResFileFv(anim)) setClr(idx, res, anim);
}

extern "C" void fn_74_D334(void* self, u32 animIndex, int loop, int force, float* outFrame) {
    Self* s = (Self*)self;
    if (s->flag != animIndex || force != 0) {
        ScnMdl* mdl = *s->model;
        if (mdl != 0) {
            ModelAnim* anim = *s->anim;
            if (anim != 0) {
                Res res(mdl->resource);
                if (res.data != 0) {
                    unbindNodeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(anim, mdl);
                    unbindVisibleAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(anim, mdl);
                    unbindTexAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(anim, mdl);
                    unbindTexSrtAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(anim, mdl);
                    unbindMatColAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(anim, mdl);
                    s->flag = (u8)animIndex;
                    if (animIndex < 1) {
                        if (gt(GetResAnmChrNumEntries__Q34nw4r3g3d7ResFileFv(anim), animIndex)) setChr2(animIndex, res, anim);
                        if (gt(GetResAnmVisNumEntries__Q34nw4r3g3d7ResFileFv(anim), animIndex)) setVis2(animIndex, res, anim);
                        if (gt(GetResAnmTexPatNumEntries__Q34nw4r3g3d7ResFileFv(anim), animIndex)) setTexPat2(animIndex, res, anim);
                        if (gt(GetResAnmTexSrtNumEntries__Q34nw4r3g3d7ResFileFv(anim), animIndex)) setTexSrt2(animIndex, res, anim);
                        if (gt(GetResAnmClrNumEntries__Q34nw4r3g3d7ResFileFv(anim), animIndex)) setClr2(animIndex, res, anim);
                        bind__16gfModelAnimationFPQ34nw4r3g3d6ScnMdlP16gfModelAnimation(mdl, anim);
                        setFrame__16gfModelAnimationFd(anim, lbl_74_rodata_1C0);
                        setUpdateRate__16gfModelAnimationFf(anim, lbl_74_rodata_1C4);
                        setLoop__16gfModelAnimationFd(anim, loop);
                        if (outFrame) {
                            *outFrame = getFrameCount__16gfModelAnimationFd(anim);
                        }
                    }
                }
            }
        }
    }
}
