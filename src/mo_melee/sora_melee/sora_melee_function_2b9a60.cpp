#pragma force_active on
struct Vec2f {
    float x;
    float y;
};

extern "C" const float lbl_27_rodata_5EBC;

// vtable at 0x1e0a8: 16 slots; the object holds the vtable pointer at offset 0xf8; shown up to slot 2
struct Class_1E0A8_base { char pad[0xf8]; };
class Class_1E0A8 : public Class_1E0A8_base {
public:
    virtual void fn_27_E6C88();  // offset 0x8
    virtual void fn_27_E640C();  // offset 0xc
    virtual void fn_27_E641C();  // offset 0x10
};

class Part {
public:
    virtual void v0();
    virtual void v1();
    virtual Vec2f get();
    char pad;
    unsigned char m_active : 1;
};

struct Obj {
    char pad0[0x38];
    int m_id;
    char pad3c[0x8c - 0x3c];
    Part p8c;
    char pad94[0xd8 - 0x94];
    Part pd8;
    char pade0[0xf8 - 0xe0];
    Part pf8;
    char pad100[0x130 - 0x100];
    Part p130;
    char pad138[0x1b4 - 0x138];
    Part p1b4;
    char pad1bc[0x200 - 0x1bc];
    Part p200;
    char pad208[0x23c - 0x208];
    Part p23c;
    char pad244[0x250 - 0x244];
    Part p250;
    char pad258[0x280 - 0x258];
    Part p280;
};

extern "C" Vec2f fn_27_2B9A60(Obj* o, short* flags) {
    Vec2f sum;
    sum.x = lbl_27_rodata_5EBC;
    sum.y = lbl_27_rodata_5EBC;
    if (o->m_id == -1) {
        return sum;
    }
    if (*flags & 4) {
        if (o->p23c.m_active) {
            Vec2f r = o->p23c.get();
            sum.x += r.x;
            sum.y += r.y;
        }
        if (o->p280.m_active) {
            Vec2f r = o->p280.get();
            sum.x += r.x;
            sum.y += r.y;
        }
    }
    if (*flags & 8) {
        if (o->p250.m_active) {
            Vec2f r = o->p250.get();
            sum.x += r.x;
            sum.y += r.y;
        }
    }
    if (*flags & 1) {
        if (o->p8c.m_active) {
            Vec2f r = o->p8c.get();
            sum.x += r.x;
            sum.y += r.y;
        }
        if (o->pd8.m_active) {
            Vec2f r = o->pd8.get();
            sum.x += r.x;
            sum.y += r.y;
        }
        if (o->pf8.m_active) {
            Vec2f r = o->pf8.get();
            sum.x += r.x;
            sum.y += r.y;
        }
        if (o->p130.m_active) {
            Vec2f r = o->p130.get();
            sum.x += r.x;
            sum.y += r.y;
        }
        if (o->p1b4.m_active) {
            Vec2f r = o->p1b4.get();
            sum.x += r.x;
            sum.y += r.y;
        }
        if (o->p200.m_active) {
            Vec2f r = o->p200.get();
            sum.x += r.x;
            sum.y += r.y;
        }
    }
    return sum;
}
