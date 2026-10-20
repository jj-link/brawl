#pragma force_active on
class WorkModule {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual int getInt(unsigned int);
    virtual void setInt(int, unsigned int);
};

struct ModuleAccesser {
    unsigned char padding[0x64];
    WorkModule* work;
};

struct Owner {
    unsigned char padding[0xd8];
    ModuleAccesser* modules;
};

struct Context {
    unsigned char padding[0x60];
    Owner* owner;
};

extern "C" int fn_27_2999AC(void*, Context* context) {
    WorkModule* work = context->owner->modules->work;
    int value = work->getInt(0x10000000);
    if (value > 0) {
        --value;
        work->setInt(value, 0x10000000);
    }
    return value;
}
