#pragma force_active on
class Result {
public:
    virtual void unused0();
    virtual void unused1();
    virtual int get();
};

class Provider {
public:
    virtual void unused0();
    virtual void unused1();
    virtual Result* get();
};

struct Object {
    char padding[0xF60];
    Provider provider;
};

extern "C" int fn_27_28F4DC(Object* object) {
    return object->provider.get()->get();
}
