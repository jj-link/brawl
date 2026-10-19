#pragma force_active on
typedef unsigned char u8;

struct MenuObjectBase {
    u8 padding[0x5C];
};

class MenuObject : public MenuObjectBase {
public:
    virtual void destroy(int);
};

struct AdvEndingTask {
    u8 pad000[0x40];
    void* handle40;
    void* handle44;
    void* handle48;
    void* f4C;
    void* f50;
    void* f54;
    void* f58;
    MenuObject* f5C;
    MenuObject* f60[2];
    MenuObject* f68;
    MenuObject* f6C;
    MenuObject** f70;
    void* f74;
    void* f78;
    u8 pad07C[0x2C];
    int count;
    u8 pad0AC[0x14];
    void* fC0;
};

extern "C" {
void exit__6gfTaskFv(void*);
void fn_800B8EDC(void*, void*);
void fn_800B8A0C(void*, int);
void fn_8007EA78(void*, int);
void __dla__FPv(void*);
void* getBuffer__14gfFileIOHandleCFv(const void*);
void free__13gfHeapManagerFPv(void*);
void release__14gfFileIOHandleFv(void*);
void fn_8018E808(void*);

void fn_37_E04(AdvEndingTask* self) {
    exit__6gfTaskFv(self->f50);
    self->f50 = 0;
    exit__6gfTaskFv(self->f54);
    self->f54 = 0;
    exit__6gfTaskFv(self->f58);
    self->f58 = 0;
    if (self->f5C) {
        self->f5C->destroy(1);
    }
    self->f5C = 0;

    for (int i = 0; i < 2; i++) {
        if (self->f60[i]) {
            self->f60[i]->destroy(1);
        }
        self->f60[i] = 0;
    }

    if (self->f68) {
        self->f68->destroy(1);
    }
    self->f68 = 0;
    if (self->f6C) {
        self->f6C->destroy(1);
    }
    self->f6C = 0;

    for (int i = 0; i < self->count; i++) {
        fn_800B8EDC(self->f74, self->f70[i]);
        if (self->f70[i]) {
            self->f70[i]->destroy(1);
        }
        self->f70[i] = 0;
    }

    __dla__FPv(self->f70);
    fn_800B8A0C(self->f74, 1);
    self->f74 = 0;
    fn_8007EA78(self->f78, 1);
    self->f78 = 0;
    __dla__FPv(self->fC0);
    self->fC0 = 0;

    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(&self->handle40));
    release__14gfFileIOHandleFv(&self->handle40);
    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(&self->handle44));
    release__14gfFileIOHandleFv(&self->handle44);
    free__13gfHeapManagerFPv(getBuffer__14gfFileIOHandleCFv(&self->handle48));
    release__14gfFileIOHandleFv(&self->handle48);
    fn_8018E808(&self->f4C);
}
}
