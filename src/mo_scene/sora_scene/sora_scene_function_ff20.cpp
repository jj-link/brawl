#pragma force_active on

extern "C" {
void __dt__9gfArchiveFv(void*, int);
void fn_24_438(void*);
void fn_24_8B8(void*);
void fn_24_D84(void*);
void fn_24_12DC(void*);
void exit__6gfTaskFv(void*);
}

class SceneObjBase {
public:
    char pad[0x200];
};

class SceneObj : public SceneObjBase {
public:
    virtual void destroy(int);
};

struct Scene {
    char pad0[8];
    void* f8;
    void* fC;
    void* f10;
    void* f14;
    void* f18;
    SceneObj* f1C;
};

extern "C" void fn_1_FF20(Scene* self) {
    __dt__9gfArchiveFv(self->f8, 1);
    self->f8 = 0;
    if (self->fC) {
        fn_24_438(self->fC);
        exit__6gfTaskFv(self->fC);
        self->fC = 0;
    }
    if (self->f10) {
        fn_24_8B8(self->f10);
        exit__6gfTaskFv(self->f10);
        self->f10 = 0;
    }
    if (self->f14) {
        fn_24_D84(self->f14);
        exit__6gfTaskFv(self->f14);
        self->f14 = 0;
    }
    if (self->f18) {
        fn_24_12DC(self->f18);
        exit__6gfTaskFv(self->f18);
        self->f18 = 0;
    }
    if (self->f1C) {
        self->f1C->destroy(1);
    }
    self->f1C = 0;
}
