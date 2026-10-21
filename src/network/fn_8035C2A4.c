#pragma force_active on
typedef int s32;

s32 SOClose(s32 s);
extern s32 lbl_805A1044;

s32 closesocket(s32 s) {
    s32 temp_r3;

    temp_r3 = SOClose(s);
    if (temp_r3 >= 0) {
        return temp_r3;
    }
    lbl_805A1044 = temp_r3;
    return -1;
}
