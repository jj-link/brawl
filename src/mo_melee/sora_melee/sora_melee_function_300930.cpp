#pragma force_active on

extern "C" void fn_27_303B3C(void*, void*, void*, void*);

struct GfTaskBase {
    char pad[0x3c];
};

class GfTaskLike : public GfTaskBase {
public:
    virtual void s00();
    virtual void s01();
    virtual void s02();
    virtual void s03();
    virtual void s04();
    virtual void s05();
    virtual void s06();
    virtual void s07();
    virtual void s08();
    virtual void s09();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
};

class CallObj {
public:
    virtual void v0();
    virtual void v1();
    virtual void* call(void*);
};

class CallObj2 {
public:
    virtual void v0();
    virtual void v1();
    virtual void* call();
};

extern "C" int fn_27_300930(int, void* arg2, void* arg3, void* arg4) {
    ((GfTaskLike*)(*(void**)((char*)arg3 + 8)))->s40();
    void* inner = *(void**)((char*)arg3 + 0xd8);
    CallObj* obj = *(CallObj**)((char*)inner + 0x18);
    void* gfTask = *(void**)((char*)arg3 + 8);
    void* field28 = *(void**)((char*)gfTask + 0x28);
    void* result = obj->call(gfTask);
    result = ((CallObj2*)result)->call();
    fn_27_303B3C(arg2, field28, arg4, result);
    return 1;
}