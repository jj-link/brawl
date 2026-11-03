#pragma force_active on
struct Result {
    unsigned int unused;
    void* value;
};
class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual Result* fn_27_FF68();
};
struct Context {
    unsigned char padding[0x28];
    Class_C80* provider;
};
extern "C" int fn_80134344(void*, unsigned int);
extern "C" int fn_27_27FF4(Context* __restrict context) {
    int flags = 0;
    Result* result = context->provider->fn_27_FF68();
    if (fn_80134344(result->value, 0)) flags |= 1;
    if (fn_80134344(result->value, 3)) flags |= 8;
    if (fn_80134344(result->value, 2)) flags |= 4;
    if (fn_80134344(result->value, 1)) flags |= 2;
    return flags;
}