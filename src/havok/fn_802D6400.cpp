#pragma force_active on
typedef unsigned int u32;

extern "C" {
    int fn_802D5DBC(void);
    void fn_802D5D88(void);
    void fn_802D5DA8(void);
    extern unsigned char lbl_80410F60[];
    extern u32 lbl_80532908[4];

    void fn_802D6400(void) {
        int temp_r3;

        temp_r3 = fn_802D5DBC();
        lbl_80532908[0] = (u32)(lbl_80410F60 + 0x1A);
        lbl_80532908[1] = (u32)fn_802D5D88;
        lbl_80532908[2] = (u32)fn_802D5DA8;
        lbl_80532908[3] = temp_r3;
    }
}

__declspec(section ".ctors") extern void* const fn_802D6400_ctor = (void*)fn_802D6400;
