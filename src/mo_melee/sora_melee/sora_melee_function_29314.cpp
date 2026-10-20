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

struct Context {
    unsigned char padding[0x28];
    Provider* provider;
};

extern "C" void fn_80134534(void*, int);

extern "C" void fn_27_29314(Context* __restrict context) {
    fn_80134534(context->provider->get()->value, 1);
}
