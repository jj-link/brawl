#include <gf/gf_heap_manager.h>
#include <gf/gf_file_io_handle.h>
#pragma force_active on

extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
extern char lbl_80455C9C[];
}

struct FnTask {
    char pad0[0x3C];
    char* unk3C;
    int unk40;
    void* unk44;
    void* unk48;
    void* unk4C;
    char pad50[0x1A8 - 0x50];
    gfFileIOHandle handle;
};

extern "C" FnTask* fn_800AFFE8(FnTask* self, int flag) {
    if (self) {
        self->unk3C = lbl_80455C9C;
        if (self->unk40 == 0) {
            if (self->unk44) {
                gfHeapManager::free(self->unk44);
            }
        }
        if (self->unk48) {
            Destroy__Q34nw4r3g3d6G3dObjFv(self->unk48);
            self->unk48 = 0;
        }
        if (self->unk4C) {
            Destroy__Q34nw4r3g3d6G3dObjFv(self->unk4C);
            self->unk4C = 0;
        }
        cancelRequest__14gfFileIOHandleFv(&self->handle);
        __dt__14gfFileIOHandleFv(&self->handle, -1);
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
