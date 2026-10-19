#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void fn_96_16014(void*, void*);
}

class AreaHelper {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void target(int, int, int);
};

extern "C" void fn_96_15DD4(void* unk1, void* unk2, int status) {
    switch (status) {
    case 0x117:
        return;
    case 0x126:
        break;
    default:
        fn_96_16014(unk1, unk2);
        break;
    }
    void** enumerationStart = *(void***) ((char*)unk2 + 0xD8);
    AreaHelper* module = (AreaHelper*)enumerationStart[0x90 / 4];
    module->target(9, 0, -1);
}
