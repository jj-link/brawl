#pragma force_active on
struct Frame {
    int a;
    int b;
    void* p;
    void* obj;
};

class VIface {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual short f9();
};

extern "C" {
extern char lbl_41_data_15BE8[];
extern char lbl_41_data_3E50[];
void fn_41_2D038(void* self, int zero, short v, void* args, void* tbl);

void* fn_41_55660(void* self, char* other) {
    *(void**)self = lbl_41_data_15BE8;
    char* o = *(char**)(other + 0xd8);
    void* c0 = *(void**)(o + 0xc0);
    Frame f;
    f.a = 1;
    f.b = 0x27;
    f.p = &f.a;
    f.obj = c0;
    char* o2 = *(char**)(other + 0xd8);
    char* sub = *(char**)(o2 + 0x80);
    short r = ((VIface*)(sub + 8))->f9();
    fn_41_2D038((char*)self + 4, 0, r, &f.p, lbl_41_data_3E50);
    return self;
}
}
