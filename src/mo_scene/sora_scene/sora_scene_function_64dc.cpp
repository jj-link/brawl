#include <types.h>
#pragma force_active on

extern "C" {
void startKeepScreen__17gfKeepFrameBufferFv(void*);
void exit__6gfTaskFv(void*);
void free__13gfHeapManagerFPv(void*);
void __dt__9gfArchiveFv(void*, int);
void fn_1_406C(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);
extern u8* g_gfApplication;
}

struct HeapMgr {
    void* f0;
    void* f4;
};

struct Self {
    u8 pad0[0x35C];
    HeapMgr* f35C;
    u8 pad1[0x1C];
    void* f37C;
    void* f380;
};

extern "C" s32 fn_1_64DC(Self* self) {
    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
    if (self->f35C == nullptr) {
        return 0;
    }
    exit__6gfTaskFv(self->f35C->f0);
    if (self->f35C->f4 != nullptr) {
        exit__6gfTaskFv(self->f35C->f4);
    }
    __dt__9gfArchiveFv(self->f37C, 1);
    self->f37C = nullptr;
    void* h = self->f380;
    if (h) {
        if (h) {
            fn_1_406C(h);
            __dt__14gfFileIOHandleFv(h, -1);
            __dl__FPv(h);
        }
        self->f380 = nullptr;
    }
    free__13gfHeapManagerFPv(self->f35C);
    self->f35C = nullptr;
    return 0;
}
