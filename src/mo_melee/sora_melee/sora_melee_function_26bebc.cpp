#pragma force_active on

typedef unsigned int u32;

struct ResMdl {
    void* data;
    ResMdl(void* p) : data(p) {}
};

struct ResAnmTexPat {
    void* data;
    ResAnmTexPat(void* p) : data(p) {}
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
    virtual void f8();
    virtual void f9();
    virtual void bind(ResMdl);
};

struct ModelAnimation {
    char pad[0x10];
    G3dObj* texAnim;
};

struct ScnMdl {
    char pad[0xE8];
    ResMdl model;
};

struct Object {
    char pad[0x44];
    ScnMdl** models;
    ModelAnimation** animations;
};

extern "C" {
u32 GetResAnmTexPatNumEntries__Q34nw4r3g3d7ResFileFv(void*);
ResAnmTexPat fn_8018DCF0(void*, u32);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
G3dObj* Construct__Q34nw4r3g3d15AnmObjTexPatResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexPatQ34nw4r3g3d6ResMdlb(void*, int*, ResAnmTexPat, ResMdl, bool);
void Destroy__Q34nw4r3g3d6G3dObjFv(G3dObj*);
void bindTexAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(ModelAnimation*, ScnMdl*);
void setFrame__16gfModelAnimationFd(ModelAnimation*, double);
extern const float lbl_27_rodata_4388;

void fn_27_26BEBC(Object* self, u32 index, int slot) {
    if (self->animations) {
        slot *= 4;
        ModelAnimation* animation = (*(ModelAnimation**)((char*)self->animations + slot));
        ResMdl model = (*(ScnMdl**)((char*)self->models + slot))->model;
        if (index < GetResAnmTexPatNumEntries__Q34nw4r3g3d7ResFileFv(animation)) {
            ResAnmTexPat resource = fn_8018DCF0(animation, index);
            if (resource.data) {
                void* allocator = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(15);
                int size;
                G3dObj* obj = Construct__Q34nw4r3g3d15AnmObjTexPatResFP12MEMAllocatorPiQ34nw4r3g3d12ResAnmTexPatQ34nw4r3g3d6ResMdlb(
                    allocator, &size, resource, model, false);
                if (obj) {
                    obj->bind(model);
                    if (animation->texAnim)
                        Destroy__Q34nw4r3g3d6G3dObjFv(animation->texAnim);
                    animation->texAnim = obj;
                }
            }
        }
        bindTexAnim__16gfModelAnimationFPQ34nw4r3g3d6ScnMdl(
            (*(ModelAnimation**)((char*)self->animations + slot)),
            (*(ScnMdl**)((char*)self->models + slot)));
        setFrame__16gfModelAnimationFd(
            (*(ModelAnimation**)((char*)self->animations + slot)),
            lbl_27_rodata_4388);
    }
}
}
