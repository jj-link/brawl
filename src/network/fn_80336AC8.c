#pragma force_active on
extern int* lbl_805A0F70;

int fn_80336AC8(int a, int b) {
    if (lbl_805A0F70 == 0) {
        return 0;
    }
    *(int*)((char*)lbl_805A0F70 + 0x48) = a;
    *(int*)((char*)lbl_805A0F70 + 0x4c) = b;
    return 1;
}
