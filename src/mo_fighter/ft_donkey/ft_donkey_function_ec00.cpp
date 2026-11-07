#pragma force_active on
struct Vec3f { float x, y, z; };
class Work {
public:
    virtual void s08(); virtual void s0c(); virtual void s10(); virtual void s14();
    virtual int getInt(int);
    virtual void setInt(int, int);
    virtual void s20(); virtual void s24();
    virtual void decInt(int);
    virtual void s2c(); virtual void s30(); virtual void s34(); virtual void s38();
    virtual void setFloat(float, int);
    virtual void s40(); virtual void s44(); virtual void s48();
    virtual int isFlag(int);
    virtual void s50();
    virtual void offFlag(int);
};
class M84 {
public:
    virtual void s08(); virtual void s0c(); virtual void s10();
    virtual void f14(int, int, bool);
};
class Eff {
public:
    virtual void s08(); virtual void s0c(); virtual void s10(); virtual void s14();
    virtual void s18(); virtual void s1c(); virtual void s20(); virtual void s24();
    virtual void req(int, int, Vec3f*, Vec3f*, float, Vec3f*, Vec3f*, int, int);
    virtual void s2c(); virtual void s30();
    virtual void req2(int, int, Vec3f*, Vec3f*, float, int, int, int, int);
};
class Atk {
public:
    virtual void s08(); virtual void s0c(); virtual void s10(); virtual void s14();
    virtual void s18();
    virtual void clear(int);
    virtual void s20(); virtual void s24();
    virtual void set(int, int);
    virtual void s2c(); virtual void s30(); virtual void s34(); virtual void s38(); virtual void s3c();
    virtual int isAttack(int, int);
};
struct Enum {
    char p0[0x1c]; Atk* atk;
    char p20[0x44]; Work* work;
    char p68[0x1c]; M84* m84; Eff* eff;
};
struct Acc { char p[0xd8]; Enum* e; };
struct Params { char p[0x14]; int limit; };
struct CData { char p[0x8c]; Params* params; };
extern "C" {
extern float lbl_92_rodata_38[];
extern char g_ftCommonDataAccesser;
CData* getData__20ftCommonDataAccesserCF6ftKind(void*, int);
float randf__Fv();
Vec3f* fn_92_D29C(Vec3f*, float, float, float);
}

extern "C" void fn_92_EC00(void*, Acc* acc) {
    float* d = lbl_92_rodata_38;
    M84* m84 = acc->e->m84;
    Work* work = acc->e->work;
    Eff* eff = acc->e->eff;
    Params* prm = getData__20ftCommonDataAccesserCF6ftKind(&g_ftCommonDataAccesser, 1)->params;
    int a = work->getInt(0x20000004);
    int b = work->getInt(0x20000002);
    if (a >= prm->limit) {
        float f = d[8] * randf__Fv();
        work->setFloat(f, 0x21000005);
        m84->f14(1, 0, false);
        f += d[8];
        work->setFloat(f, 0x21000005);
        m84->f14(1, 0, false);
        a = 0;
        b = 0;
    }
    work->setInt(a + 1, 0x20000004);
    work->setInt(b, 0x20000002);
    if (work->isFlag(0x22000018)) {
        work->offFlag(0x22000018);
        if (work->isFlag(0x22000012)) {
            Vec3f v4, v3, v2, v1;
            eff->req(0xe10001, 0, fn_92_D29C(&v4, d[3], d[9], d[3]),
                     fn_92_D29C(&v3, d[3], d[3], d[3]), d[0],
                     fn_92_D29C(&v2, d[3], d[3], d[3]),
                     fn_92_D29C(&v1, d[3], d[3], d[3]), 1, 0);
        } else {
            Vec3f v2, v1;
            eff->req2(0xe1000a, 0, fn_92_D29C(&v2, d[3], d[9], d[3]),
                      fn_92_D29C(&v1, d[3], d[3], d[3]), d[0], 1, 0, 0, -1);
        }
    }
    if (work->isFlag(0x22000019)) {
        work->offFlag(0x22000019);
        Vec3f v2, v1;
        eff->req2(0xe1000b, 3, fn_92_D29C(&v2, d[3], d[3], d[3]),
                  fn_92_D29C(&v1, d[3], d[3], d[3]), d[0], 1, 0, 0, -1);
    }
    Atk* atk = acc->e->atk;
    int n = work->getInt(0x2000000a);
    if (n != -1) {
        for (int i = 0; i < 4; i++) {
            if (atk->isAttack(i, 0)) atk->clear(i);
        }
        atk->set(n, 0);
        work->setInt(-1, 0x2000000a);
    } else if (work->getInt(0x20000009) > 0) {
        work->decInt(0x20000009);
        if (work->getInt(0x20000009) <= 0) {
            for (int i = 0; i < 4; i++) {
                if (atk->isAttack(i, 0)) atk->clear(i);
            }
        }
    }
}
