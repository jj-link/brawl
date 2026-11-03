#pragma force_active on
class Class_70AC {
public:
    virtual void fn_123_6E08();
    virtual void fn_123_12D4C();
    virtual void fn_123_14120();
    virtual void fn_123_14118();
    virtual void fn_123_14110();
    virtual void fn_123_14108();
    virtual void fn_123_14100();
    virtual void fn_123_140F8();
    virtual void fn_123_140F0();
    virtual void fn_123_140E8();
    virtual void fn_123_140E0();
    virtual void fn_123_140D8();
    virtual void fn_123_140D0();
    virtual void fn_123_140C8();
    virtual void fn_123_14078();
    virtual void fn_123_140C0();
    virtual int fn_123_140B0();
    virtual void fn_123_140A0();
    virtual void fn_123_14090();
    virtual void fn_123_14080();
};
class Work {
public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual int get(int);
    virtual void set(int, int);
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void off(int);
};
struct Modules {
    char pad[0x64];
    Work* work;
    char pad68[8];
    Class_70AC* status;
};
struct Fighter {
    char pad[0xd8];
    Modules* modules;
};
struct Context {
    char pad[0x60];
    Fighter* fighter;
};
extern "C" void fn_27_131CD0(void*, int, int, int);
extern "C" void fn_123_9944(Context* self, int a, int b, int c) {
    int value = self->fighter->modules->work->get(0x10000001);
    fn_27_131CD0(self, a, b, c);
    switch (self->fighter->modules->status->fn_123_140B0()) {
    case 0x11d:
    case 0x11e:
    case 0x11f:
    case 0x120:
    case 0x122:
    case 0x124:
    case 0x125:
        self->fighter->modules->work->set(value, 0x10000001);
        break;
    }
    if (a == 3)
        self->fighter->modules->work->off(0x1200003d);
}