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

class Class_1AB0 {
public:
    virtual void fn_76_6F4C();
    virtual Element* fn_76_6414(int);
    virtual void fn_76_6424();
    virtual int fn_76_3F88();
};

extern "C" void fn_76_6C70(Class_1AB0* self, int index, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + index >= self->fn_76_3F88()) {
        count = self->fn_76_3F88() - index;
    }
    for (int i = 0; count > i; ++i) {
        *self->fn_76_6414(index + i) = *value;
    }
}
