#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual int slot9();
};
extern "C" {
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_27_1D9FF8(void*);
void fn_27_38E0A8(void*);
void fn_27_38DC40(void* object) {
    unsigned char* accesser = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x60);
    fn_27_1D9FF8(object);
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        if ((*reinterpret_cast<Object_vptr_0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x44))->slot9() == 0) {
            fn_27_38E0A8(object);
        }
    }
}
}