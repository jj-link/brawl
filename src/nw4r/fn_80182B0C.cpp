#pragma force_active on
class Class_80465690 {
public:
    virtual void fn_80182894();
    virtual void fn_80183620();
    virtual void fn_80182CA4();
    virtual void fn_80182F9C();
    virtual void fn_80183020();
    virtual void fn_80183024();
    virtual void fn_801830B0();
    virtual void fn_80182AD4();
    virtual void fn_80182AE0();
    virtual void fn_80182AE4();
    virtual void fn_80182B0C();
    virtual void fn_80182B34();
    virtual void fn_80182B3C(int a, int b);
};

extern "C" void fn_80182B0C(Class_80465690* self, int a, int b) {
    switch (a) {
    case 0x10:
        *(unsigned char*)((char*)self + 0xB4) = (unsigned char)b;
        return;
    }
    self->fn_80182B3C(a, b);
}