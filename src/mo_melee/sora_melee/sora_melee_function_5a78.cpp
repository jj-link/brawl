#pragma force_active on
namespace {
struct V8Base { char _pad[8]; };
class V8 : public V8Base {
public:
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void s10() = 0;
};
class V0 {
public:
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual void s4() = 0;
    virtual void s5() = 0;
    virtual void s6() = 0;
    virtual void s7() = 0;
    virtual void s8() = 0;
    virtual void s9() = 0;
    virtual void s10() = 0;
    virtual void s11() = 0;
    virtual void s12() = 0;
    virtual void s13() = 0;
    virtual void s14() = 0;
    virtual void s15() = 0;
    virtual void s16() = 0;
    virtual void s17() = 0;
    virtual void s18() = 0;
    virtual void s19() = 0;
    virtual void s20() = 0;
    virtual void s21() = 0;
    virtual void s22() = 0;
    virtual void s23() = 0;
    virtual void s24() = 0;
    virtual void s25() = 0;
    virtual void s26() = 0;
    virtual void s27() = 0;
    virtual void s28() = 0;
    virtual void s29() = 0;
    virtual void s30() = 0;
    virtual void s31() = 0;
    virtual void s32() = 0;
    virtual void s33() = 0;
    virtual void s34() = 0;
    virtual void s35() = 0;
    virtual void s36() = 0;
    virtual void s37() = 0;
    virtual void s38() = 0;
    virtual void s39() = 0;
    virtual void s40() = 0;
    virtual void s41() = 0;
    virtual void s42() = 0;
    virtual void s43() = 0;
    virtual void s44() = 0;
    virtual void s45() = 0;
    virtual void s46() = 0;
    virtual void s47() = 0;
    virtual void s48() = 0;
    virtual void s49() = 0;
    virtual void s50() = 0;
    virtual void s51() = 0;
    virtual void s52() = 0;
    virtual void s53() = 0;
    virtual void s54() = 0;
    virtual void s55() = 0;
    virtual void s56() = 0;
};
}

extern "C" {
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);

void fn_27_5A78(void* object) {
    unsigned char* accesser = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x60);
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BEA8(lbl_27_bss_F0) == 1) {
        (*reinterpret_cast<V8**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x38))->s9();
        (*reinterpret_cast<V0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x40))->s4();
        (*reinterpret_cast<V0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x3c))->s4();
        (*reinterpret_cast<V8**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0xbc))->s6();
        (*reinterpret_cast<V0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x24))->s30();
        (*reinterpret_cast<V0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x28))->s30();
        (*reinterpret_cast<V0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x2c))->s30();
        (*reinterpret_cast<V0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x20))->s44();
        (*reinterpret_cast<V8**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x38))->s10();
        (*reinterpret_cast<V0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x30))->s15();
        (*reinterpret_cast<V0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x1c))->s56();
        (*reinterpret_cast<V0**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x34))->s13();
    }
}
}