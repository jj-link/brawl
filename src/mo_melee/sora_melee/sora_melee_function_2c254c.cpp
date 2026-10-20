#pragma force_active on
extern "C" int fn_27_2C1F54(void*);

struct soSpriteElem {
    int a;
    int b;
    int c;
};

class soWorkBase {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual unsigned int vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
};

extern "C" soSpriteElem* fn_27_2C254C(soWorkBase* self) {
    int idx = fn_27_2C1F54(self);
    if (self->vf4() != 1 && idx >= 0) {
        self->vf13();
    }
    soSpriteElem* base = (soSpriteElem*)self;
    return base + idx + 1;
}
