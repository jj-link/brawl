#pragma force_active on

struct Base {
    unsigned char padding[0x3C];
};

struct Obj : Base {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void setValue(int);
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_40_19B44(void*, const char*);
extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(int, unsigned long);
extern "C" void gfMemFill__FPvUcUl(void*, unsigned char, unsigned long);
extern "C" unsigned char lbl_40_data_B9D8[];

extern "C" Obj* fn_40_2E29C(int arg0, const char* name) {
    Obj* obj = (Obj*)__nw__FUlQ25Heaps8HeapType(0x158, 15);
    if (obj) {
        fn_40_19B44(obj, name);
        *(void**)((unsigned char*)obj + 0x3C) = lbl_40_data_B9D8;
        *(short*)((unsigned char*)obj + 0x150) = 0x14;
        *(short*)((unsigned char*)obj + 0x152) = 0;
        void* buf = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUl(15, 0x1e0);
        *(void**)((unsigned char*)obj + 0x154) = buf;
        gfMemFill__FPvUcUl(buf, 0, 0x1e0);
    }
    if (obj) {
        obj->setValue(arg0);
    }
    return obj;
}
