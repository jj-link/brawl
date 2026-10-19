#pragma force_active on
struct Pair {
    void* a;
    void* b;
};

class Iface {
public:
    virtual void v0() {}
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void v6() {}
    virtual void v7() {}
    virtual void v8() {}
    virtual void v9() {}
    virtual void v10() {}
    virtual void v11() {}
    virtual void v12() {}
    virtual Pair get(short* s);
};

extern "C" void fn_122_1D0D4(void* obj, Pair* p);

extern "C" int fn_122_E010(void* obj, void* arg) {
    short flag = 1;
    char* p = (char*)arg;
    void* o = *(void**)(p + 0xd8);
    Iface* o2 = (Iface*)*(void**)((char*)o + 0x7c);
    Pair r = o2->get(&flag);
    fn_122_1D0D4(obj, &r);
    return 1;
}
