#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual int* slot1(int);
    virtual void slot2();
    virtual int slot3();
};

extern "C" void fn_27_296D74(Object_vptr_0* self, int start, int* source, unsigned int countArg)
{
    int count = static_cast<int>(countArg);
    if (count + start >= self->slot3())
        count = self->slot3() - start;
    for (int i = 0; i < count; ++i) {
        int* dst = self->slot1(start + i);
        *dst = *source;
    }
}