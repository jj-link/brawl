#pragma force_active on
extern "C" float lbl_27_rodata_6580;

class A {
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
    virtual int checkFlag(unsigned int);
    virtual void v18();
    virtual int clearFlag(unsigned int);
};

class B {
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
    virtual void setParam(int, void*, int);
    virtual void v17();
    virtual void v18();
    virtual int getParam(int);
};

class C {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void call(int, int, int);
};

class D {
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
    virtual void fire(int, int, int, int, int);
};

struct EBase { char pad[0x3c]; };
class E : public EBase {
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
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual int getStatus();
};

struct FBase { char pad[8]; };
class F : public FBase {
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
    virtual int get(int);
};

struct Args1 {
    int a;
    char b;
};

struct Args2 {
    int a;
    char b;
    int c;
    int d;
    int e;
    int f;
    float g;
    char h;
};

extern "C" void fn_27_307B54(void* arg1, void* arg2) {
    void* d8 = *(void**)((char*)arg2 + 0xd8);
    C* r30 = *(C**)((char*)d8 + 0x84);
    D* r29 = *(D**)((char*)d8 + 0x1c);
    A* r28 = *(A**)((char*)d8 + 0x64);
    B* r27 = *(B**)((char*)d8 + 0x54);

    if (r28->checkFlag(0x22000012)) {
        Args1 s1;
        s1.a = 0x1d;
        s1.b = 0;
        r27->setParam(0, &s1, 0);
        r28->clearFlag(0x22000012);
    }
    if (r28->checkFlag(0x22000013)) {
        E* e = *(E**)((char*)arg2 + 8);
        int r = e->getStatus();
        int var4 = 0;
        if (r == 4) {
            var4 = 1;
        } else if (r == 5) {
            var4 = 0xd;
        }
        r30->call(var4, 0, 0);
        int t = r27->getParam(0);
        Args2 s2;
        s2.a = 0x1e;
        s2.b = 0;
        s2.c = -1;
        s2.d = -1;
        s2.e = -1;
        s2.f = -1;
        s2.g = lbl_27_rodata_6580;
        s2.h = 1;
        r27->setParam(0, &s2, 0);
        void* d8b = *(void**)((char*)arg2 + 0xd8);
        F* f = *(F**)((char*)d8b + 4);
        int r8c = f->get(0x12c);
        r29->fire(0, r8c, t, s2.d, s2.e);
        r28->clearFlag(0x22000013);
    }
}
