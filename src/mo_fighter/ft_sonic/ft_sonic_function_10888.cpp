#pragma force_active on

struct SonicF4C8 {
    int field0;
    float field1;
    float field2;
    unsigned char field3;
    unsigned char field4;
    unsigned char field5;
    unsigned char field6;
};

struct VtA {
    virtual void v0();  virtual void v1();  virtual void v2();  virtual void v3();
    virtual void v4();  virtual void v5();  virtual void v6();  virtual void v7();
    virtual void v8();  virtual void v9();  virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29();
    virtual void v30(void* p);
};

struct VtB {
    virtual void v0();  virtual void v1();  virtual void v2();  virtual void v3();
    virtual void v4();  virtual void v5();  virtual void v6();  virtual void v7();
    virtual void v8();
    virtual float v9();
};

struct VtCBase { char pad[8]; };
struct VtC : VtCBase {
    virtual void v0();  virtual void v1();  virtual void v2();  virtual void v3();
    virtual void v4();  virtual void v5();  virtual void v6();  virtual void v7();
    virtual void v8();  virtual void v9();  virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual void v36(); virtual void v37(); virtual void v38(); virtual void v39();
    virtual void v40(); virtual void v41(); virtual void v42(); virtual void v43();
    virtual void v44(); virtual void v45(); virtual void v46(); virtual void v47();
    virtual void v48(); virtual void v49(); virtual void v50(); virtual void v51();
    virtual void v52(); virtual void v53(); virtual void v54();
    virtual unsigned int v55(int a, int b);
};

struct Mid {
    char pad0[8];
    VtA* a;
    VtB* b;
    VtC* c;
};

struct Owner {
    char pad[0xd8];
    Mid* mid;
};

extern "C" {
void fn_123_F4C8(SonicF4C8*, int, float, float,
                 unsigned char, unsigned char, unsigned char, unsigned char);
void fn_27_19397C(void*, float, float, float, int);
extern const float lbl_123_rodata_60;
extern const float lbl_123_rodata_64;
}

extern "C" void fn_123_10888(void*, Owner* owner) {
    SonicF4C8 p18;
    SonicF4C8 p8;
    if (owner->mid->c->v55(4, 0) == 1U) {
        fn_123_F4C8(&p18, 0x1DB, lbl_123_rodata_60, lbl_123_rodata_64, 0, 0, 0, 0);
        owner->mid->a->v30(&p18);
    } else {
        fn_123_F4C8(&p8, 0x1DC, lbl_123_rodata_60, lbl_123_rodata_64, 0, 0, 0, 0);
        owner->mid->a->v30(&p8);
    }
    float x = owner->mid->b->v9();
    fn_27_19397C(owner, x, -x, lbl_123_rodata_64, 1);
}
