#pragma force_active on
namespace {
class ModuleA {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual int slot2C() = 0;
};

class ModuleB {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual int slot18(int) = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28(int) = 0;
};
}

extern "C" {
void fn_27_12DCA8(void*);
void fn_96_1DC44(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
extern void* lbl_27_bss_F0;
}

extern "C" void fn_96_D954(void* self) {
    unsigned char* base = static_cast<unsigned char*>(self);
    fn_27_12DCA8(self);
    fn_96_1DC44(base + 0x1B72C);
    base[0x1B68D] = 0;
    base[0x1B68C] = 0;
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) != 1) {
        return;
    }
    if ((*reinterpret_cast<ModuleA**>(*reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(base + 0x60) + 0xD8) + 0x44))->slot2C() != 0) {
        return;
    }
    if ((*reinterpret_cast<ModuleB**>(*reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(base + 0x60) + 0xD8) + 0x64))->slot18(0x1000004C) > 0) {
        (*reinterpret_cast<ModuleB**>(*reinterpret_cast<unsigned char**>(*reinterpret_cast<unsigned char**>(base + 0x60) + 0xD8) + 0x64))->slot28(0x1000004C);
    }
}
