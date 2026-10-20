#include <types.h>
#pragma force_active on

extern "C" {
extern char lbl_27_data_5DA8;
extern char lbl_27_data_5C40;
extern char __vt__22soAnimCmdEventObserver;
}

struct FakeObserver {
    virtual void addObserver(short param1, s8 param2);
    s16 m_manageID;
    s16 m_unitID;
    s16 m_sendID;
};

extern "C" void* fn_27_58264(void* self, int a2, int unused, void* a3) {
    char* p = (char*)self;
    FakeObserver* obs = (FakeObserver*)(p + 4);
    short unit = (short)a2;
    *(void**)p = &lbl_27_data_5DA8;
    s16 init = -1;
    obs->m_manageID = init;
    obs->m_unitID = 5;
    obs->m_sendID = init;
    *(void**)obs = &__vt__22soAnimCmdEventObserver;
    obs->addObserver(unit, (s8)-1);
    *(void**)p = &lbl_27_data_5C40;
    *(void**)(p + 4) = &lbl_27_data_5C40 + 0x110;
    *(void**)(p + 0x10) = a3;
    return self;
}
