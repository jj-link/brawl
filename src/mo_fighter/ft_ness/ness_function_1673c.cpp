#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const char lbl_101_data_853C[], lbl_101_data_4330[];
extern float lbl_101_rodata_C0;
}

class V1 {
public:
    virtual void m0() = 0;
    virtual void m1() = 0;
    virtual void m2() = 0;
    virtual void m3() = 0;
    virtual int f(int) = 0;
};

class V2 {
public:
    virtual void g0() = 0;
    virtual void g1() = 0;
    virtual void g2() = 0;
    virtual void g3() = 0;
    virtual void g4() = 0;
    virtual void g5() = 0;
    virtual void g6() = 0;
    virtual void g7() = 0;
    virtual void g8() = 0;
    virtual void g9() = 0;
    virtual void g10() = 0;
    virtual void g11() = 0;
    virtual void g12() = 0;
    virtual void g13() = 0;
    virtual void g14() = 0;
    virtual void g15() = 0;
    virtual void g16() = 0;
    virtual void g17() = 0;
    virtual void g18() = 0;
    virtual void g19() = 0;
    virtual void g20() = 0;
    virtual void g21() = 0;
    virtual void g22() = 0;
    virtual void g(float, float) = 0;
};

struct Obj {
    int x0;
    int x4;
    char pad2[0x10];
    float x18;
};

struct Holder {
    char pad[0xc];
    V2* v14;
    char pad2[0x54];
    V1* v64;
};

struct Arg {
    char pad[8];
    void* object;
    char pad2[0xcc];
    Holder* holder;
};

extern "C" void fn_101_1673C(void*, Arg* arg) {
    char* p = (char*)__dynamic_cast(arg->object, 0x3c, lbl_101_data_853C, lbl_101_data_4330, 1);
    Obj* obj = *(Obj**)(p + 0x23ac);
    V1* v1 = arg->holder->v64;
    int v = v1->f(0x10000004);
    float result = obj->x18 + ((((float)v) * (lbl_101_rodata_C0 - obj->x18)) / (float)obj->x4);
    arg->holder->v14->g(result, obj->x18);
}
