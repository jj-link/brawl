#pragma force_active on
class Work {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual int getInt(unsigned int index);
    virtual void setInt(int value, unsigned int index);
};

struct Modules {
    unsigned char padding[0x64];
    Work* work;
};

struct Accessor {
    unsigned char padding[0xD8];
    Modules* modules;
};

struct Context {
    unsigned char padding[0x60];
    Accessor* accessor;
};

extern "C" int fn_27_299534(void*, Context* context) {
    Work* work = context->accessor->modules->work;
    int value = work->getInt(0x10000000);
    if (value > 0) {
        --value;
        work->setInt(value, 0x10000000);
    }
    return value;
}
