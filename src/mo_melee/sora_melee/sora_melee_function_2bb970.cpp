#pragma force_active on
class soSubObj {
public:
    virtual void f0();
    virtual void f1();
};

extern "C" void fn_27_2BB970(void* p) {
    soSubObj* s = (soSubObj*)((char*)p + 0x10);
    s->f1();
}
