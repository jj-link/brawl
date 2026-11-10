#pragma force_active on

struct Pair {
    unsigned int a, b;
    Pair& operator=(const Pair& p) {
        a = p.a;
        b = p.b;
        return *this;
    }
};

struct Skip {
    unsigned int a, b;
    Skip& operator=(const Skip&) { return *this; }
};

struct Small {
    unsigned int a, b;
};

struct Tail {
    Pair pairs[7];
};

struct Element {
    int a0, a1;
    Small c;
    int d;
    float a5;
    int a6, a7, a8, a9;
    float a10, a11, a12;
    int a13, a14, a15, a16;
    Skip skip;
    int b0;
    Tail tail;
    int b2, b3;
};

class ClassA {
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
    virtual Element* get();
};

class ClassB {
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
    virtual Element* get(int);
};

extern "C" void fn_62_79D8(ClassA* self, int, int arg2) {
    Element* src = self->get();
    Element* dst = ((ClassB*)self)->get(arg2);
    *dst = *src;
}
