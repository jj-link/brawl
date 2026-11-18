#include <types.h>
#include <nw4r/ut/ut_ResFontBase.h>
#pragma force_active on

extern "C" nw4r::ut::CharWidths fn_8015E0E8(void* arg0) {
    return (*(nw4r::ut::FontInformation**)((char*)arg0 + 0x14))->defaultWidth;
}
