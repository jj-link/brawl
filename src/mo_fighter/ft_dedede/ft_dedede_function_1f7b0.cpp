#include <so/so_module_accesser.h>

namespace {
// The combo state has eight bytes of non-polymorphic prefix before its table.
struct ComboStatePrefix {
    unsigned int fields[2];
};
class ComboState : public ComboStatePrefix {
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
public:
    virtual unsigned int getKind() = 0;
};
class ComboModule {
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4C() = 0;
    virtual void slot50() = 0;
    virtual void slot54() = 0;
    virtual void slot58() = 0;
    virtual void slot5C() = 0;
    virtual void slot60() = 0;
    virtual void slot64() = 0;
    virtual void slot68() = 0;
    virtual void slot6C() = 0;
    virtual void slot70() = 0;
    virtual void slot74() = 0;
public:
    virtual ComboState* getState() = 0;
};
}

extern "C" {
void fn_27_1DA034(void*);
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
}

extern "C" void fn_117_1F7B0(void* object) {
    fn_27_1DA034(object);
    soModuleAccesser* accesser = *reinterpret_cast<soModuleAccesser**>(static_cast<unsigned char*>(object) + 0x60);
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (singleton != 0) {
            singleton = fn_27_5BCD0(singleton);
        }
        lbl_27_bss_F0 = singleton;
    }
    if (fn_27_5BEA8(lbl_27_bss_F0) != 1) {
        return;
    }
    if (accesser->getStatusModule().getStatusKind() == 0) {
        return;
    }
    if (accesser->getStatusModule().getStatusKind() == 1) {
        return;
    }
    if (accesser->getStatusModule().getStatusKind() == 8) {
        return;
    }
    if (accesser->getStatusModule().getStatusKind() == 9) {
        return;
    }
    if (accesser->getStatusModule().getStatusKind() == 0x18) {
        return;
    }
    if (accesser->getStatusModule().getStatusKind() == 0x19) {
        return;
    }
    if (accesser->getSituationModule().getKind() == 3) {
        return;
    }
    unsigned char* modules = *reinterpret_cast<unsigned char**>(reinterpret_cast<unsigned char*>(accesser) + 0xD8);
    ComboState* state = (*reinterpret_cast<ComboModule**>(modules + 0x90))->getState();
    if (state->getKind() != 1) {
        return;
    }
    soModuleAccesser* current = *reinterpret_cast<soModuleAccesser**>(static_cast<unsigned char*>(object) + 0x60);
    if (current->getWorkManageModule().getInt(0x20000004) == 2) {
        return;
    }
    if (accesser->getWorkManageModule().isFlag(0x22000005)) {
        accesser->getStatusModule().changeStatusRequest(0x19, accesser);
    } else {
        accesser->getStatusModule().changeStatusRequest(9, accesser);
    }
}
