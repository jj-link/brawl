#pragma force_active on
typedef unsigned int u32;

struct Interface {
    virtual void* call();
    virtual void* call2(void*);
    virtual void* call3(void*);
};

extern "C" void fn_27_FCF5C(void* object, u32* output, void* input) {
    void* result = static_cast<Interface*>(object)->call2(input);
    *static_cast<u32*>(result) = *output;
}
