#pragma force_active on
class fn27Base {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual int getCount();
};

extern "C" void* fn_27_C81F4(void* self, int flag);
extern "C" void fn_27_C84A0(void* self, void* value);

extern "C" void fn_27_C7D28(fn27Base* self) {
    int count = self->getCount();
    void* value = fn_27_C81F4(self, count - 1);
    fn_27_C84A0(self, value);
}
