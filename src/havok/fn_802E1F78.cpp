#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" {
extern void* fn_802E0E88(void);
extern void fn_802E0E40(void);
extern void fn_802E0E74(void);
extern u8 lbl_804129D0[];
extern u32 lbl_80532F70[4];

void fn_802E1F78(void) {
    void* temp_r3;

    temp_r3 = fn_802E0E88();
    lbl_80532F70[0] = (u32)(lbl_804129D0 + 0x4A);
    lbl_80532F70[1] = (u32)fn_802E0E40;
    lbl_80532F70[2] = (u32)fn_802E0E74;
    lbl_80532F70[3] = (u32)temp_r3;
}
}

__declspec(section ".ctors") extern void* const fn_802E1F78_ctor = (void*)fn_802E1F78;
