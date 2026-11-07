#pragma force_active on

struct Pair {
    unsigned int a;
    unsigned int b;
};

class Class_20AB0 {
public:
    virtual void fn_27_EE820();
    virtual Pair* fn_27_EE1A4(int index);
    virtual void fn_27_EE1B4();
    virtual int fn_27_D2F9C();
};

extern "C" void fn_27_EE72C(Class_20AB0* self, int start, const Pair* value,
                            unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->fn_27_D2F9C())
        count = self->fn_27_D2F9C() - start;

    for (int i = 0; i < count; ++i) {
        Pair* dst = self->fn_27_EE1A4(start + i);
        dst->a = value->a;
        dst->b = value->b;
    }
}
