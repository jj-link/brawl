#pragma force_active on
struct Obj;
typedef void (Obj::*PMF)(void*);

extern Obj* lbl_40_bss_15C;
extern PMF lbl_40_data_1618;

extern "C" void fn_40_8B30(void* self) {
    if (lbl_40_bss_15C) {
        (lbl_40_bss_15C->*lbl_40_data_1618)((char*)self + 0xc);
    }
}
