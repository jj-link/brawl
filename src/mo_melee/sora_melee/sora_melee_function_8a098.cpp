#pragma force_active on

struct Vec2Work {
    float x;
    float y;
};

extern "C" Vec2Work fn_27_895B8(const Vec2Work* a, const Vec2Work* b, const Vec2Work* c, const Vec2Work* d);
extern "C" Vec2Work fn_27_897E0(const Vec2Work* a, const Vec2Work* b);
extern "C" Vec2Work fn_27_899AC(const Vec2Work* a, const Vec2Work* b);

extern const float lbl_27_rodata_BA8;
extern const float lbl_27_rodata_BAC;

inline Vec2Work copyVec(Vec2Work v) {
    return v;
}

class Pre8 {
public:
    int pad0;
    int pad1;
};

#define V(n) virtual void m##n();

class ObjPre8 : public Pre8 {
public:
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54)
    virtual int m55(int, int);
    V(56)
    virtual Vec2Work m57(int, int);
    V(58) V(59) V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67)
    V(68) V(69) V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77)
    V(78) V(79) V(80) V(81) V(82) V(83) V(84) V(85) V(86) V(87)
    V(88) V(89)
    virtual float m90(int);
};

class Obj14 {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual int m3();
};

struct Accesser {
    char pad0[0x10];
    ObjPre8* p10;
    Obj14* p14;
};

struct Module {
    char pad0[0xd8];
    Accesser* acc;
};

struct Self {
    char pad0[8];
    Vec2Work v8;
    Vec2Work v10;
    Vec2Work v18;
    Vec2Work v20;
    Vec2Work v28;
    unsigned char f30;
    unsigned char f31;
    unsigned char f32;
};

extern "C" void fn_27_8A098(Self* self, Module* m) {
    if (lbl_27_rodata_BA8 != (self->v10.x * self->v10.x + self->v10.y * self->v10.y) ||
        lbl_27_rodata_BA8 != (self->v8.x * self->v8.x + self->v8.y * self->v8.y)) {
        Vec2Work a = self->v10;
        Vec2Work b = self->v20;
        if (m->acc->p14->m3() == 0) {
            if (self->f30 == 1 || (self->f31 == 1 && self->f32 == 1)) {
                if (m->acc->p10->m55(8, 0) != 0) {
                    if (self->f31 == 1 && self->f32 == 1 &&
                        ((a.x * a.x + a.y * a.y) != lbl_27_rodata_BA8 ||
                         (b.x * b.x + b.y * b.y) != lbl_27_rodata_BA8)) {
                        float s = m->acc->p10->m90(0);
                        if (s > lbl_27_rodata_BAC) {
                            b.x = b.x * s;
                            b.y = b.y * s;
                        } else if (s < lbl_27_rodata_BAC) {
                            a.x = a.x * s;
                            a.y = a.y * s;
                            b.x = b.x * s;
                            b.y = b.y * s;
                        }
                    }
                    if (self->f30 == 1) {
                        float qa = a.x * a.x + a.y * a.y;
                        if (lbl_27_rodata_BA8 != qa) {
                            Vec2Work d = copyVec(m->acc->p10->m57(8, 0));
                            a = fn_27_899AC(&a, &d);
                        }
                    }
                }
            }
        }
        a = fn_27_895B8(&self->v8, &a, &self->v18, &b);
        float qr = a.x * a.x + a.y * a.y;
        if (lbl_27_rodata_BA8 != qr) {
            self->v8.x = self->v8.x + a.x;
            self->v8.y = self->v8.y + a.y;
        }
        self->v8 = fn_27_897E0(&self->v8, &self->v28);
    }
}
