#pragma force_active on

extern const float lbl_27_rodata_4610;

struct Vec2 {
    float x;
    float y;
};

struct Vec3 {
    float x;
    float y;
    float z;
    Vec3(Vec2 xy, float zz) : x(xy.x), y(xy.y), z(zz) {}
};

inline Vec2 identity(Vec2 v) { return v; }

class BaseItemSub {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int s16();
};

class BaseItemOwner {
public:
    char m_pad[0x70];
    BaseItemSub* m_sub;
};

class BaseItemCtrl {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual bool c9(int arg);
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void c47();
    virtual void c48();
    virtual void c49();
    virtual void c50();
    virtual void c51();
    virtual void c52();
    virtual Vec2 c53(int arg);
};

class BaseItemPos {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual Vec3 f4();
};

class BaseItem {
public:
    char m_pad0[0x1a4];
    BaseItemOwner* m_owner;
    char m_pad1[0xdb4 - 0x1a8];
    BaseItemPos m_pos;
    char m_pad2[0x27a8 - 0xdb8];
    BaseItemCtrl m_ctrl;
};

extern "C" Vec3 fn_27_28FF84(BaseItem* self) {
    bool haved;
    if (self->m_owner->m_sub->s16() == 2) {
        haved = true;
    } else {
        haved = self->m_ctrl.c9(3);
    }
    if (haved) {
        return Vec3(identity(self->m_ctrl.c53(3)), lbl_27_rodata_4610);
    }
    return self->m_pos.f4();
}
