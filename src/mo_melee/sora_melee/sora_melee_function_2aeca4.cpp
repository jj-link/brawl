#pragma force_active on
extern "C" int fn_27_2AD208(void* self, int flag);
extern "C" void fn_27_2AD4B4(void* self, int value);

class soSpriteBase {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual int getCount();
};

extern "C" void fn_27_2AECA4(soSpriteBase* self) {
    int count = self->getCount();
    int result = fn_27_2AD208(self, count - 1);
    fn_27_2AD4B4(self, result);
}
