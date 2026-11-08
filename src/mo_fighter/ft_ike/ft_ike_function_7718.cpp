#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual void slot5(int, unsigned int);
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
void fn_27_12E7C8(void*);
}

extern "C" void fn_119_7718(void* object) {
    unsigned char* accesser = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x60);
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        if ((*reinterpret_cast<Object_vptr_0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x44))->slot9() == 0) {
            if ((*reinterpret_cast<Object_vptr_0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x14))->slot3() == 0) {
                (*reinterpret_cast<Object_vptr_0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x64))->slot5(0, 0x10000040);
            }
        }
    }
    fn_27_12E7C8(object);
}
