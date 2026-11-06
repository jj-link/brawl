#pragma force_active on
struct Result {
    unsigned int unused;
    void* value;
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Result* slot1(int);
};
struct Context {
    unsigned char padding[0x28];
    Object_vptr_0* provider;
};
extern "C" int fn_80136A7C(void*, int);
extern "C" int fn_27_2A690(Context* context, int kind, int arg) {
    if (kind == 0) {
        return fn_80136A7C(context->provider->slot1(arg)->value, 1);
    } else if (kind == 1) {
        return fn_80136A7C(context->provider->slot1(arg)->value, 0);
    } else if (kind == 2) {
        return fn_80136A7C(context->provider->slot1(arg)->value, 3);
    }
    return 0;
}