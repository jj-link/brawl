#pragma force_active on
extern "C" {
extern const float lbl_107_rodata_58;

class VA {
public:
    virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
    virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
    virtual void v8() = 0; virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
    virtual void v12() = 0;
    virtual void setX(unsigned int, float) = 0;
};

class VB {
public:
    virtual void v0() = 0; virtual void v1() = 0; virtual void v2() = 0; virtual void v3() = 0;
    virtual void v4() = 0; virtual void v5() = 0; virtual void v6() = 0; virtual void v7() = 0;
    virtual void v8() = 0; virtual void v9() = 0; virtual void v10() = 0; virtual void v11() = 0;
    virtual void v12() = 0; virtual void v13() = 0; virtual void v14() = 0; virtual void v15() = 0;
    virtual void v16() = 0; virtual void v17() = 0; virtual void v18() = 0; virtual void v19() = 0;
    virtual void v20() = 0; virtual void v21() = 0;
    virtual float getF() = 0;
};

void fn_107_12908(void*, char* obj) {
    char* a = *(char**)(obj + 0xd8);
    VA* r31 = *(VA**)(a + 0x64);
    VB* b = *(VB**)(a + 0xc);
    float f = b->getF();
    float g = lbl_107_rodata_58 * f;
    r31->setX(0x11000012, g);
}
}
