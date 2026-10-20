#pragma force_active on
struct fn_27_5A11C_Obj {
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
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
    virtual void vf16();
    virtual void vf17();
    unsigned char pad[0x7E - 4];
    unsigned char b7E;
    unsigned char b7F;
    unsigned char b80;
    unsigned char b81;
    unsigned char b82;
    unsigned char b83;
    unsigned char b84;
    unsigned char b85;
};

extern "C" void fn_27_5A11C(fn_27_5A11C_Obj* obj) {
    obj->vf16();
    obj->vf17();
    obj->b80 = 0xFE;
    obj->b7E = 0xFE;
    obj->b81 = 0;
    obj->b7F = 0;
    obj->b84 = 0xFE;
    obj->b82 = 0xFE;
    obj->b85 = 0;
    obj->b83 = 0;
}
