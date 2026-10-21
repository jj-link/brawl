#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_27_25EB9C(void*);
void fn_27_25EBB8(void*);
extern char lbl_27_data_546F8[];
extern char lbl_27_data_54748[];
extern void* lbl_27_bss_5B98;
}

struct Field4 {
    unsigned int hi : 14;
    unsigned int mid : 7;
    unsigned int lo : 11;
};

struct Obj27 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
};

extern "C" void fn_27_25E71C() {
    if (lbl_27_bss_5B98 == 0) {
        Obj27* obj = (Obj27*)__nw__FUlQ25Heaps8HeapType(0x194, 0xF);
        if (obj != 0) {
            *(char**)((char*)obj + 0x190) = lbl_27_data_546F8;
            *(char**)((char*)obj + 0x0) = lbl_27_data_54748;
            *(unsigned int*)((char*)obj + 4) |= 0xFFFC0000u;
            ((Field4*)((char*)obj + 4))->mid = -1;
            __construct_array((char*)obj + 8, fn_27_25EB9C, fn_27_25EBB8, 0xC, 0x20);
            obj->v8();
            *(int*)((char*)obj + 0x188) = 0x20;
            *(int*)((char*)obj + 0x18C) = 0;
        }
        lbl_27_bss_5B98 = obj;
    }
}
