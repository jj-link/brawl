#pragma force_active on
#pragma scheduling off
typedef struct { int a; int b; int c; unsigned int d; } ControlArg;
extern int lbl_804DE270[];
extern int fn_801DCF70(int);
extern int fn_801DD2A0(int);
extern int fn_801DD320(int);

void fn_801E41F4(int arg0, ControlArg *arg1) {
    int *p = lbl_804DE270;
    switch (arg0) {
    case 0:
        if ((arg1->a == 0 && p[32] == 0) || (arg1->d & 0x10)) {
            fn_801DD2A0(0x410000);
        } else {
            fn_801DD320(0x410000);
        }
        break;
    case 1:
        if (arg1->a == 0 || (arg1->d & 0x10)) {
            fn_801DD2A0(0x80000);
        } else {
            fn_801DD320(0x80000);
        }
        break;
    case 2:
        if (fn_801DCF70(0x19) == 0 || (arg1->d & 0x10)) {
            fn_801DD2A0(0x40);
        } else {
            fn_801DD320(0x40);
        }
        break;
    }
}