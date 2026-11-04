#pragma force_active on

struct Byte {
    unsigned char a;
};

class Class_C80 {
public:
    virtual void fn_27_FEE4();
    virtual Byte* fn_27_FF68(int index);
    virtual void fn_27_FFAC();
    virtual int fn_27_FFF0();
};

extern "C" void fn_27_A1224(Class_C80* self, int start, const Byte* value,
                            unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->fn_27_FFF0())
        count = self->fn_27_FFF0() - start;

    for (int i = 0; i < count; ++i) {
        Byte* dst = self->fn_27_FF68(start + i);
        dst->a = value->a;
    }
}