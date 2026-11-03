#pragma force_active on

extern "C" {
void fn_27_12DCA8(void*);
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
float fn_118_95F0(void*);
void* fn_118_8E00();
void fn_118_8EE4(void*);
void fn_118_8FA0(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_118_data_600[];
extern char lbl_118_data_2250[];
}

class Class_63D0 {
public:
    virtual void fn_118_D9F0();
    virtual void fn_118_D72C();
    virtual void fn_118_D92C();
    virtual void fn_118_D9EC();
    virtual void fn_118_D9E8();
    virtual void fn_118_D9E4();
    virtual void fn_118_D9E0();
    virtual void fn_118_D790();
    virtual void fn_118_D9DC();
    virtual void fn_118_D94C();
    virtual void fn_118_D9D8();
    virtual void fn_118_D9D0();
    virtual float fn_118_D9CC(unsigned int);
    virtual void fn_118_D9C4(float, unsigned int);
};

class Class_8E00 {
public:
    virtual void fn_118_A0();
    virtual void fn_118_A1();
    virtual void fn_118_A2();
    virtual void fn_118_unk14(void*);
};

extern "C" void fn_118_9068(void* self) {
    Class_63D0* r30;
    void* r29;
    fn_27_12DCA8(self);
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        r29 = *(void**)((unsigned char*)self + 0x60);
        r30 = *(Class_63D0**)((unsigned char*)*(void**)((unsigned char*)r29 + 0xD8) + 0x64);
        float v = r30->fn_118_D9CC(0x11000013);
        r30->fn_118_D9C4(v, 0x11000014);
        float f = fn_118_95F0(r29);
        r30->fn_118_D9C4(f, 0x11000013);
        r30 = (Class_63D0*)__dynamic_cast(*(void**)((unsigned char*)r29 + 0x8), 0x3C, lbl_118_data_600, lbl_118_data_2250, 1);
        Class_63D0* r28 = *(Class_63D0**)((unsigned char*)*(void**)((unsigned char*)r29 + 0xD8) + 0x64);
        float f31 = r28->fn_118_D9CC(0x11000014);
        float f1 = r28->fn_118_D9CC(0x11000013);
        if (f1 != f31) {
            fn_118_8EE4(r30);
            fn_118_8FA0(r30);
            r28->fn_118_D9C4(f1, 0x11000014);
        }
        Class_8E00* h = (Class_8E00*)fn_118_8E00();
        h->fn_118_unk14(r29);
    }
}
