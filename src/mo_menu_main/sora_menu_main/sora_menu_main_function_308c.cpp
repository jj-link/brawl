#pragma force_active on
extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(void* self, const char* name, int heap, int a, int b);
void release__14gfFileIOHandleFv(void*);
int sprintf(char*, const char*, ...);
}
extern char lbl_2_data_680[];

struct Mgr {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12();
    virtual void rel(void*);
};
struct Info { int a; int b; int name; };

struct Obj {
    int f0, f4;
    void* f8;
    Mgr* fC;
    int f10, f14;
    float f18, f1C, f20;
    int pad[3];
    Info* f30;
    int f34;
    char h38[0x1c];
    int f54, f58;
    int f5c, f60, f64;
};

extern "C" void fn_2_308C(Obj* self, int* arg1, Mgr* arg2) {
    void* o = self->f8;
    self->f4 = 0;
    self->f0 = 0;
    self->f20 = 0.0f;
    self->f1C = 0.0f;
    self->f18 = 0.0f;
    self->fC = arg2;
    self->f30 = (Info*)arg1;
    if (o) {
        arg2->rel(o);
        Destroy__Q34nw4r3g3d6G3dObjFv(self->f8);
        self->f8 = 0;
        self->f34 = 1;
        self->f60 = 0;
        self->f64 = 0;
    }
    self->f54 = *arg1;
    switch (self->f34) {
    case 0: {
        char buf[0x40];
        release__14gfFileIOHandleFv(self->h38);
        int v = self->f54;
        sprintf(buf, lbl_2_data_680, self->f30->name);
        self->f58 = v;
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self->h38, buf, 0x2b, 0, 0);
        self->f34 = 4;
        break;
    }
    case 5: {
        char buf2[0x40];
        release__14gfFileIOHandleFv(self->h38);
        int v = self->f54;
        sprintf(buf2, lbl_2_data_680, self->f30->name);
        self->f58 = v;
        readRequest__14gfFileIOHandleFPCcQ25Heaps8HeapTypeii(self->h38, buf2, 0x2b, 0, 0);
        self->f34 = 4;
        break;
    }
    }
}
