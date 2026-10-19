#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

class Obj {
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
    virtual void call(int, void*);
};

extern "C" void fn_110_18BB8(void* a, void* b) {
    Obj* obj = *(Obj**)((char*)b + 0xd8);
    Obj* o2 = *(Obj**)((char*)obj + 0x54);
    struct {
        u32 x;
        u8 y;
    } loc;
    loc.x = 0x83c;
    loc.y = 0;
    o2->call(3, &loc);
}
