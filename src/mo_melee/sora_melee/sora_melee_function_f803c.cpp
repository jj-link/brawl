#pragma force_active on
struct Factory {
    virtual void f0();
    virtual int* alloc(int);
};

extern "C" void fn_27_F803C(Factory* factory, int* src, int kind) {
    int* p = factory->alloc(kind);
    *p = *src;
}
