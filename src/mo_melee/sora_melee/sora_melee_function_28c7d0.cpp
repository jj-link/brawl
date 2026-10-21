#pragma force_active on
class Work {
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
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void setFlag(unsigned int);
};

struct Object {
    char padding[0x2AAC];
    Work work;
};

extern "C" void fn_27_28C7D0(Object* object) {
    object->work.setFlag(0x12000006);
}
