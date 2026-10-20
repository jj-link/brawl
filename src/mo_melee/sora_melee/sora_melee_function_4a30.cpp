#pragma force_active on
extern "C" {
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
}

struct Thing {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
};

extern "C" void fn_27_4A30(void* object) {
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }

    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        void* a = *reinterpret_cast<void**>(static_cast<unsigned char*>(object) + 0x60);
        void* b = *reinterpret_cast<void**>(static_cast<unsigned char*>(a) + 0xd8);
        void* c = *reinterpret_cast<void**>(static_cast<unsigned char*>(b) + 0x44);
        static_cast<Thing*>(c)->f13();
    }
}
