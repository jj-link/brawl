#pragma force_active on
class Ctx;
typedef void (Ctx::*PMF)(void*);
extern Ctx* lbl_40_bss_15C;
extern PMF lbl_40_data_1630;

extern "C" void fn_40_8D50(char* self) {
    if (lbl_40_bss_15C) {
        (lbl_40_bss_15C->*lbl_40_data_1630)(self + 0xc);
    }
}
