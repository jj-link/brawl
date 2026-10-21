#pragma force_active on
extern "C" {
extern int lbl_805A0570;
void fn_80204B90(void*, int);

void fn_801BBCF8() {
    int* p = (int*)lbl_805A0570;
    if (p[2])
        p[2]--;
    p = (int*)lbl_805A0570;
    if (p[2] == 0)
        fn_80204B90((void*)p[1], 3);
}
}
