#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern char lbl_80462B60[];
extern char lbl_80462B88[];
extern void* lbl_805A0468;

struct Base { char pad[0x3C]; };
struct Task : Base {
    virtual void v0();virtual void v1();virtual void v2();virtual void v3();
    virtual void v4();virtual void v5();virtual void v6();virtual void v7();
    virtual void v8();virtual void v9();virtual void v10();virtual void v11();
    virtual void v12();virtual void v13();virtual void v14();virtual void v15();
    virtual void v16();virtual void v17();virtual void v18();virtual void v19();
    virtual void v20();virtual void init();
    char pad2[8];
    bool flag;
};

class adAutoSave {
public:
    static adAutoSave* create(bool);
};

adAutoSave* adAutoSave::create(bool b) {
    if (lbl_805A0468 != 0) return 0;
    Task* t = (Task*)__nw__FUlQ25Heaps8HeapType(0x50, 0xC);
    if (t) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(t, lbl_80462B60, 0, 0xE, 6, true);
        *(char**)((char*)t + 0x3C) = lbl_80462B88;
    }
    lbl_805A0468 = t;
    t->init();
    ((Task*)lbl_805A0468)->flag = b;
    return (adAutoSave*)lbl_805A0468;
}
