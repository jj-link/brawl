#include <types.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_model.h>
#pragma force_active on
struct Self { u32 unk0; void* unk4; void* unk8; void* unkC; void* unk10; void* unk14; };
extern "C" {
void fn_8018E5D4(void*, const void*);
int fn_8018D20C(void*, int);
int fn_8018E458(void*);
int fn_8018E4A4(void*);
int fn_8018E4F0(void*);
int fn_8018E40C(void*);
int fn_8018E53C(void*);
void* fn_801B0B40(void*, void*, void*, u32, int, void (*)());
void fn_801B0A28();
void fn_801AAFF0(void*, const void*);
void fn_801AB014(void*, const void*);
extern f32 lbl_805A2200;
void* __nw__FUlQ25Heaps8HeapType(u32, Heaps::HeapType);
void* __ct__16gfModelAnimationFd(void*, void*, void*, int, int, Heaps::HeapType);
void setFrame__16gfModelAnimationFd(void*, double);
}
inline void* loadFile(const char* name, Heaps::HeapType heap) {
    gfFileIOHandle handle;
    void* buffer = 0;
    if (handle.read(name, heap, 0)) {
        buffer = handle.getBuffer();
        handle.getSize();
    }
    return buffer;
}
inline void bindSelf(void* res) { void* tmp = *(void**)res; fn_8018E5D4(res, &tmp); }
extern "C" void fn_800B2F84(Self* self, const char* name, void* arg2, int arg3, u32* arg4, Heaps::HeapType heap) {
    u32 tmp20;
    void* allocator = gfHeapManager::getMEMAllocator(heap);
    self->unk4 = loadFile(name, heap);
    if (!self->unk4) gfHeapManager::dumpAll();
    nw4r::g3d::ResFile::Init(&self->unk4);
    if (!arg4) {
        bindSelf(&self->unk4);
    } else {
        u32 tmp = *arg4;
        fn_8018E5D4(&self->unk4, &tmp);
    }
    self->unk8 = (void*)fn_8018D20C(&self->unk4, arg3);
    u32 flags = 0;
    if (fn_8018E458(&self->unk4)) flags |= 0x10b;
    if (fn_8018E4A4(&self->unk4)) flags |= 3;
    if (fn_8018E4F0(&self->unk4)) flags |= 0x204;
    if (fn_8018E40C(&self->unk4)) flags |= 0x40;
    if (fn_8018E53C(&self->unk4)) flags |= 0x7000;
    void* tmp18 = self->unk8;
    void* anim = fn_801B0B40(allocator, &tmp20, &tmp18, flags | 0x10b, 1, fn_801B0A28);
    if (arg2) {
        fn_801AAFF0(anim, arg2);
        fn_801AB014(anim, arg2);
    }
    void* model = __nw__FUlQ25Heaps8HeapType(0x20, heap);
    if (model) {
        void* tmp14 = self->unk8;
        void* tmp10 = self->unk4;
        model = __ct__16gfModelAnimationFd(model, &tmp10, &tmp14, 1, arg3, heap);
    }
    gfModelAnimation::bind((nw4r::g3d::ScnMdl*)anim, (gfModelAnimation*)model);
    self->unkC = anim;
    f32 frame = lbl_805A2200;
    self->unk10 = anim;
    self->unk14 = model;
    setFrame__16gfModelAnimationFd(model, frame);
}