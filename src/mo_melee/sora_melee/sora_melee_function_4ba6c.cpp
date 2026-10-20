#pragma force_active on
struct Result {
    unsigned int data[3];
};

class Object {
public:
    unsigned char padding[0x30];

    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual Result get();
};

extern "C" Object* fn_27_36028(void*, unsigned int, unsigned int);

extern "C" Result fn_27_4BA6C(void* self, unsigned int value) {
    return fn_27_36028(static_cast<unsigned char*>(self) + 0xC0, value, 0)->get();
}
