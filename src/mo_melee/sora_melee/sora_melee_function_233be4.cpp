#include <st/st_trigger.h>
#include <st/st_trigger_observe.h>
#include <types.h>
#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" const char lbl_27_data_4BE10[];
extern "C" const char lbl_27_data_4BEC0[];
extern "C" void fn_27_235CC0(stObsTriggerSquareWindCB*, grGimmickWindData2nd*);

extern "C" void fn_27_233BE4(void* self, grGimmickWindData2nd* wnd) {
    if (__dynamic_cast(*(void**)((char*)self + 0x18), 4, lbl_27_data_4BE10, lbl_27_data_4BEC0, 0)) {
        fn_27_235CC0((stObsTriggerSquareWindCB*)__dynamic_cast(*(void**)((char*)self + 0x18), 4, lbl_27_data_4BE10, lbl_27_data_4BEC0, 0), wnd);
    }
}
