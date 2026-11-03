#pragma force_active on
struct Pair { unsigned int a; unsigned int b; };
class Class_1F0C0 {
public:
    virtual void fn_27_EB12C();
    virtual Pair* fn_27_EA8F0(int);
    virtual void fn_27_EA900();
    virtual int fn_27_CB588();
};
extern "C" void fn_27_EB7A4(Class_1F0C0* self, int start, const Pair* value, unsigned int countArg) {
    int count = static_cast<int>(countArg);
    if (count + start >= self->fn_27_CB588())
        count = self->fn_27_CB588() - start;
    for (int i = 0; i < count; ++i) {
        Pair* dst = self->fn_27_EA8F0(start + i);
        dst->a = value->a;
        dst->b = value->b;
    }
}