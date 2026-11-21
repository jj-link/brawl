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

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual Element* slot1(int);
    virtual void slot2();
    virtual int slot3();
};

extern "C" void fn_27_E803C(Object_vptr_0* self, int start, const Element* value, unsigned int countArg) {
    int count = countArg;
    if (count + start >= self->slot3()) {
        count = self->slot3() - start;
    }
    for (int i = 0; i < count; i++) {
        *self->slot1(start + i) = *value;
    }
}
