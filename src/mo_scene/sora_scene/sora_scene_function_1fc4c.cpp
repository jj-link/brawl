#pragma force_active on

struct Base5C {
    char pad[0x5c];
};

class Obj : public Base5C {
public:
    virtual ~Obj();
};

extern "C" {
void exit__6gfTaskFv(void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void fn_803F0D4C(void*, void (*)(void*, int));
void fn_8000D7B8(void*);
void __dt__9gfArchiveFv(void*, int);
void startKeepScreen__17gfKeepFrameBufferFv(void*);
extern void* g_gfSceneRoot;
extern char* g_gfApplication;
extern void* lbl_1_bss_1790;
}

struct Self {
    char pad[0x34];
    void* t34;
    void* t38;
    void* t3C;
    char* handles;
    int pad44;
    Obj* o48;
    Obj* o4C;
    void* buf50;
    void* arc54;
};

extern "C" int fn_1_1FC4C(Self* self) {
    if (lbl_1_bss_1790 != 0) {
        exit__6gfTaskFv(lbl_1_bss_1790);
        lbl_1_bss_1790 = 0;
    }
    if (self->handles != 0) {
        for (int i = 0; i < 3; i++) {
            free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(self->handles + i * 4));
            release__14gfFileIOHandleFv(self->handles + i * 4);
        }
        fn_803F0D4C(self->handles, __dt__14gfFileIOHandleFv);
        self->handles = 0;
    }
    if (self->o48 != 0) {
        delete self->o48;
        self->o48 = 0;
    }
    if (self->o4C != 0) {
        delete self->o4C;
        self->o4C = 0;
    }
    fn_8000D7B8(g_gfSceneRoot);
    if (self->t34 != 0) {
        exit__6gfTaskFv(self->t34);
        self->t34 = 0;
    }
    if (self->t38 != 0) {
        exit__6gfTaskFv(self->t38);
        self->t38 = 0;
    }
    if (self->t3C != 0) {
        exit__6gfTaskFv(self->t3C);
        self->t3C = 0;
    }
    if (self->arc54 != 0) {
        __dt__9gfArchiveFv(self->arc54, 1);
        self->arc54 = 0;
    }
    if (self->buf50 != 0) {
        free__13gfHeapManagerFPv(self->buf50);
        self->buf50 = 0;
    }
    startKeepScreen__17gfKeepFrameBufferFv(g_gfApplication + 0xd0);
    return 0;
}
