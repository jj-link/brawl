#pragma force_active on

class A {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void* call(void* arg) = 0;
};

class B {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void* call() = 0;
};

struct Obj {
    char pad1[0x8];
    void* unk8;
    char pad2[0xCC];
    void* unkD8;
};

extern "C" void fn_27_3455B0(void*, void*, void*, void*);

extern "C" int fn_27_33C9D0(int, void* arg2, Obj* obj, void* arg4) {
    void* p = obj->unk8;
    void* t = *(void**)((char*)p + 0x28);
    A* a = *(A**)((char*)obj->unkD8 + 0x18);
    void* r = a->call(p);
    r = ((B*)r)->call();
    fn_27_3455B0(arg2, t, arg4, r);
    return 1;
}
