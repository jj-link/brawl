#pragma force_active on
extern "C" {
void startKeepScreen__17gfKeepFrameBufferFv(void*);
void exit__6gfTaskFv(void*);
void free__13gfHeapManagerFPv(void*);
void __dl__FPv(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
extern char* g_gfApplication;
}

struct Scene {
    char pad[0x35C];
    void* f35c;
    void* f360;
    void* f364;
    void* f368;
    void* f36c;
    void* f370;
    void* f374;
    void* f378;
    void* f37c;
    void* f380;
    void* f384;
    void* f388;
    void* f38c;
    unsigned int handles[10];
};

extern "C" int fn_1_C6A0(Scene* self) {
    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);

    if (self->f38c) {
        exit__6gfTaskFv(self->f38c);
        self->f38c = 0;
    }
    if (self->f35c) {
        exit__6gfTaskFv(self->f35c);
        self->f35c = 0;
    }
    if (self->f360) {
        free__13gfHeapManagerFPv(self->f360);
        self->f360 = 0;
    }
    if (self->f370) {
        free__13gfHeapManagerFPv(self->f370);
        self->f370 = 0;
    }
    if (self->f364) {
        free__13gfHeapManagerFPv(self->f364);
        self->f364 = 0;
    }
    if (self->f368) {
        free__13gfHeapManagerFPv(self->f368);
        self->f368 = 0;
    }
    if (self->f380) {
        free__13gfHeapManagerFPv(self->f380);
        self->f380 = 0;
    }
    if (self->f36c) {
        free__13gfHeapManagerFPv(self->f36c);
        self->f36c = 0;
    }
    if (self->f374) {
        __dl__FPv(self->f374);
        self->f374 = 0;
    }
    if (self->f378) {
        __dl__FPv(self->f378);
        self->f378 = 0;
    }
    if (self->f384) {
        __dl__FPv(self->f384);
        self->f384 = 0;
    }
    if (self->f37c) {
        __dl__FPv(self->f37c);
        self->f37c = 0;
    }

    for (int i = 0; i < 10; ++i) {
        cancelRequest__14gfFileIOHandleFv(&self->handles[i]);
    }
    return 0;
}
