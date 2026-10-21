#pragma force_active on
struct Modules;
class LookupModule {
public:
    virtual void e08(); virtual void e0C(); virtual void e10(); virtual void e14();
    virtual int get(int, Modules*);
};
class TargetModule {
public:
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3();
    virtual void a4(); virtual void a5(); virtual void a6(); virtual void a7();
    virtual void a8(); virtual void a9(); virtual void a10(); virtual void a11();
    virtual void a12(); virtual void a13(); virtual void a14(); virtual void a15();
    virtual void a16(); virtual void a17(); virtual void a18(); virtual void a19();
    virtual void a20(); virtual void a21(); virtual void a22(); virtual void a23();
    virtual void a24(); virtual void a25(); virtual void a26(); virtual void a27();
    virtual void a28(); virtual void a29(); virtual void a30(); virtual void a31();
    virtual void apply(int, void*);
};
struct Modules {
    unsigned char p0[0x64];
    LookupModule* lookup;
    unsigned char p1[0x20];
    TargetModule* target;
    LookupModule& getL() { return *lookup; }
    TargetModule& getT() { return *target; }
};
struct Object {
    unsigned char p[0xD8];
    Modules* modules;
};
extern "C" void fn_118_99DC(Object* object, int key, void* value) {
    Modules* m = object->modules;
    LookupModule* l = &m->getL();
    TargetModule* t = &m->getT();
    int r = l->get(key, m);
    if (r) {
        t->apply(r, value);
    }
}
