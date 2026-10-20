#pragma force_active on
class Sub {
public:
    virtual ~Sub();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual bool isEmpty() const;
};

struct Outer {
    int a, b, c;
    Sub sub;
};

extern "C" {
bool fn_27_1AA1E4(Outer* self) {
    return self->sub.isEmpty();
}
}