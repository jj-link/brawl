#include <types.h>
#include <em/wnem/wnem_proc_common.h>
#include <wn/wn_em_simple.h>
#include <mt/mt_vector.h>
#include <so/so_array.h>

#pragma force_active on

extern char lbl_41_data_E6D7[];
extern char lbl_41_data_E71E[];
extern const float lbl_41_rodata_FA0[];

struct Params {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    float unk14;
    s32 unk18;
    float unk1C;
};

#define V5(n) \
    virtual void n##0(); \
    virtual void n##1(); \
    virtual void n##2(); \
    virtual void n##3(); \
    virtual void n##4();

#define V10(n) V5(n##a) V5(n##b)

class Hit {
public:
    V5(a)
    V5(b)
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void set(int);
};

class Coll {
public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void clear();
};

class Other {
public:
    V5(a)
    virtual void b0();
    virtual void set(int, int);
};

class Posture {
public:
    V5(a)
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual float lr();
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual Vec3f getRot(int);
    virtual void setRot(Vec3f*, int);
};

struct V2 {
    float x;
    float y;
};

class Ground {
    char pad[8];

public:
    V10(a)
    V10(b)
    V10(c)
    V10(d)
    V10(e)
    V5(f)
    virtual bool check(int, int);
    virtual void g();
    virtual V2 normal(int, int);
};

class Kinetic {
    char pad[8];

public:
    V10(a)
    V10(b)
    V5(c)
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void set(int, Vec3f*);
};

#undef V10
#undef V5

struct Modules {
    char pad[4];
    Kinetic* kinetic;
    char pad8[4];
    Posture* posture;
    Ground* ground;
    Other* other;
    char pad18[8];
    Hit* hit;
    char pad24[0x28];
    Coll* coll;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_41_31B34(wnemSimple*);
extern "C" Vec3f* fn_41_5AC4(Vec3f*, float, float, float);
extern "C" void fn_41_534C(Vec3f*, const Vec3f*);
extern "C" void fn_8003DBA8(Vec2f*);
extern "C" void fn_8003DC64(Vec2f*, float, Vec2f*);
extern "C" V2 fn_41_108CC(const V2*, float);

inline float valueAt(wnemSimple* wn, int index) {
    return ((soArrayFixed<float>*)&wn->unk2238[0x14])->at(index);
}

inline int& counter(wnemSimple* wn) {
    return ((soArrayFixed<int>*)&wn->unk2238[0])->at(0);
}

inline V2 reflect(V2* normal, V2* velocity, const float* rod) {
    V2 result;
    float dot = normal->x * velocity->x + normal->y * velocity->y;
    V2 scaled = fn_41_108CC(normal, rod[3]);
    V2 projection = fn_41_108CC(&scaled, dot);
    result.x = velocity->x - projection.x;
    result.y = velocity->y - projection.y;
    return result;
}

extern "C" void fn_41_44F14(wnemSimple* arg0, Accesser* arg1) {
    const float* rod = lbl_41_rodata_FA0;
    Params* data = 0;
    if (arg0->unk2234) {
        data = (Params*)arg0->unk2234;
    }

    bool entering = arg0->unk2214;
    arg0->unk2214 = false;
    if (entering) {
        wnemCommonProc::Report(lbl_41_data_E6D7);
        arg0->SetLifeLimit(data->unkC);
        arg1->modules->other->set(2, 1);
        arg1->modules->coll->clear();
        arg1->modules->hit->set(0);

        if (*(s32*)((char*)arg0 + 0x21CC) == 3) {
            wnemCommonProc::Report(lbl_41_data_E71E);
            arg0->SetLifeLimit(10);
            arg0->RequestDeactive();
            return;
        }

        fn_41_31B34(arg0);

        Vec2f v38;
        v38.m_x = valueAt(arg0, 0);
        v38.m_y = valueAt(arg0, 1);

        float f30;
        if (*(s32*)((char*)arg0 + 0x21CC) == 0) {
            f30 = data->unk14;
        } else {
            f30 = valueAt(arg0, 2);
        }

        float f31 = valueAt(arg0, 3);
        fn_8003DBA8(&v38);
        v38.m_x *= f30;
        v38.m_y *= f30;

        s32 mode = *(s32*)((char*)arg0 + 0x21CC);
        if (mode == 1) {
            fn_8003DC64(&v38, rod[2] * -f31, &v38);
        } else if (mode == 2) {
            fn_8003DC64(&v38, rod[2] * f31, &v38);
        }

        counter(arg0) = 0;
        arg0->unk2204 = rod[0];
        arg0->unk2200 = rod[0];
        arg0->unk21F8 = v38.m_x;
        arg0->unk21FC = v38.m_y;
    }

    if (arg1->modules->ground->check(0xff, 0)) {
        V2 normal;
        V2 raw = arg1->modules->ground->normal(0xff, 0);
        __memcpy(&normal, &raw, sizeof(V2));
        V2 result = reflect(&normal, (V2*)&arg0->unk21F8, rod);
        arg0->unk21F8 = result.x;
        arg0->unk21FC = result.y;

        s32 r27 = counter(arg0);
        if (r27 >= data->unk18) {
            arg0->RequestDeactive();
            return;
        }
        counter(arg0) = r27 + 1;
    }

    Vec3f v4C;
    fn_41_5AC4(&v4C, rod[0], rod[0], rod[0]);
    if (rod[1] == arg1->modules->posture->lr()) {
        v4C.m_y = rod[4];
    }

    arg1->modules->posture->setRot(&v4C, 0);
    Vec3f v40 = arg1->modules->posture->getRot(1);
    fn_41_534C(&v4C, &v40);
    v4C.m_x += data->unk1C;
    v4C.m_z = rod[0];
    v4C.m_y = rod[0];
    arg1->modules->posture->setRot(&v4C, 1);
    arg1->modules->kinetic->set(3, &v4C);
}
