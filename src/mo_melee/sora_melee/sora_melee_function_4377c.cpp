#pragma force_active on
struct Vt {
    virtual void* f0();
    virtual void* f1(void* a);
    virtual void* f2();
    virtual void* f3();
};

extern "C" void fn_27_42078(void* a, void* b, void* c, void* d);

extern "C" void fn_27_4377C(unsigned char* self, void* a1, void* a2, void* a3) {
    Vt* obj = *(Vt**)(self + 0x58);
    void* r = obj->f1(a3);
    fn_27_42078(r, *(void**)(self + 0x30), a1, a2);
}
