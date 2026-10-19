#pragma force_active on
extern "C" {
void startKeepScreen__17gfKeepFrameBufferFv(void*);
void exit__6gfTaskFv(void*);
void free__13gfHeapManagerFPv(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
extern char* g_gfApplication;
}

struct TaskPair {
    void* task0;
    void* task4;
};

struct Scene {
    char pad[0x398];
    TaskPair* f398;
    char pad2[4];
    char f3a0;
};

extern "C" int fn_1_5230(Scene* self) {
    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);

    if (self->f398 == 0) {
        return 0;
    }
    exit__6gfTaskFv(self->f398->task0);
    exit__6gfTaskFv(self->f398->task4);
    free__13gfHeapManagerFPv(self->f398);
    self->f398 = 0;
    cancelRequest__14gfFileIOHandleFv(&self->f3a0);
    return 0;
}
