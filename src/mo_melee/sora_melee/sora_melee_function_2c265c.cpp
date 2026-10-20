#pragma force_active on
extern "C" int fn_27_2C1F54(void*, int);
extern "C" void fn_27_2C2200(void*, int);

class soBase {
public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int getCount();
};

extern "C" void fn_27_2C265C(soBase* self) {
    int value = fn_27_2C1F54(self, self->getCount() - 1);
    fn_27_2C2200(self, value);
}
