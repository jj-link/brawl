#pragma force_active on
class Node {
public:
    virtual void s0();
    virtual void s1();
    virtual Node* s4();
    virtual void s5(int a, int b);
    virtual Node* s6();
    virtual void s7();
    virtual void s8(int a);
};

struct Holder {
    char pad[0xF60];
    Node sub;
};

extern "C" void fn_27_28F418(Holder* self, int arg1) {
    int first = (int)self->sub.s6()->s4();
    int second = (int)self->sub.s4()->s4();
    if (second == first) {
        self->sub.s8(arg1);
    }
    self->sub.s5(arg1, 1);
}
