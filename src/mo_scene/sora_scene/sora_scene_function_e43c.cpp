#pragma force_active on
extern "C" {
void startKeepScreen__17gfKeepFrameBufferFv(void*);
void exit__6gfTaskFv(void*);
void free__13gfHeapManagerFPv(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
extern char* g_gfApplication;
}

struct Self {
    char pad0[0x360];
    void* f360;
    void* f364;
    void* f368;
    void* f36c;
    char pad1[0x434 - 0x370];
    unsigned int handles[3];
};

extern "C" int fn_1_E43C(Self* self) {
    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xD0);

    if (self->f36c) {
        exit__6gfTaskFv(self->f36c);
        self->f36c = 0;
    }
    if (self->f360) {
        exit__6gfTaskFv(self->f360);
        self->f360 = 0;
    }
    if (self->f364) {
        free__13gfHeapManagerFPv(self->f364);
        self->f364 = 0;
    }
    if (self->f368) {
        free__13gfHeapManagerFPv(self->f368);
        self->f368 = 0;
    }

    for (int i = 0; i < 3; ++i) {
        cancelRequest__14gfFileIOHandleFv(&self->handles[i]);
    }
    return 0;
}
