#pragma force_active on
#pragma fp_contract off

#include <mt/mt_vector.h>
#include <types.h>

struct Pr {
    int a, b;
};

inline Vec2f& vector(Pr& p) { return reinterpret_cast<Vec2f&>(p); }
inline float x(Pr& p) { return vector(p).m_x; }

inline float dot(const Vec2f& p, const Vec2f& q) {
    return p.m_x * q.m_x + p.m_y * q.m_y;
}

inline void assign(Vec2f& dest, const Vec2f& src) {
    dest.m_x = src.m_x;
    dest.m_y = src.m_y;
}

extern "C" {
int fn_27_1DA24C(void*);
float fn_8003DDD0(const Pr*, const Pr*);
void* __dynamic_cast(void*, long, const void*, const void*, long);
extern char lbl_27_data_457C0[];
extern char lbl_27_data_CDF8[];
extern float lbl_27_rodata_7EA8[];
}

#define F(n) virtual void f##n();
#define TEN(a,b,c,d,e,f,g,h,i,j) \
    F(a) F(b) F(c) F(d) F(e) F(f) F(g) F(h) F(i) F(j)

struct State {
    F(0)
    virtual signed char getFlag();
    virtual signed char getType();
};

struct CastModule {
    F(0) F(1) F(2) F(3) F(4) F(5)
    virtual void* get(int);
    F(7) F(8) F(9)
    TEN(10,11,12,13,14,15,16,17,18,19)
};

struct Result {
    F(0) F(1)
    virtual unsigned long long get();
    F(3) F(4) F(5) F(6) F(7) F(8) F(9)
    TEN(10,11,12,13,14,15,16,17,18,19)
    int pad;
    Vec2f value;
};

struct FloatModule {
    F(0) F(1) F(2) F(3) F(4) F(5) F(6) F(7) F(8)
    virtual float get();
    virtual void set(float);
    F(11) F(12) F(13) F(14) F(15) F(16) F(17) F(18)
    virtual void update();
};

struct FrameBase {
    char pad[8];
};

struct FrameModule : FrameBase {
    TEN(0,1,2,3,4,5,6,7,8,9)
    TEN(10,11,12,13,14,15,16,17,18,19)
    TEN(20,21,22,23,24,25,26,27,28,29)
    TEN(30,31,32,33,34,35,36,37,38,39)
    TEN(40,41,42,43,44,45,46,47,48,49)
    F(50) F(51) F(52) F(53) F(54) F(55) F(56)
    virtual unsigned long long get(unsigned, int);
};

struct FrameCheck {
    F(0) F(1) F(2) F(3)
    virtual int getFrame(unsigned);
    F(5) F(6) F(7) F(8) F(9)
    TEN(10,11,12,13,14,15,16,17,18,19)
};

struct ActionModule {
    F(0) F(1) F(2)
    virtual void act(int, void*);
    F(4) F(5) F(6) F(7) F(8) F(9)
    TEN(10,11,12,13,14,15,16,17,18,19)
};

struct ObjectBase {
    char pad[0x3c];
};

struct Object : ObjectBase {
    TEN(0,1,2,3,4,5,6,7,8,9)
    TEN(10,11,12,13,14,15,16,17,18,19)
    TEN(20,21,22,23,24,25,26,27,28,29)
    TEN(30,31,32,33,34,35,36,37,38,39)
    F(40) F(41) F(42) F(43) F(44) F(45) F(46)
    virtual int valid(signed char);
    F(48) F(49)
    TEN(50,51,52,53,54,55,56,57,58,59)
    TEN(60,61,62,63,64,65,66,67,68,69)
    TEN(70,71,72,73,74,75,76,77,78,79)
    TEN(80,81,82,83,84,85,86,87,88,89)
    TEN(90,91,92,93,94,95,96,97,98,99)
    TEN(100,101,102,103,104,105,106,107,108,109)
    TEN(110,111,112,113,114,115,116,117,118,119)
    TEN(120,121,122,123,124,125,126,127,128,129)
    F(130) F(131) F(132) F(133) F(134) F(135) F(136) F(137)
    virtual void change(int);
    char pad1[0x1fdc];
    float* scale;
};

struct Owner : ObjectBase {
    TEN(0,1,2,3,4,5,6,7,8,9)
    TEN(10,11,12,13,14,15,16,17,18,19)
    TEN(20,21,22,23,24,25,26,27,28,29)
    TEN(30,31,32,33,34,35,36,37,38,39)
    F(40) F(41) F(42)
    virtual void action();
};

#undef TEN
#undef F

struct Modules {
    char pad0[12];
    FloatModule* floatModule;
    FrameModule* frameModule;
    char pad1[0x50];
    FrameCheck* frameCheck;
    char pad2[8];
    ActionModule* action;
    char pad3[8];
    CastModule* castModule;
};

struct Context {
    char pad0[8];
    Owner* owner;
    char pad1[0xcc];
    Modules* modules;
};

extern "C" int fn_27_3A4F40(Object* self, State* state, Context* context) {
    float literal;
    double conversionBias;
    literal = -1.0f;
    literal = 0.0f;
    literal = 1.0f;
    literal = 20.0f;
    literal = 360.0f;
    literal = 0.01745329238474369f;
    literal = 57.295780181884766f;
    literal = 1.5707963705062866f;
    literal = 2.0f;
    conversionBias = 4503601774854144.0;

    if (fn_27_1DA24C(self))
        return 1;

    if (!self->valid(state->getFlag()))
        return 0;

    if (state->getType() <= -1 || state->getType() >= 11)
        return 0;

    switch (state->getType()) {
    case 6: {
        Result* result = (Result*)__dynamic_cast(
            context->modules->castModule->get(0), 0,
            lbl_27_data_457C0, lbl_27_data_CDF8, 1);

        Pr origin;
        Pr original;
        Pr direction;

        unsigned long long bits = result->get();
        origin = *(const Pr*)&bits;
        original = origin;

        unsigned long long dbits =
            context->modules->frameModule->get(0xff, 0);
        direction = *(const Pr*)&dbits;

        float rate = context->modules->floatModule->get();
        float angle = fn_8003DDD0(&origin, &direction);
        float scale = self->scale[0];
        float limit = 0.01745329238474369f * scale;
        angle -= 1.5707963705062866f;

        if (angle > limit) {
            self->change(0);
            return 1;
        }

        if (context->modules->frameCheck->getFrame(0x10000004) -
                *(int*)((char*)self->scale + 0x10) <= 0) {
            context->modules->action->act(1, context);
            return 1;
        }

        assign(vector(origin), vector(origin) - (vector(direction) * 2.0f) *
            dot(vector(direction), vector(origin)));

        float oldSign = x(original) < 0.0f ? -1 : 1;
        int newSign = x(origin) < 0.0f ? -1 : 1;

        if ((float)newSign * (float)oldSign < 0.0f) {
            context->modules->floatModule->set(-1.0f * rate);
            context->modules->floatModule->update();
            context->owner->action();
        }

        Vec2f out;
        out.m_y = vector(origin).m_y;
        out.m_x = vector(origin).m_x;
        assign(result->value, out);
        return 1;
    }
    }

    return 0;
}
