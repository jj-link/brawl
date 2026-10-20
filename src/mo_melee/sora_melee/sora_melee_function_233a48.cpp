#include <st/st_trigger.h>
#include <st/st_trigger_observe.h>
#include <types.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" const char lbl_27_data_4BE50[];
extern "C" const char lbl_27_data_4BEC0[];
extern "C" void fn_27_235514(stObsTriggerSquareWindCB*, grGimmickWindData2nd*, s32);

void stTrigger::setWindParam(grGimmickWindData2nd* wnd, s32 p2) {
    if (__dynamic_cast(m_obsTriggerCB, 4, lbl_27_data_4BE50, lbl_27_data_4BEC0, 0)) {
        fn_27_235514((stObsTriggerSquareWindCB*)__dynamic_cast(m_obsTriggerCB, 4, lbl_27_data_4BE50, lbl_27_data_4BEC0, 0), wnd, p2);
    }
}
