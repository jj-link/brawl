#pragma force_active on

typedef unsigned long u32;

struct ResMdl {
    void* data;
};

struct ResAnmVis {
    void* data;
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
    virtual void Bind(ResMdl);
};

struct Model {
    char pad[0xE8];
    ResMdl resource;
};

struct ModelAnimation {
    void* file;
    char pad[4];
    AnmObj* animation;
};

struct grGimmick {
    char pad[0x44];
    Model** models;
    ModelAnimation** animations;
};

extern "C" {
u32 GetResAnmVisNumEntries__Q34nw4r3g3d7ResFileFv(void*);
void* fn_8018D8E0(void*, u32);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
AnmObj* Construct__Q34nw4r3g3d12AnmObjVisResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmVisQ34nw4r3g3d6ResMdl(
    void*, int*, ResAnmVis, ResMdl);
void Destroy__Q34nw4r3g3d6G3dObjFv(AnmObj*);
void bindVisibleAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(ModelAnimation*, Model*);
void setFrame__16gfModelAnimationFd(ModelAnimation*, double);
extern const float lbl_27_rodata_4388;

inline void makeAnimation(u32 index, ResMdl model, ModelAnimation* animation) {
    int size;
    ResAnmVis anim;
    anim.data = fn_8018D8E0(animation, index);
    void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);

    if (anim.data) {
        AnmObj* object =
            Construct__Q34nw4r3g3d12AnmObjVisResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmVisQ34nw4r3g3d6ResMdl(
                allocator, &size, anim, model);
        if (object) {
            object->Bind(model);
            if (animation->animation)
                Destroy__Q34nw4r3g3d6G3dObjFv(animation->animation);
            animation->animation = object;
        }
    }
}

inline void changeAnimation(u32 index, ResMdl model, ModelAnimation* animation) {
    if (index < GetResAnmVisNumEntries__Q34nw4r3g3d7ResFileFv(animation)) {
        makeAnimation(index, model, animation);
    }
}

void changeVisibleAnim__9grGimmickFUlUl(grGimmick* self, u32 index, u32 modelIndex) {
    if (self->animations) {
        changeAnimation(index, self->models[modelIndex]->resource,
                        self->animations[modelIndex]);
        bindVisibleAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(
            self->animations[modelIndex], self->models[modelIndex]);
        setFrame__16gfModelAnimationFd(
            self->animations[modelIndex], lbl_27_rodata_4388);
    }
}
}
