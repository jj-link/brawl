#pragma force_active on
class Class_804645B0 {
public:
    virtual void fn_8015D358();
    virtual int fn_8015CF94();
    virtual void fn_8015D00C();
    virtual void fn_8015D05C();
    virtual void fn_8015D0E4();
    virtual void fn_8015CC00();
    virtual void fn_8015CC04();
    virtual void fn_8015D350();
    virtual void fn_8015D338();
    virtual unsigned long long fn_8015D328();
};
struct Owner { char pad[0x60]; Class_804645B0* obj; };
struct Vec { float x, y; };
union Bits { unsigned long long value; Vec vec; };
extern "C" void fn_801342C8(Owner* self, Vec* out) {
    if (self->obj->fn_8015CF94() == 2) {
        Bits result;
        result.value = self->obj->fn_8015D328();
        *out = result.vec;
    }
}