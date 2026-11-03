#pragma force_active on

struct Pair {
    unsigned char a;
    unsigned int b;
};

class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual Pair* fn_27_FF68(int index);
    virtual void fn_27_FFAC();
    virtual int fn_27_FFF0();
};

extern "C" void fn_27_123B20(Class_C80* self, int start, const Pair* value,
                            unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->fn_27_FFF0())
        count = self->fn_27_FFF0() - start;

    for (int i = 0; i < count; ++i) {
        Pair* dst = self->fn_27_FF68(start + i);
        dst->a = value->a;
        dst->b = value->b;
    }
}
