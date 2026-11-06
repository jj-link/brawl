#pragma force_active on

struct Vec2f {
    float x;
    float y;
};
struct Vec3f {
    float x;
    float y;
    float z;
};

class Obj {
public:
    virtual void v0(unsigned int);
    virtual void v1(unsigned int);
    virtual void v2(unsigned int);
    virtual void v3(unsigned int);
    virtual void v4(unsigned int);
    virtual void v5(unsigned int);
    virtual Obj* v6(unsigned int);
    virtual void v7(unsigned int);
    virtual void v8(unsigned int);
    virtual void v9(unsigned int);
    virtual void v10(unsigned int);
    virtual void v11(unsigned int);
    virtual void v12(unsigned int);
    virtual void v13(unsigned int);
    virtual void v14(unsigned int);
    virtual void v15(unsigned int);
    virtual void v16(unsigned int);
    virtual void v17(unsigned int);
    virtual void v18(unsigned int);
    unsigned char x4;
    signed char f5;
};

extern "C" {
extern const float lbl_27_rodata_1FC0;
void fn_27_89D08(int, void*, int, Vec2f*, Vec3f*);

void fn_27_162B40(int a, int b, int c, char* p) {
    Vec2f v2 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    Vec3f v3 = {lbl_27_rodata_1FC0, lbl_27_rodata_1FC0, lbl_27_rodata_1FC0};
    fn_27_89D08(0, p, 0xd, &v2, &v3);
    Obj* t = *(Obj**)(*(char**)(p + 0xd8) + 0x7c);
    t = t->v6(4);
    t->f5 &= ~0x80;
    Obj* u = *(Obj**)(*(char**)(p + 0xd8) + 0x64);
    u->v18(0x2200000d);
}
}