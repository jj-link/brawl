#pragma force_active on
class grGimmick {
public:
    void setPos(float, float, float);
    char pad[0x3c];
};

#define V4(n) virtual void v##n##a(); virtual void v##n##b(); virtual void v##n##c(); virtual void v##n##d();
struct Mid : grGimmick {
    V4(0) V4(1) V4(2) V4(3) V4(4) V4(5) V4(6) V4(7)
    V4(8) V4(9) V4(10) V4(11) V4(12) V4(13) V4(14) V4(15)
    V4(16) V4(17) V4(18) V4(19) V4(20) V4(21) V4(22) V4(23)
    V4(24) V4(25) V4(26) V4(27) V4(28)
    virtual void target();
};

struct Obj : Mid {
    char pad1[0x14c - 0x40];
    int f14c;
    char pad2[0x158 - 0x150];
    float* pos;
    int f15c;
    char pad3[0x17c - 0x160];
    unsigned char f17c;
};

extern "C" void fn_51_13F7C(Obj* o) {
    if (o->f15c != 0) {
        if (o->f17c == 1) {
            o->setPos(o->pos[0], o->pos[1], o->pos[2]);
        } else {
            o->target();
            if (o->f14c != 0) o->f17c = 1;
        }
    }
}
