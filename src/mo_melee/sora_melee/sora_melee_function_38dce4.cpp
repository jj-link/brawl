#pragma force_active on
namespace {
class ObjA {
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
    virtual int s9() = 0;
};
class ObjB {
public:
    virtual void s0() = 0;
    virtual void s1() = 0;
    virtual void s2() = 0;
    virtual void s3() = 0;
    virtual int s4(unsigned int, void*) = 0;
};
}

extern "C" {
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
void fn_27_38DDBC(void*);
void fn_27_38E55C(void*);
void fn_27_1DA030(void*);

void fn_27_38DCE4(void* object) {
    unsigned char* accesser = *reinterpret_cast<unsigned char**>(static_cast<unsigned char*>(object) + 0x60);
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BEA8(lbl_27_bss_F0) == 1) {
        if ((*reinterpret_cast<ObjA**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x44))->s9() == 0) {
            if ((*reinterpret_cast<ObjB**>(*reinterpret_cast<unsigned char**>(accesser + 0xd8) + 0x64))->s4(0x10000005, *reinterpret_cast<void**>(accesser + 0xd8)) == 2) {
                fn_27_38DDBC(object);
            }
            fn_27_38E55C(object);
        }
    }
    fn_27_1DA030(object);
}
}
