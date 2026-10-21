#pragma force_active on

struct Vec3 {
    float x;
    float y;
    float z;
};

class Inner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 getPos();
};

class Mid {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void setU(unsigned int a, unsigned int b);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void setF(unsigned int a, float b);
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void setP(unsigned int a, void* b);
};

struct Holder {
    char pad0[0xC];
    Inner* inner;
    char pad1[0x64 - 0x10];
    Mid* mid;
};

struct Owner {
    char pad[0xD8];
    Holder* holder;
};

extern "C" void fn_27_19124C(void* arg, Owner* obj) {
    const Vec3& p = obj->holder->inner->getPos();
    obj->holder->mid->setF(0x21000004, p.x);
    obj->holder->mid->setF(0x21000005, p.y);
    obj->holder->mid->setU(0x29, 0x20000000);
    obj->holder->mid->setP(0x12000001, obj->holder);
}
