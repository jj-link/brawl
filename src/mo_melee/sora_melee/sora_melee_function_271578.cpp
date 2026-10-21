#pragma force_active on

typedef unsigned long u32;

struct ResMdl {
    void* data;
};

struct ResAnmClr {
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
    virtual void Bind(const ResMdl*);
};

struct Model {
    char pad[0xE8];
    ResMdl resource;
};

struct ModelAnimation {
    char pad[0x18];
    AnmObj* animation;
};

struct Obj {
    char pad0[4];
    u32 state;
    char pad8[8];
    Model* model;
    ModelAnimation* animation;
    u32 index;
};

extern "C" {
u32 GetResAnmClrNumEntries__Q34nw4r3g3d7ResFileFv(ModelAnimation*);
void* fn_8018DAE8(ModelAnimation*, u32);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
AnmObj* Construct__Q34nw4r3g3d15AnmObjMatClrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmClrQ34nw4r3g3d6ResMdlb(
    void*, int*, const ResAnmClr*, const ResMdl*, bool);
void Destroy__Q34nw4r3g3d6G3dObjFv(AnmObj*);
void bindMatColAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(ModelAnimation*, Model*);
void setFrame__16gfModelAnimationFd(ModelAnimation*, double);

extern const float lbl_27_rodata_4470;
extern u32 lbl_27_data_57EE8;

void fn_27_271578(Obj* self) {
    Model* mdl = self->model;
    ModelAnimation* animation = self->animation;
    u32 index = self->index;
    ResMdl model = mdl->resource;

    if (index < GetResAnmClrNumEntries__Q34nw4r3g3d7ResFileFv(animation)) {
        struct Params {
            int size;
            ResAnmClr anim;
            ResMdl model;
            ResMdl bindModel;
        } params;

        ResAnmClr anim;
        anim.data = fn_8018DAE8(animation, index);
        if (anim.data) {
            void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);
            params.model = model;
            params.anim = anim;
            AnmObj* object =
                Construct__Q34nw4r3g3d15AnmObjMatClrResFP12MEMAllocatorPiQ34nw4r3g3d9ResAnmClrQ34nw4r3g3d6ResMdlb(
                    allocator, &params.size, &params.anim, &params.model, false);
            if (object) {
                params.bindModel = model;
                object->Bind(&params.bindModel);
                if (animation->animation)
                    Destroy__Q34nw4r3g3d6G3dObjFv(animation->animation);
                animation->animation = object;
            }
        }
    }

    bindMatColAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(self->animation, self->model);
    setFrame__16gfModelAnimationFd(self->animation, lbl_27_rodata_4470);
    self->state = lbl_27_data_57EE8;
}
}
