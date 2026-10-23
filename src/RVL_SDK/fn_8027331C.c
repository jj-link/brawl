#pragma force_active on

extern void *lbl_805A0E80;

typedef void (*Fn)(int, int);

struct S {
    unsigned char pad[0x8a];
    unsigned char flag;
    unsigned char pad2[0x1bc - 0x8b];
    Fn fn;
};

void fn_8027331C(int arg, int arg2) {
    if (arg == 1) {
        ((struct S *)lbl_805A0E80)->flag = 1;
    }
    if (((struct S *)lbl_805A0E80)->fn != 0) {
        ((struct S *)lbl_805A0E80)->fn(arg, arg2);
    }
}
