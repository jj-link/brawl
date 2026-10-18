#pragma force_active on
namespace {
class Mod70 {
public:
    virtual void s00() = 0;
    virtual void s04() = 0;
    virtual void s08() = 0;
    virtual void s0C() = 0;
    virtual void s10() = 0;
    virtual void s14() = 0;
    virtual void s18() = 0;
    virtual void s1C() = 0;
    virtual void s20() = 0;
    virtual void s24() = 0;
    virtual void s28() = 0;
    virtual void s2C() = 0;
    virtual void s30() = 0;
    virtual void s34() = 0;
    virtual void s38() = 0;
    virtual void s3C() = 0;
    virtual void s40() = 0;
    virtual void s44() = 0;
    virtual void s48() = 0;
    virtual void process() = 0;
};
class Mod3C {
public:
    virtual void s00() = 0;
    virtual void s04() = 0;
    virtual void s08() = 0;
    virtual void s0C() = 0;
    virtual void s10() = 0;
    virtual void s14() = 0;
    virtual void s18() = 0;
    virtual void s1C() = 0;
    virtual void s20() = 0;
    virtual void s24() = 0;
    virtual void s28() = 0;
    virtual void s2C() = 0;
    virtual void s30() = 0;
    virtual void s34() = 0;
    virtual void s38() = 0;
    virtual unsigned int getKind() = 0;
};
}

extern "C" {
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);

void fn_27_5C04(void* object) {
    unsigned char* accesser = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x60);
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BEA8(lbl_27_bss_F0) == 1) {
        Mod70* m70 = *reinterpret_cast<Mod70**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x70);
        m70->process();
        Mod3C* m3c = *reinterpret_cast<Mod3C**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x3c);
        if (m3c->getKind() == 1) {
            return;
        }
    }
}
}
