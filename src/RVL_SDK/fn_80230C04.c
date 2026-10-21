#pragma force_active on
extern void fn_802305C8(unsigned short val, void* ptr);
extern unsigned char lbl_80525F28[0x38];

int fn_80230C04(int arg0) {
    fn_802305C8((unsigned short)((arg0 - 8) - *(unsigned short*)&lbl_80525F28[0x12]), lbl_80525F28);
    return 0;
}
