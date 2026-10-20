#pragma force_active on
extern "C" const float lbl_27_rodata_1F08[2];

class Object {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual int calculate(float, float);
    virtual void v15();
    virtual void apply(int, int);
};

extern "C" void fn_27_15412C(Object* self, int index, float value) {
    self->apply(self->calculate(value, lbl_27_rodata_1F08[0]), index);
}
