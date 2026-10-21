#pragma force_active on
typedef unsigned int u32;

extern "C" void* fn_802E4758();
extern "C" void fn_802E4724();
extern "C" void fn_802E4744();
extern "C" char lbl_80413110[];
extern "C" void* lbl_805330D8[4];

extern "C" void fn_802E47D8() {
    void* temp_r3 = fn_802E4758();
    lbl_805330D8[0] = lbl_80413110;
    lbl_805330D8[1] = (void*)fn_802E4724;
    lbl_805330D8[2] = (void*)fn_802E4744;
    lbl_805330D8[3] = temp_r3;
}

__declspec(section ".ctors") extern void* const fn_802E47D8_ctor = (void*)fn_802E47D8;
