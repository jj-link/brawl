#pragma force_active on

typedef unsigned int u32;
typedef unsigned long long u64;
typedef int s32;

struct Vec {
    union {
        u64 bits;
        struct { float x, y; };
    };

    Vec(u64 v) { bits = v; }
};

struct LocalData {
    int a;
    float b, c;
    unsigned char d, e, f, g;

    LocalData(int n, float v)
        : a(n), b(v), c(lbl()), d(0), e(0), f(1), g(0) {}

    static float lbl();
};

struct Obj8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float facing();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void change(LocalData*);
};

struct Obj10 {
    char pad[8];

    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void change(int, int);
};

struct Obj14 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int get();
};

struct Obj40 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual u64 get(int);
};

struct Obj64 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int get(u32);
    virtual void set(int, u32);
};

struct Obj7c {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void* get(int);
};

struct Modules {
    char p0[8];
    Obj8* obj8;
    char pc[4];
    Obj10* obj10;
    Obj14* obj14;
    char p18[0x28];
    Obj40* obj40;
    char p44[0x20];
    Obj64* obj64;
    char p68[0x14];
    Obj7c* obj7c;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" {
unsigned int fn_27_1795AC(s32, Accesser*, s32, s32, s32*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_27_data_2E5F8[], lbl_27_data_CDF8[];
extern float lbl_27_rodata_2358;
}

inline float LocalData::lbl() {
    return lbl_27_rodata_2358;
}

extern "C" void fn_27_179BF8(s32 self, Accesser* obj) {
    Vec temp(obj->modules->obj40->get(1));
    Vec pos(temp);

    float* result = (float*)__dynamic_cast(
        obj->modules->obj7c->get(3),
        0, lbl_27_data_2E5F8, lbl_27_data_CDF8, 1);
    result[2] = pos.x;
    result[3] = pos.y;

    if (obj->modules->obj14->get() == 0) {
        int value;
        if (fn_27_1795AC(self, obj, 0x7e, 0x81, &value) == 1) {
            obj->modules->obj10->change(5, 0);
            return;
        }

        int n = value;
        if (n != obj->modules->obj64->get(0x20000000)) {
            obj->modules->obj64->set(n, 0x20000000);
            LocalData local(value, obj->modules->obj8->facing());
            obj->modules->obj8->change(&local);
        }
    }
}
