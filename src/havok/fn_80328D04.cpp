#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);

class Ctx {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    char pad[0xC];
    unsigned int f10;
    unsigned int pad14;
    unsigned int f18;
};

class Heap {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void*, int, int);
};

extern Ctx* lbl_805A0EC8;
extern Heap* lbl_805A0EB8;

struct Arg {
    void* data;
    int size;
    unsigned int raw;
    unsigned int f0C;

    bool isOwned() const { return (raw & 0x80000000) == 0; }
    void dealloc() { fn_8027EABC(lbl_805A0EC8, data, raw & 0x3FFFFFFF, 0x15); }
    void destroy() {
        unsigned int t = f0C;
        Ctx* c = lbl_805A0EC8;
        c->f10 = t;
        if (t == c->f18) {
            c->vf4();
        }
        if (this && isOwned())
            dealloc();
    }
};

extern "C" {
void* __dt__14Class_80328D04Fv(Arg* arg0, int arg1) {
    if (arg0) {
        arg0->destroy();
        if (arg1 > 0) {
            lbl_805A0EB8->free(arg0, 0x10, 0x15);
        }
    }
    return arg0;
}
}
