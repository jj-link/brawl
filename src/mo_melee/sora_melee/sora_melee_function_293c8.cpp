#pragma force_active on
struct Result {
    unsigned int unused;
    void* value;
};

class Provider {
public:
    virtual void unused();
    virtual Result* get();
};

struct Object {
    unsigned char padding[0x28];
    Provider* provider;
};

extern "C" void fn_80134534(void*, int);

extern "C" void fn_27_293C8(Object* __restrict object) {
    fn_80134534(object->provider->get()->value, 7);
}
