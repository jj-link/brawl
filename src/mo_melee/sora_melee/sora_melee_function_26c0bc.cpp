#pragma force_active on
typedef unsigned long u32;
struct Res {
    void* data;
    Res(void* p) : data(p) {}
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
    virtual void bind(Res);
};
struct ModelAnimation {
    char pad[0x18];
    AnmObj* color;
};
struct grGimmick {
    char pad[0x44];
    Model** models;
    ModelAnimation** animations;
};
extern "C" {
u32 GetResAnmClrNumEntries__Q34nw4r3g3d7ResFileFv(ModelAnimation*);
void* fn_8018DAE8(ModelAnimation*, u32);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
AnmObj* Construct__Q34nw4r3g3d15AnmObjMatClrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmClrQ34nw4r3g3d6ResMdlb(void*, int*, Res, Res, bool);
void Destroy__Q34nw4r3g3d6G3dObjFv(AnmObj*);
void bindMatColAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(ModelAnimation*, Model*);
void setFrame__16gfModelAnimationFd(ModelAnimation*, double);
extern const float lbl_27_rodata_4388;
void changeMatColAnim__9grGimmickFUlUl(grGimmick* self, u32 animIndex, u32 modelIndex) {
    if (self->animations) {
        modelIndex *= 4;
        ModelAnimation* animation = *(ModelAnimation**)((char*)self->animations + modelIndex);
        Res resource((*(Model**)((char*)self->models + modelIndex))->resource);
        if (animIndex < GetResAnmClrNumEntries__Q34nw4r3g3d7ResFileFv(animation)) {
            Res anim(fn_8018DAE8(animation, animIndex));
            if (anim.data) {
                int size;
                void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);
                AnmObj* obj = Construct__Q34nw4r3g3d15AnmObjMatClrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmClrQ34nw4r3g3d6ResMdlb(allocator, &size, anim, resource, false);
                if (obj) {
                    obj->bind(resource);
                    if (animation->color) {
                        Destroy__Q34nw4r3g3d6G3dObjFv(animation->color);
                    }
                    animation->color = obj;
                }
            }
        }
        bindMatColAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(*(ModelAnimation**)((char*)self->animations + modelIndex), *(Model**)((char*)self->models + modelIndex));
        setFrame__16gfModelAnimationFd(*(ModelAnimation**)((char*)self->animations + modelIndex), lbl_27_rodata_4388);
    }
}
}
