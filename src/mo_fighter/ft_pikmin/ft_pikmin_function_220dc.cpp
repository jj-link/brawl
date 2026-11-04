#pragma force_active on
struct Vec2 { float x, y; };

class VObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4(unsigned long);
};

struct Mid { char pad[0x64]; VObj* obj; };
struct Arg2 { char pad[0xd8]; Mid* mid; };

class Arg1 {
public:
    virtual void v0();
    virtual void v1(Arg2*);
    int unk;
    Vec2 vec;
};

extern "C" {
extern const float lbl_113_rodata_88[];
void fn_113_BC00(Vec2*, const Vec2*);

void fn_113_220DC(void* unused, Arg1* self, Arg2* arg2) {
    const float* c = lbl_113_rodata_88;
    if (arg2->mid->obj->v4(0x20000000) >= 0) {
        float val = c[14];
        int r = arg2->mid->obj->v4(0x10000011);
        if (!(r & 0x10)) {
            val *= c[3];
        }
        Vec2 vec_if;
        vec_if.x = val;
        vec_if.y = c[2];
        fn_113_BC00(&self->vec, &vec_if);
    } else {
        Vec2 vec_else;
        vec_else.x = c[2];
        vec_else.y = c[2];
        fn_113_BC00(&self->vec, &vec_else);
    }
    self->v1(arg2);
}
}