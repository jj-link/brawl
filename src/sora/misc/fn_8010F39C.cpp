#pragma force_active on

struct Base10 {
    char pad[0x10];
};

class Obj : public Base10 {
public:
    virtual ~Obj();
};

struct Flags8 {
    unsigned char b0 : 1;
    unsigned char rest : 7;
};

extern "C" {
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void fn_8000D7B8(void*);
void cancelRequest__14gfFileIOHandleFv(void*);
void free__13gfHeapManagerFPv(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dl__FPv(void*);
void fn_800FC3E4(void*, int);
extern void* g_gfSceneRoot;
}

struct Handle {
    int x;
};

struct Self {
    Flags8 flags;
    char pad1[3];
    void* g3d;
    void* buf8;
    void* bufC;
    Obj* obj;
    Handle handles[2];
    ~Self() {
        if (obj != 0) {
            delete obj;
            obj = 0;
        }
        if (g3d != 0) {
            Destroy__Q34nw4r3g3d6G3dObjFv(g3d);
            g3d = 0;
        }
        fn_8000D7B8(g_gfSceneRoot);
        if (buf8 != 0) {
            free__13gfHeapManagerFPv(buf8);
            buf8 = 0;
        }
        if (bufC != 0) {
            free__13gfHeapManagerFPv(bufC);
            bufC = 0;
        }
        for (int i = 0; i < 2; i++) {
            cancelRequest__14gfFileIOHandleFv(&handles[i]);
        }
        flags.b0 = 0;
        __destroy_arr(handles, fn_800FC3E4, 4, 2);
    }
};

extern "C" {
extern Self* lbl_805A0350;
}

extern "C" void fn_8010F39C() {
    delete lbl_805A0350;
    lbl_805A0350 = 0;
}
