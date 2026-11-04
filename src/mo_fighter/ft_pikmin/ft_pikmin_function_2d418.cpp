#include <so/so_module_accesser.h>
#pragma force_active on
class Class_7D6C {
public:
    virtual void fn_113_80F4();
    virtual void fn_113_15588();
    virtual void fn_113_1BDC0();
    virtual void fn_113_1BDBC();
    virtual void fn_113_1BDB8();
    virtual void fn_113_1BDB4();
    virtual void fn_113_1BDAC();
    virtual void fn_113_1BDF4();
    virtual void fn_113_1BDEC();
    virtual int fn_113_1BDE4();
    virtual void fn_113_1BDDC();
    virtual void fn_113_1BDD4();
    virtual void fn_113_1BD6C();
    virtual void fn_113_1BDA0();
    virtual void fn_113_1BD94();
    virtual void fn_113_1BD8C();
    virtual void fn_113_1BD80();
};
class Class_7FE8 {
public:
    virtual void fn_113_80F4();
    virtual void fn_113_1552C();
    virtual void fn_113_1C084();
    virtual void fn_113_1C07C();
    virtual void fn_113_1C074();
    virtual void fn_113_1C06C();
    virtual void fn_113_1C064();
    virtual void fn_113_1C05C();
    virtual void fn_113_1C054();
    virtual void fn_113_1C04C();
    virtual void fn_113_1C044();
    virtual void fn_113_1C03C();
    virtual void fn_113_1C034();
    virtual void fn_113_1C02C();
    virtual void fn_113_1BFDC();
    virtual void fn_113_1C024();
    virtual int fn_113_1C014();
};
extern "C" {
extern void* lbl_27_bss_F0;
void fn_27_1DA038(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_113_2DCE4(soModuleAccesser*);
}
extern "C" void fn_113_2D418(void* self) {
    fn_27_1DA038(self);
    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (p) p = fn_27_5BCD0(p);
        lbl_27_bss_F0 = p;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
        if (!(*(soModuleAccesser**)((char*)self + 0x60))->getStopModule().isStop()) {
            switch ((*(soModuleAccesser**)((char*)self + 0x60))->getStatusModule().getStatusKind()) {
            case 1:
            case 2:
            case 3:
            case 6:
            case 7:
                fn_113_2DCE4(*(soModuleAccesser**)((char*)self + 0x60));
                break;
            }
        }
    }
}