#pragma force_active on

typedef unsigned long u32;

struct ResMdl {
    void* data;
    ResMdl(void* p) : data(p) {}
};

struct ResAnim {
    void* data;
    ResAnim(void* p) : data(p) {}
};

struct Model {
    char pad[0xE8];
    void* resource;
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
    virtual int Bind(ResMdl);
};

struct Animation {
    char pad[0x14];
    AnmObj* texSrt;
};

struct grGimmick {
    char pad[0x44];
    Model** models;
    Animation** animations;
};

extern "C" {
u32 GetResAnmTexSrtNumEntries__Q34nw4r3g3d7ResFileFv(Animation*);
void* fn_8018DEF8(Animation*, u32);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
AnmObj* Construct__Q34nw4r3g3d15AnmObjTexSrtResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexSrtQ34nw4r3g3d6ResMdlb(
    void*, int*, ResAnim, ResMdl, bool);
void Destroy__Q34nw4r3g3d6G3dObjFv(AnmObj*);
void bindTexSrtAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(Animation*, Model*);
void setFrame__16gfModelAnimationFd(Animation*, double);
extern const float lbl_27_rodata_4388;

void changeTexSrtAnim__9grGimmickFUlUl(grGimmick* self, u32 animIndex, u32 modelIndex) {
    if (self->animations) {
        modelIndex *= 4;
        Animation* animation = *(Animation**)((char*)self->animations + modelIndex);
        ResMdl model((*(Model**)((char*)self->models + modelIndex))->resource);

        if (animIndex < GetResAnmTexSrtNumEntries__Q34nw4r3g3d7ResFileFv(animation)) {
            ResAnim anim(fn_8018DEF8(animation, animIndex));
            if (anim.data) {
                int size;
                void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);
                AnmObj* obj = Construct__Q34nw4r3g3d15AnmObjTexSrtResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexSrtQ34nw4r3g3d6ResMdlb(
                    allocator, &size, anim, model, false);
                if (obj) {
                    obj->Bind(model);
                    if (animation->texSrt) {
                        Destroy__Q34nw4r3g3d6G3dObjFv(animation->texSrt);
                    }
                    animation->texSrt = obj;
                }
            }
        }

        bindTexSrtAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(
            *(Animation**)((char*)self->animations + modelIndex),
            (*(Model**)((char*)self->models + modelIndex)));
        setFrame__16gfModelAnimationFd(
            *(Animation**)((char*)self->animations + modelIndex),
            lbl_27_rodata_4388);
    }
}
}
