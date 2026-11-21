#pragma force_active on

struct Skip {
    unsigned int a, b;
    Skip& operator=(const Skip&) { return *this; }
};

struct Pair {
    unsigned int a, b;
    Pair& operator=(const Pair& p) { a = p.a; b = p.b; return *this; }
};

struct Tail {
    Pair pairs[6];
};

struct Element {
    unsigned int first[10];
    Skip skipped;
    unsigned int middle[1];
    Tail tail;
    unsigned char last[2];
};

class Class_1F70 {
public:
    virtual void fn_66_CA8C();
    virtual Element* fn_66_BF54(int index);
    virtual void fn_66_BF64();
    virtual int fn_66_A44C();
};

extern "C" void fn_66_C7B0(Class_1F70* const self, int index, const Element* src, unsigned int countArg) {
    int count = countArg;
    Element* dst;
    if (count + index >= self->fn_66_A44C()) {
        count = self->fn_66_A44C() - index;
    }
    for (int i = 0; i < count; i++) {
        dst = self->fn_66_BF54(index + i);
        *dst = *src;
    }
}
