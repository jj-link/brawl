#pragma force_active on

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void fn_70_2C28(void*, void*);
extern char lbl_70_data_14FC[];
}

struct Base {
    char pad[0x3c];
};

#define V(n) virtual void f##n(int);

struct Obj : Base {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7) V(8) V(9)
    V(10) V(11) V(12) V(13) V(14) V(15) V(16) V(17) V(18) V(19)
    V(20) V(21) V(22) V(23) V(24) V(25) V(26) V(27) V(28) V(29)
    V(30) V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38) V(39)
    V(40) V(41) V(42) V(43) V(44) V(45) V(46) V(47) V(48) V(49)
    V(50) V(51) V(52) V(53) V(54) V(55) V(56) V(57) V(58) V(59)
    V(60) V(61) V(62) V(63) V(64) V(65) V(66) V(67) V(68) V(69)
    V(70) V(71) V(72) V(73) V(74) V(75) V(76) V(77) V(78)
};

extern "C" void* fn_70_5960(int a, int b, void* c) {
    Obj* p = (Obj*)__nw__FUlQ25Heaps8HeapType(0x1D0, 0xF);
    if (p != 0) {
        fn_70_2C28(p, c);
        *(void**)((char*)p + 0x3c) = (void*)lbl_70_data_14FC;
        *((char*)p + 0x1CC) = 0;
    }
    if (p != 0) {
        p->f42(a);
        p->f78(b);
    }
    return p;
}
