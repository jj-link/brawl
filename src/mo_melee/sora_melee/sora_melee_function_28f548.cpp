#pragma force_active on

typedef int s32;
typedef float f32;

extern "C" const float lbl_27_rodata_4610;

class SubObj {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8();
    virtual int check(int);
    virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13();
    virtual void v14(); virtual void v15(); virtual void v16(); virtual void v17();
    virtual void v18(); virtual void v19(); virtual void v20(); virtual void v21();
    virtual void v22(); virtual void v23(); virtual void v24(); virtual void v25();
    virtual void v26(); virtual void v27(); virtual void v28(); virtual void v29();
    virtual void v30(); virtual void v31(); virtual void v32(); virtual void v33();
    virtual void v34(); virtual void v35(); virtual void v36(); virtual void v37();
    virtual void v38(); virtual void v39();
    virtual float get(int);
};

struct NonPolyBase {
    int a;
    int b;
};

class TargetObj : public NonPolyBase {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25();
    virtual void call(void*, int, float, float);
};

struct MainObj {
    unsigned char pad1[0x8D0];
    TargetObj* target;
    unsigned char pad2[0x27A8 - 0x8D4];
    SubObj sub;
};

extern "C" void fn_27_28F548(MainObj* arg0, int arg1, float farg0, float farg1) {
    if (lbl_27_rodata_4610 == farg0) {
        if (arg0->sub.check(3)) {
            farg0 = arg0->sub.get(3);
        }
    }
    arg0->target->call(arg0, arg1, farg0, farg1);
}
