#pragma force_active on
extern void *lbl_8059EE5C;
extern void *lbl_805A0E80;
void fn_80204738(int);
void fn_80204E6C(void *, void *);
void fn_8026FAE4(void *, int);

void fn_8026F614(void) {
    int var_r3;
    int *temp_r31;

    temp_r31 = *(int **)((char *)lbl_805A0E80 + 0x4);
    fn_8026FAE4(lbl_805A0E80, -1);
    fn_80204E6C(lbl_8059EE5C, lbl_805A0E80);
    lbl_805A0E80 = 0;
    if (temp_r31[0xF] != 0) {
        var_r3 = 0;
    } else {
        var_r3 = 2;
        if (temp_r31[4] != 0) {
            var_r3 = 1;
        }
    }
    if (var_r3 == 1) {
        fn_80204738(*(int *)((char *)lbl_8059EE5C + 0x4));
    }
}
