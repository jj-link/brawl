#include <types.h>
#pragma force_active on

extern const float lbl_27_rodata_4610;

struct Object_vptr_4_base { char pad[4]; };
class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6(void*, int, int);
};
extern "C" {
    extern Object_vptr_4 lbl_27_bss_71C8;
}

class V2C34 {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d(int, void*);
};

class VQ {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
};

class V2AAC {
public:
#define V(n) virtual void v##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18)
#undef V
    virtual void v19(int);
};

struct Vec3 { float x, y, z; };

class V3474 {
public:
#define V(n) virtual void v##n();
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18)
#undef V
    virtual void v19(Vec3*, short*);
#define V(n) virtual void v##n();
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48)
#undef V
    virtual void v49(void*, int);
};

extern "C" int fn_27_28B340(void* object) {
    char* self = (char*)object;
    char* p31 = self + 0x2aac;
    int r = ((Object_vptr_4*)&lbl_27_bss_71C8)->slot6(self + 0xcc, 0x5b73, 0);
    if (r == 1) {
        ((V2C34*)(self + 0x2c34))->d(6, self + 0xcc);
        return 1;
    }
    if (r == 2) {
        ((V2C34*)(self + 0x2c34))->d(7, self + 0xcc);
        return 1;
    }
    if (*(unsigned char*)(self + 0x2130) != 0) {
        ((V2AAC*)p31)->v19(0x22000003);
        float x;
        float y = *(float*)(self + 0x212c);
        x = *(float*)(self + 0x2128);
        Vec3 v;
        v.x = x;
        v.y = y;
        v.z = lbl_27_rodata_4610;
        short s = 1;
        ((V3474*)(self + 0x3474))->v19(&v, &s);
        return 1;
    }
    if (r == 3) {
        VQ* q = *(VQ**)(*(char**)(self + 0x1a4) + 0x14);
        if (q->s3() != 0) {
            ((V2AAC*)p31)->v19(0x22000003);
            ((V3474*)(self + 0x3474))->v49(self + 0xcc, 0);
            return 1;
        }
    }
    return 0;
}
