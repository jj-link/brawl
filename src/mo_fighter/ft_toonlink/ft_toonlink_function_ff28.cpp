#pragma force_active on
class Obj {
public:
    virtual ~Obj();
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};

class Holder {
public:
    char pad[0x34];
    Obj* obj;
};

extern "C" int fn_121_FF28(char* self) {
    Holder* h = *(Holder**)(self + 0xd8);
    h->obj->f3();
    return 0;
}
