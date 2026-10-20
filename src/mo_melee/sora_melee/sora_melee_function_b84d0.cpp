#pragma force_active on
class BaseItem;

namespace itValueAccesser {
    enum ParamInt { PARAM_INT_DUMMY = 0 };
}

class BaseItem {
public:
    int getParam(itValueAccesser::ParamInt param);
};

struct Payload {
    int pad;
    BaseItem* item;
};

class Inner {
public:
    virtual void v0();
    virtual Payload* v3(void* arg);
};

class Outer {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual bool v16(void* arg);

    char pad[0x34];
    Inner* m_inner;
};

extern "C" {
int fn_27_B84D0(Outer* self, void* arg) {
    if (self->v16(arg) == true) {
        return self->m_inner->v3(arg)->item->getParam((itValueAccesser::ParamInt)0x5b6a);
    }
    return 0;
}
}
