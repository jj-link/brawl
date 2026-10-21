#pragma force_active on
extern int lbl_805A0640;

int fn_801D6410(int arg0, int arg1) {
    int *p = (int*)(lbl_805A0640 + (((unsigned char)arg0) << 2));
    int old = *p;
    *p = arg1;
    return old;
}
