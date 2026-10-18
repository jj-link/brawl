#pragma force_active on
class Target {
public:
    char pad[0x10];
    float m_val;
};

class Inner {
public:
    virtual void slot0();
    virtual Target* slot1();
};

class Outer {
public:
    char pad[0x2c];
    Inner* m_inner;
};

extern "C" {
void fn_27_4E5C4(Outer* self, float value) {
    self->m_inner->slot1()->m_val = value;
}
}
