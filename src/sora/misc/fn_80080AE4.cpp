#pragma force_active on
extern "C" {

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void* ptr, unsigned short type, int align);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct DtorObj {
    void* vtable;
    unsigned short type;
};

void* fn_80080AE4(void* arg0, int arg1) {
    if (arg0 != 0 && arg1 > 0) {
        DtorObj* d = (DtorObj*)arg0;
        lbl_805A0EB8->free(arg0, d->type, 0x18);
    }
    return arg0;
}

}
