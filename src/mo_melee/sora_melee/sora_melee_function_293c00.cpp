#pragma force_active on
typedef unsigned int u32;

class Object {
public:
    virtual void f0();
    virtual u32* invoke(void*);
};

extern "C" u32* fn_27_293C00(Object* self, u32* out, void* arg) {
    u32* result = self->invoke(arg);
    *result = *out;
    return result;
}
