#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void __ct__9grGimmickFPCc(void*, const char*);
extern "C" unsigned char lbl_40_data_3AD8[];

struct Gimmick {
    unsigned char padding[0x3C];
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void a5();
    virtual void a6();
    virtual void a7();
    virtual void a8();
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual void a14();
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42(int);
};

extern "C" Gimmick* fn_40_19740(int param0, const char* name) {
    Gimmick* obj = (Gimmick*)__nw__FUlQ25Heaps8HeapType(0x160, 0xF);
    if (obj) {
        __ct__9grGimmickFPCc(obj, name);
        *(void**)((char*)obj + 0x3C) = lbl_40_data_3AD8;
        *(int*)((char*)obj + 0x14C) = 0;
        *(int*)((char*)obj + 0x150) = 0;
        *(int*)((char*)obj + 0x154) = 0;
        *(int*)((char*)obj + 0x158) = 0;
        *(int*)((char*)obj + 0x15C) = 0;
        *(unsigned char*)((char*)obj + 0x6C) |= 1;
        *(int*)((char*)obj + 0xE4) = 0;
    }
    if (obj) {
        obj->a42(param0);
    }
    return obj;
}
