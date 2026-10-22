#pragma force_active on
extern "C" void fn_801F54D0(float x, float y);
extern "C" void GXSetZMode(unsigned char enable, int func, unsigned char update);
extern "C" float lbl_805A26C0;
extern "C" float lbl_805A26D0;

extern "C" {
void fn_800FB6DC(void* arg0, int arg1) {
    float temp_f1;

    switch (arg1) {
    case 1:
        temp_f1 = *(float*)((char*)arg0 + 4);
        fn_801F54D0(temp_f1, lbl_805A26D0 - temp_f1);
        GXSetZMode(1, 3, 1);
        break;
    case 4:
        fn_801F54D0(lbl_805A26D0, lbl_805A26C0);
        GXSetZMode(0, 3, 0);
        break;
    case 3:
        break;
    }
}
}
