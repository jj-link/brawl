#pragma force_active on

typedef unsigned char u8;
typedef signed int s32;

struct HeapMgr {
    void* f0;
    void* f4;
};

struct Scene {
    u8 pad0[0x35C];
    HeapMgr* f35C;
    u8 pad360[0x38];
    void* f398;
    void* f39C;
};

extern "C" {
void startKeepScreen__17gfKeepFrameBufferFv(void*);
extern u8* g_gfApplication;
void exit__6gfTaskFv(void*);
void __dt__9gfArchiveFv(void*, int);
void fn_1_406C(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);
void free__13gfHeapManagerFPv(void*);
}

extern "C" s32 fn_1_90E0(Scene* self) {
    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);
    if (self->f35C == 0) {
        return 0;
    }
    exit__6gfTaskFv(self->f35C->f0);
    exit__6gfTaskFv(self->f35C->f4);
    if (self->f398 != 0) {
        __dt__9gfArchiveFv(self->f398, 1);
        self->f398 = 0;
    }
    void* h = self->f39C;
    if (h != 0) {
        if (h != 0) {
            fn_1_406C(h);
            __dt__14gfFileIOHandleFv(h, -1);
            __dl__FPv(h);
        }
        self->f39C = 0;
    }
    free__13gfHeapManagerFPv(self->f35C);
    self->f35C = 0;
    return 0;
}
