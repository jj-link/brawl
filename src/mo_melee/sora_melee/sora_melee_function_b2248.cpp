#pragma force_active on
extern "C" void fn_27_B16D0(void* self, void* a, int b, int c);

class VA {
public:
    virtual void v0();
    virtual void* v1(int idx, void* p);
    virtual void v2();
    virtual int v3();
};

class VB {
public:
    virtual void v0();
    virtual void v1();
    virtual void* v2();
};

struct Inner { char pad[0xC0]; VB* unkC0; };
struct Mid { char pad[0xD8]; Inner* unkD8; };
struct Self { char pad0[0x10]; Mid* unk10; char pad1[4]; VA* unk18; };

extern "C" void fn_27_B2248(Self* self, int* arg1) {
    int count = self->unk18->v3();
    VB* b;
    void* obj;
    int off;
    int i;
    i = 0;
    off = 0;
    while (i < count) {
        Inner* d = self->unk10->unkD8;
        b = d->unkC0;
        obj = self->unk18->v1(i, d);
        void* p = b->v2();
        fn_27_B16D0(obj, p, *arg1 + off, 0);
        off += 0x14;
        i += 1;
    }
}
