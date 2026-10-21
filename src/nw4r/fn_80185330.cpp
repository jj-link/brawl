#pragma force_active on
extern int lbl_805A0508;

extern "C" {
void fn_80204E6C(int a, int b);

void fn_80185330(char* self) {
    int v = *(int*)(self + 0xD4);
    if (v != 0) {
        fn_80204E6C(lbl_805A0508, v);
        *(int*)(self + 0xD4) = 0;
        *(short*)(self + 0xF8) = 0;
    }
}
}
