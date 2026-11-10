#pragma force_active on
struct Skip {
    unsigned int a, b;
    Skip& operator=(const Skip&) { return *this; }
};
struct Pair {
    unsigned int a, b;
    void operator=(const Pair& p) {
        a = p.a;
        b = p.b;
    }
};
struct PairRegion {
    Pair pairs[6];
};
struct Element {
    unsigned int first[10];
    Skip skipped;
    unsigned int middle;
    PairRegion region;
    unsigned char last[2];
};
class Class_1898 {
public:
    virtual void fn_67_818C();
    virtual Element* fn_67_7654(int);
    virtual void fn_67_7664();
    virtual int fn_67_51C8();
};
extern "C" void fn_67_7EB0(Class_1898* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_67_51C8()) {
        count = self->fn_67_51C8() - index;
    }
    for (int i = 0; i < count; ++i) {
        *self->fn_67_7654(index + i) = *value;
    }
}