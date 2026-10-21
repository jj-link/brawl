#pragma force_active on
extern int lbl_805A0FD4;
typedef int (*VFn)(int, int);

int fn_80352BEC(int a) {
    return (*(VFn*)((char*)lbl_805A0FD4 + 0x5b30))(12, a);
}
