#pragma force_active on
extern void fn_80269610(void);
extern void fn_802696FC(void);

void fn_802695D0(void *arg0) {
    unsigned int *temp_r5;
    unsigned int a;
    unsigned int b;
    unsigned int c;

    temp_r5 = *(unsigned int **)((char *)arg0 + 0x1c);
    c = temp_r5[0x10 / 4];
    a = temp_r5[0];
    b = temp_r5[1];
    if (b - a >= c - 0x100) {
        *(void (**)(void))((char *)arg0 + 0x20) = fn_802696FC;
    } else {
        *(void (**)(void))((char *)arg0 + 0x20) = fn_80269610;
    }
}
