#pragma force_active on
extern char lbl_8053A6E0[];

void fn_803ADD18(int arg0, int arg1) {
    *(int*)((char*)lbl_8053A6E0 + (arg0 & 0xFF) * 0x2C + 0x710) = arg1;
}
