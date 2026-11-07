#include <types.h>
#pragma force_active on

struct V2 { f32 x, y; V2() {} V2(f32 a, f32 b) : x(a), y(b) {} };
struct V3 { f32 x, y, z; };

class Energy {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual V3 s4();
    virtual void s5(int, V2*, const V3&, void*);
    char pad[0x1c];
    V2 f20;
    V2 f28;
};
class Kin { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void* s6(int); };
class Post { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual f32 s9(); };
class Sit { public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual int s3(); };
struct Modules { char p0[0xc]; Post* post; char p1[4]; Sit* sit; char p2[0x64]; Kin* kin; };
struct Acc { char p[0xd8]; Modules* m; };

extern "C" {
extern char lbl_27_data_2E5F8[], lbl_27_data_CDF8[];
extern const f32 lbl_27_rodata_7DE4;
void* __dynamic_cast(void*, long, const void*, const void*, long);
f32 fn_27_192278(void*, unsigned long);
}

extern "C" void fn_27_39B854(Acc* a, int arg1) {
    Energy* e = (Energy*)__dynamic_cast(a->m->kin->s6(3), 0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    f32 lr = a->m->post->s9();
    int s = a->m->sit->s3();
    V2 v(lbl_27_rodata_7DE4, lbl_27_rodata_7DE4);
    int kind;
    f32 f;
    if (s == 0) {
        kind = 0;
        f = fn_27_192278(a, 0xfa0);
    } else {
        kind = 6;
        f = fn_27_192278(a, 0xfa1);
    }
    v.x = -lr * (f * (f32)arg1);
    e->s5(kind, &v, e->s4(), a);
    e->f28 = v;
    if (s != 0) {
        e->f20 = V2(fn_27_192278(a, 0xfa2), lbl_27_rodata_7DE4);
    }
}
