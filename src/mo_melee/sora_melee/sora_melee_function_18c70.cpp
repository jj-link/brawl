#pragma force_active on
#pragma optimize_for_size off
#pragma optimization_level 2

struct Vec3;

struct Pair {
    int x, y;
};

struct Result {
    int a;
    Pair b;
    int c;
    Pair d;
    int e;
    Pair f, g, h, i, j, k;
};

class Inner {
public:
    char pad[8];

    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual int f34(int);
};

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C();
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual Result& fn_27_14A60(Result&, int);
};

struct InnerHolder {
    char pad[4];
    Inner* inner;
};

struct Container {
    char pad[0xd8];
    InnerHolder* holder;

    int get(int n) {
        return holder->inner->f34(n);
    }
};

struct Arg {
    char pad0[0x3c];
    Class_1250* p;
    char pad40[0x128];
    Container* q;

    Class_1250* getP() const {
        return p;
    }
};

extern "C" void fn_80195708(void*, Vec3*);

extern "C" void fn_27_18C70(Vec3* out, const Arg* arg, int n) {
    Container* q = arg->q;
    Class_1250* p = arg->getP();
    Result r;
    Result* v = &p->fn_27_14A60(r, q->get(n));
    if (v != &r) {
        r = *v;
        v = &r;
    }
    fn_80195708(v, out);
}
