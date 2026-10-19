#pragma force_active on
extern "C" {
extern unsigned char g_ftCommonDataAccesser[];
extern const unsigned char lbl_95_data_810C[];
extern const unsigned char lbl_95_data_2C38[];
extern const float lbl_95_rodata_108;
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_89544(void*, int);
}

struct MotionBase {
    unsigned int data0;
    unsigned int data1;
};

struct Motion : MotionBase {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void* query(int, int);
};

struct Status {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual int check(int);
};

struct Article {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void* fetch(int);
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void update(int, void*);
};

struct Modules {
    unsigned char pad0[0x10];
    Motion* motion;
    unsigned char pad1[0x50];
    Status* status;
    unsigned char pad2[0x14];
    Article* article;
};

struct Accesser {
    unsigned char pad[0xd8];
    Modules* modules;
};

struct CommonParam {
    unsigned char pad[0x84];
    float* value;
};

extern "C" void fn_95_139DC(void* r3, Accesser* accesser) {
    Modules* modules = accesser->modules;
    Status* status = modules->status;
    Article* article = modules->article;
    modules->motion->query(3, 0);
    CommonParam* param = (CommonParam*)getData__20ftCommonDataAccesserCF6ftKind(
        g_ftCommonDataAccesser, 4);
    float* value = param->value;

    if (status->check(0x22000011)) {
        article->update(0, accesser);
        fn_27_89544(article, 2);
        void* object = article->fetch(1);
        object = __dynamic_cast(object, 0, lbl_95_data_810C,
                                lbl_95_data_2C38, 1);
        *(float*)((char*)object + 0x0c) = *value;
        *(float*)((char*)object + 0x10) = lbl_95_rodata_108;
    }
}
