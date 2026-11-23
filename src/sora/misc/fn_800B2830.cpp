#include <mu/mu_object.h>
#include <gf/gf_heap_manager.h>
#pragma force_active on
using namespace nw4r::g3d;
extern "C" {
extern int lbl_80455D70[];
void fn_8018E5D4(ResFile*, const ResFile*);
void* fn_8018D20C(ResFile*, int);
bool fn_8018E458(ResFile*);
bool fn_8018E4A4(ResFile*);
bool fn_8018E4F0(ResFile*);
bool fn_8018E40C(ResFile*);
bool fn_8018E53C(ResFile*);
void fn_801B0A28();
ScnMdl* fn_801B0B40(MEMAllocator*, unsigned int*, ResMdl*, unsigned int, int, void (*)());
void fn_801AAFF0(ScnMdl*, int);
void fn_801AB014(ScnMdl*, int);
extern const float lbl_805A2200;
void setFrame__16gfModelAnimationFd(gfModelAnimation*, double);
void* __nw__FUlQ25Heaps8HeapType(u32, Heaps::HeapType);
gfModelAnimation* __ct__16gfModelAnimationFd(gfModelAnimation*, ResFile*, ResMdl*, bool, u32, Heaps::HeapType);
}
struct Object {
    unsigned int flags;
    ResFile file;
    ResMdl model;
    ScnMdl* scene;
    ScnMdl* scene2;
    gfModelAnimation* anim;
    int a[4];
    int array[3];
    int node;
    unsigned char byte;
    char pad[3];
    float pos[3];
    float rot[3];
    Heaps::HeapType heap;
    int unknown;
    void* vtable;
};
inline void clearWords(int* p, int* end) {
    do { *p = 0; ++p; } while (p < end);
}
extern "C" Object* fn_800B2830(Object* self, ResFile* source, int index, int priority, ResFile* texture, bool animate, Heaps::HeapType heap) {
    u32 size;
    u32 textureCopy;
    u32 sp14;
    u32 resMdlCopy;
    u32 resFileCopy;
    u32 selfCopy;
    void* vt = lbl_80455D70;
    int* p = &self->a[3];
    self->vtable = vt;
    self->flags |= 0x80000000;
    self->file = ResFile();
    self->model = ResMdl();
    self->scene = 0;
    self->scene2 = 0;
    self->anim = 0;
    self->a[0] = 0;
    self->a[1] = 0;
    self->a[2] = 0;
    do { *p = 0; p++; } while (p < &self->node);
    self->node = -1;
    self->byte = 0xff;
    self->heap = (Heaps::HeapType)0x2b;
    self->unknown = 0;
    MEMAllocator* allocator = gfHeapManager::getMEMAllocator(heap);
    self->heap = heap;
    self->file = *source;
    if (texture) {
        textureCopy = *(u32*)texture;
        fn_8018E5D4(&self->file, (const ResFile*)&textureCopy);
    } else {
        selfCopy = *(u32*)&self->file;
        fn_8018E5D4(&self->file, (const ResFile*)&selfCopy);
    }
    self->model = ResMdl(fn_8018D20C(&self->file, index));
    unsigned int flags;
    if (animate) {
        unsigned int f = 0;
        if (fn_8018E458(&self->file)) f |= 0x10b;
        if (fn_8018E4A4(&self->file)) f |= 3;
        if (fn_8018E4F0(&self->file)) f |= 0x204;
        if (fn_8018E40C(&self->file)) f |= 0x40;
        if (fn_8018E53C(&self->file)) f |= 0x7000;
        flags = f | 0x10b;
    } else flags = 0;
    sp14 = *(u32*)&self->model;
    texture = (ResFile*)fn_801B0B40(allocator, (unsigned int*)&size, (ResMdl*)&sp14, flags, 1, fn_801B0A28);
    if (priority) {
        fn_801AAFF0((ScnMdl*)texture, priority);
        fn_801AB014((ScnMdl*)texture, priority);
    }
    self->scene = (ScnMdl*)texture;
    self->scene2 = (ScnMdl*)texture;
    self->pos[2] = lbl_805A2200;
    self->pos[1] = lbl_805A2200;
    self->pos[0] = lbl_805A2200;
    self->rot[2] = lbl_805A2200;
    self->rot[1] = lbl_805A2200;
    self->rot[0] = lbl_805A2200;
    char* node = (char*)self->model.GetResNode(0).ptr();
    for (;;) {
        int off = *(int*)(node + 0x5c);
        char* next;
        if (off == 0) {
            next = NULL;
        } else {
            next = node + off;
        }
        if (next == NULL) {
            break;
        }
        node = next;
    }
    self->node = node ? *(int*)(node + 0xc) : 0;
    if (!animate) return self;
    source = (ResFile*)__nw__FUlQ25Heaps8HeapType(0x20, heap);
    if (source) {
        resMdlCopy = *(u32*)&self->model;
        resFileCopy = *(u32*)&self->file;
        source = (ResFile*)__ct__16gfModelAnimationFd((gfModelAnimation*)source, (ResFile*)&resFileCopy, (ResMdl*)&resMdlCopy, true, (u32)index, heap);
    }
    gfModelAnimation::bind((ScnMdl*)texture, (gfModelAnimation*)source);
    self->anim = (gfModelAnimation*)source;
    ((gfModelAnimation*)source)->_spacer[0] = 0;
    setFrame__16gfModelAnimationFd((gfModelAnimation*)source, lbl_805A2200);
    return self;
}