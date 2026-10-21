#pragma force_active on

class soObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(float);
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();

    float _data[25];
    float _68;
    float _6c;
    float _70;
    float _74;
};

extern "C" void fn_27_25310(soObj*, float*);
extern const float lbl_27_rodata_38C;

extern "C" void fn_27_2362C(soObj* obj, float* f) {
    fn_27_25310(obj, f);
    obj->vf12();
    obj->vf16();

    float d, c, a, b;
    a = f[0];
    b = lbl_27_rodata_38C;
    c = f[1];
    d = f[2];

    obj->_68 = b;
    obj->_6c = a;
    obj->_70 = c;
    obj->_74 = d;
}
