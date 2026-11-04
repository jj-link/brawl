#pragma force_active on

class Class_6EB8 {
public:
    virtual void fn_116_DEEC();
    virtual void fn_116_DD40();
    virtual void fn_116_DD48();
    virtual void fn_116_DD44();
    virtual void fn_116_DEE8();
    virtual void fn_116_DEE4();
    virtual void fn_116_DEE0();
    virtual void fn_116_DEDC(int);
    virtual void fn_116_DED8();
    virtual void fn_116_DED0();
    virtual void fn_116_DECC();
    virtual void fn_116_DEC4();
    virtual void fn_116_DEC0();
    virtual void fn_116_DEB8();
};

class Class_7624 {
public:
    virtual void fn_116_7384();
    virtual void fn_116_101BC();
    virtual Class_6EB8** fn_116_11518(int);
    virtual void fn_116_11510();
    virtual int fn_116_11508();
    virtual void fn_116_11500();
    virtual void fn_116_114F8();
    virtual void fn_116_114F0();
    virtual void fn_116_114E8();
    virtual void fn_116_114E0();
    virtual void fn_116_114D8();
    virtual void fn_116_114D0();
    virtual void fn_116_114C8();
    virtual void fn_116_114C0();
};

class Obj2 {
public:
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
    virtual void m13(int, float);
};

class Middle {
public:
    char pad[0x64];
    Obj2* obj;
};

class Outer {
public:
    char pad[0xd8];
    Middle* mid;
};

extern "C" Class_7624* fn_116_9570(void*);
extern "C" void fn_27_12BAF8(void*, int);
extern "C" void fn_27_3689A4(void*);

extern "C" void fn_116_1F58C(void* self, int arg1) {
    char* s = (char*)self;
    int val;
    int i;
    Class_7624* mgr;
    Outer* outer = *(Outer**)(s + 0x60);
    fn_27_12BAF8(self, arg1);
    val = *(int*)(s + 0x28);
    mgr = fn_116_9570(s + 0x11130);
    i = 0;
    Class_6EB8* p;
    while (i < mgr->fn_116_11508()) {
        p = *mgr->fn_116_11518(i);
        p->fn_116_DEDC(val);
        i += 1;
    }
    if (arg1 != 6 && arg1 != 7) {
        fn_27_3689A4(s + 0x11118);
    }
    float f1a = *(float*)(s + 0x11124);
    Obj2* obj = outer->mid->obj;
    obj->m13(0x11000013, f1a);
    float f1b = *(float*)(s + 0x1112c);
    obj = outer->mid->obj;
    obj->m13(0x11000014, f1b);
}