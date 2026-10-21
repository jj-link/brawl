#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

class Obj1 {
public:
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
};

class Obj2 {
public:
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
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33(int);
    virtual void v34(int);
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45(int);
    virtual u32 v46();
};

struct Outer {
    char pad0[0x27fc];
    Obj1 a;
    char pad1[0x38cc - 0x2800];
    Obj2 b;
    char pad2[0x3d26 - 0x38d0];
    bool flag;
};

extern "C" void fn_27_28509C(Outer* self, int arg1) {
    self->a.v7();
    if (self->b.v46() != 1) {
        self->b.v45(1);
        self->b.v33(arg1);
    }
    self->flag = arg1 == 0;
    self->b.v34(self->flag);
}
