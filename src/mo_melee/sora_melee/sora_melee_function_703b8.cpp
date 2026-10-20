#pragma force_active on
typedef int s32;
typedef unsigned int u32;

struct Big {
    float x;
    float y;
    float z;
    float w;
};

extern "C" void fn_27_777D8(void* out, const Big& a);

class Vt {
public:
    virtual void s0();
    virtual s32 s3(void* out, void* owner, s32* flag, s32 zero);
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual Big s7();
};

struct Mid {
    char pad[0x74];
    Vt* m74;
};

struct Owner {
    char pad[0xd8];
    Mid* md8;
};

struct Ctx {
    char pad[0x44];
    Owner* m44;
};

extern "C" {
s32 fn_27_703B8(Ctx* self, Vt* src) {
    if (self->m44 == 0) {
        return 0;
    }
    s32 local = 0;
    Vt* v = self->m44->md8->m74;
    Big t2;
    fn_27_777D8(&t2, src->s7());
    return v->s3(&t2, self->m44, &local, 0);
}
}
