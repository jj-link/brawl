#pragma force_active on

struct Data {
    int a00, a04, a08, a0C, a10, a14, a18, a1C, a20, a24;
    int a28, a2C, a30, a34, a38, a3C, a40, a44, a48;
    float f4C, f50, f54;
    int a58, a5C, a60, a64, a68, a6C;
    short s70;
    unsigned char b72, b73, b74;
};

class Class_14D0 {
public:
    virtual void fn_77_5564();
    virtual Data* fn_77_4984(int);
    virtual void fn_77_4994();
    virtual int fn_77_3CC8();
};

extern "C" void fn_77_4630(Class_14D0* self, int start, const Data* source, unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->fn_77_3CC8()) {
        count = self->fn_77_3CC8() - start;
    }

    for (int i = 0; i < count; ++i) {
        Data* dst = self->fn_77_4984(start + i);
        *dst = *source;
    }
}