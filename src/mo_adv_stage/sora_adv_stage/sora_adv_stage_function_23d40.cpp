#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_27_269C40(void* self, const char* a, const char* name);
extern "C" char lbl_40_data_6728[];
extern "C" const float lbl_40_rodata_350;

struct Base {
    char pad[0x3c];
};

#define V(n) virtual void f##n();
#define VI(n) virtual void f##n(int);

struct Obj : Base {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41)
    VI(42)
};

extern "C" void* fn_40_23D40(int arg0, const char* arg1, const char* arg2) {
    char* p = (char*)__nw__FUlQ25Heaps8HeapType(0x1a4, 0xf);
    if (p != 0) {
        fn_27_269C40(p, arg1, arg2);
        *(void**)(p + 0x3c) = (void*)lbl_40_data_6728;
        *(float*)(p + 0x160) = lbl_40_rodata_350;
        *(int*)(p + 0x164) = 0;
        *(int*)(p + 0x190) = 0;
        *(int*)(p + 0x194) = 0;
        *(int*)(p + 0x198) = 0;
        *(int*)(p + 0x19c) = 0;
        *(int*)(p + 0x1a0) = 0;
    }
    if (p != 0) {
        ((Obj*)p)->f42(arg0);
    }
    return p;
}
