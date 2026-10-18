#include <so/so_module_accesser.h>
#pragma force_active on

struct CaptainVirtualObject {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
};

extern "C" void fn_100_DC78(void*, soModuleAccesser* accesser) {
    CaptainVirtualObject* object = *(CaptainVirtualObject**)(*(char**)((char*)accesser + 0xd8) + 0x3c);
    object->slot10();
}
