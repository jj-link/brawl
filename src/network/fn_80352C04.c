#pragma force_active on
typedef int (*FnT)(int, int, int);

extern char* lbl_805A0FD4;

int fn_80352C04(int a) {
    return (*(FnT*)(lbl_805A0FD4 + 0x5b34))(0xc, a, 0);
}
