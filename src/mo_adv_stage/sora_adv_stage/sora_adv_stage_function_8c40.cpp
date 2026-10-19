#pragma force_active on
class Target;
typedef void (Target::*PMF)(void*);

extern "C" {
extern Target* lbl_40_bss_15C;
extern PMF lbl_40_data_1624;

void fn_40_8C40(char* p)
{
    if (lbl_40_bss_15C) {
        (lbl_40_bss_15C->*lbl_40_data_1624)(p + 0xc);
    }
}
}
