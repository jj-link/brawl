#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
void fn_73_34A4(void* a, int b);
void __ct__14snd3DGeneratorFv(void* a);
extern char lbl_73_data_3558[];
}

class Base {
public:
    int data[15];
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
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
};

class Derived : public Base {
public:
    virtual void f44(int);
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51();
    virtual void f52();
    virtual void f53();
    virtual void f54();
    virtual void f55();
    virtual void f56();
    virtual void f57();
    virtual void f58();
    virtual void f59();
    virtual void f60();
    virtual void f61();
    virtual void f62();
    virtual void f63();
    virtual void f64();
    virtual void f65();
    virtual void f66();
    virtual void f67();
    virtual void f68();
    virtual void f69();
    virtual void f70();
    virtual void f71();
    virtual void f72();
    virtual void f73();
    virtual void f74();
    virtual void f75();
    virtual void f76();
    virtual void f77();
    virtual void f78();
    virtual void f79();
    virtual void f80(int);
};

extern "C" void* fn_73_5CD8(void* a, void* b, void* c) {
    void* obj = __nw__FUlQ25Heaps8HeapType(0x2a4, 0xf);
    if (obj) {
        fn_73_34A4(obj, (int)c);
        *(void**)((char*)obj + 0x3c) = lbl_73_data_3558;
        __ct__14snd3DGeneratorFv((char*)obj + 0x29c);
        *(int*)((char*)obj + 0x294) = 0;
        *(int*)((char*)obj + 0x298) = 0;
    }
    if (obj) {
        ((Derived*)obj)->f44((int)a);
        ((Derived*)obj)->f80((int)b);
    }
    return obj;
}
