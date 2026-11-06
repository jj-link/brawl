#pragma force_active on

struct Pair {
    unsigned int a;
    unsigned int b;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Pair* slot1(int index);
    virtual void slot2();
    virtual int slot3();
};

extern "C" void fn_27_393B0(Object_vptr_0* self, int start, const Pair* value,
                            unsigned int countArg) {
    int count = static_cast<int>(countArg);

    if (count + start >= self->slot3())
        count = self->slot3() - start;

    for (int i = 0; i < count; ++i) {
        Pair* dst = self->slot1(start + i);
        dst->a = value->a;
        dst->b = value->b;
    }
}