#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_48_1F28(void*, const char*);
void __construct_array(void*, void*, void*, unsigned long, unsigned long);
void __ct__14snd3DGeneratorFv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void* memset(void*, int, unsigned long);
extern unsigned char lbl_48_data_AF8[];
}

struct Base {
    unsigned char pad[0x3C];
};

class Ground : public Base {
public:
    virtual void f0() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void f6() = 0;
    virtual void f7() = 0;
    virtual void f8() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void f15() = 0;
    virtual void f16() = 0;
    virtual void f17() = 0;
    virtual void f18() = 0;
    virtual void f19() = 0;
    virtual void f20() = 0;
    virtual void f21() = 0;
    virtual void f22() = 0;
    virtual void f23() = 0;
    virtual void f24() = 0;
    virtual void f25() = 0;
    virtual void f26() = 0;
    virtual void f27() = 0;
    virtual void f28() = 0;
    virtual void f29() = 0;
    virtual void f30() = 0;
    virtual void f31() = 0;
    virtual void f32() = 0;
    virtual void f33() = 0;
    virtual void f34() = 0;
    virtual void f35() = 0;
    virtual void f36() = 0;
    virtual void f37() = 0;
    virtual void f38() = 0;
    virtual void f39() = 0;
    virtual void f40() = 0;
    virtual void f41() = 0;
    virtual void f42(int) = 0;
    virtual void f43() = 0;
    virtual void f44() = 0;
    virtual void f45() = 0;
    virtual void f46() = 0;
    virtual void f47() = 0;
    virtual void f48() = 0;
    virtual void f49() = 0;
    virtual void f50() = 0;
    virtual void f51() = 0;
    virtual void f52() = 0;
    virtual void f53() = 0;
    virtual void f54() = 0;
    virtual void f55() = 0;
    virtual void f56() = 0;
    virtual void f57() = 0;
    virtual void f58() = 0;
    virtual void f59() = 0;
    virtual void f60() = 0;
    virtual void f61() = 0;
    virtual void f62() = 0;
    virtual void f63() = 0;
    virtual void f64() = 0;
    virtual void f65() = 0;
    virtual void f66() = 0;
    virtual void f67() = 0;
    virtual void f68() = 0;
    virtual void f69() = 0;
    virtual void f70() = 0;
    virtual void f71() = 0;
    virtual void f72() = 0;
    virtual void f73() = 0;
    virtual void f74() = 0;
    virtual void f75() = 0;
    virtual void f76() = 0;
    virtual void f77() = 0;
    virtual void f78(const char*) = 0;
};

extern "C" Ground* fn_48_2070(int arg0, const char* arg1, const char* arg2) {
    Ground* p = (Ground*)__nw__FUlQ25Heaps8HeapType(0x1DC, 15);
    if (p) {
        fn_48_1F28(p, arg2);
        *(void**)((char*)p + 0x3C) = (void*)lbl_48_data_AF8;
        __construct_array((char*)p + 0x194, (void*)__ct__14snd3DGeneratorFv, (void*)__dt__14snd3DGeneratorFv, 8, 6);
        *(int*)((char*)p + 0x158) = 0;
        *(int*)((char*)p + 0x15C) = 0;
        memset((char*)p + 0x160, 0, 0x30);
        *(unsigned char*)((char*)p + 0x190) = 0;
        *(unsigned char*)((char*)p + 0x191) = 1;
        *(int*)((char*)p + 0x1C4) = -1;
        *(int*)((char*)p + 0x1C8) = -1;
        *(int*)((char*)p + 0x1CC) = -1;
        *(int*)((char*)p + 0x1D0) = -1;
        *(int*)((char*)p + 0x1D4) = -1;
        *(int*)((char*)p + 0x1D8) = -1;
    }
    if (p) {
        p->f42(arg0);
        p->f78(arg1);
    }
    return p;
}
