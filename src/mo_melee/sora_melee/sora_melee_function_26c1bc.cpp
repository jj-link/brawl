#pragma force_active on

typedef unsigned long u32;

struct ResMdl {
    void* data;
    ResMdl(void* p) : data(p) {}
};

struct ResAnmShp {
    void* data;
    ResAnmShp(void* p) : data(p) {}
};

struct G3dObj {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void setFrame(float);
    virtual void f9();
    virtual void bind(ResMdl);
};

struct ModelAnimation {
    char pad[0x1c];
    G3dObj* shpAnim;
};

struct ScnMdl {
    char pad[0xE8];
    ResMdl model;
};

struct grGimmick {
    char pad[0x44];
    ScnMdl** models;
    ModelAnimation** animations;
    void changeShapeAnim(u32, u32);
};

extern "C" {
u32 GetResAnmShpNumEntries__Q34nw4r3g3d7ResFileFv(void*);
ResAnmShp fn_8018E100(void*, u32);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
G3dObj* fn_8019BC04(void*, int*, ResAnmShp, ResMdl, bool);
void Destroy__Q34nw4r3g3d6G3dObjFv(G3dObj*);
void unbindShapeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(ModelAnimation*, ScnMdl*);
void bindShapeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(ModelAnimation*, ScnMdl*);
void setFrame__16gfModelAnimationFd(ModelAnimation*, double);
extern const float lbl_27_rodata_4388;
extern const float lbl_27_rodata_4398;
}

void grGimmick::changeShapeAnim(u32 index, u32 slot) {
    if (animations) {
        slot *= 4;
        unbindShapeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(
            *(ModelAnimation**)((char*)animations + slot), *models);
        ResMdl model((*(ScnMdl**)((char*)models + slot))->model);
        ModelAnimation* animation = *(ModelAnimation**)((char*)animations + slot);
        if (index < GetResAnmShpNumEntries__Q34nw4r3g3d7ResFileFv(animation)) {
            ResAnmShp anim(fn_8018E100(animation, index));
            if (anim.data) {
                int size;
                void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);
                G3dObj* obj = fn_8019BC04(allocator, &size, anim, model, false);
                if (obj) {
                    obj->bind(model);
                    if (animation->shpAnim) {
                        Destroy__Q34nw4r3g3d6G3dObjFv(obj);
                    }
                    animation->shpAnim = obj;
                }
            }
        }
        bindShapeAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(
            *(ModelAnimation**)((char*)animations + slot),
            *(ScnMdl**)((char*)models + slot));
        setFrame__16gfModelAnimationFd(
            *(ModelAnimation**)((char*)animations + slot), lbl_27_rodata_4388);
        (*(ModelAnimation**)((char*)animations + slot))->shpAnim->setFrame(lbl_27_rodata_4398);
    }
}
