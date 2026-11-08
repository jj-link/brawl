#pragma force_active on
struct Data {
    int a00, a04, a08, a0C, a10, a14, a18, a1C, a20, a24;
    int a28, a2C, a30, a34, a38, a3C, a40, a44, a48;
    float f4C, f50, f54;
    int a58, a5C, a60, a64, a68, a6C;
    short s70;
    unsigned char b72, b73, b74;
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Data* slot1(int index);
    virtual void slot2();
    virtual int slot3();
};
extern "C" void fn_40_20718(Object_vptr_0* self, int start, const Data* source, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->slot3()) {
        count = self->slot3() - start;
    }
    for (int i = 0; i < count; ++i) {
        Data* dst = self->slot1(start + i);
        *dst = *source;
    }
}