#pragma force_active on
typedef unsigned char u8;

struct Vec3f {
    float x, y, z;
};

class Fighter {
public:
    void start(Vec3f* pos, float a, float b, int c, bool d);
};

class Base0 {
public:
    char _pad[0xc];
};

class Obj : public Base0 {
public:
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual float w3();
};

struct FtManager {
    char _pad[0x68];
    u8 f68;
};

extern FtManager* g_ftManager;

struct Ctx {
    char _0[0x0e];
    u8 flags;
    char _1[0x28 - 0x0f];
    Obj* p28;
    char _2[0x3c - 0x2c];
    Fighter* p3c;
};

extern "C" void fn_27_111B7C(Vec3f* out, Obj** src);
extern "C" float fn_27_111B44(Obj* self);

extern "C" void fn_27_114CE4(Ctx* self) {
    if (self->flags & 2) {
        Vec3f tmp;
        fn_27_111B7C(&tmp, (Obj**)self->p28);
        float a = fn_27_111B44(self->p28);
        Fighter* f = self->p3c;
        float b = self->p28->w3();
        f->start(&tmp, a, b, 1, g_ftManager->f68 == 1);
    }
}
