#pragma force_active on
class WorkModule {
public:
    virtual void f00();
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void setFlag(bool value, unsigned int index);
};

struct BaseItem {
    char padding[0x2AAC];
    WorkModule work;
};

extern "C" void setVanishMode__8BaseItemFb(BaseItem* item, bool value) {
    item->work.setFlag(value, 0x12000006);
}
