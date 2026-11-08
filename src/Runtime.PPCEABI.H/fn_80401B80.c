#pragma force_active on
extern int fn_80405BE4();
extern int fn_80401968(int *out_index, void **out_buffer);
extern int fn_80401868(void *buffer, unsigned long position);
extern int fn_80405BA8();
extern int fn_804015D4(void *buffer, void *input, int len);
extern void fn_804018D8(int index);

int fn_80401B80(void) {
    int spC;
    void *sp8;
    int sp10[16];
    unsigned char sp50[0x888];
    int temp_r31;
    int var_r31;
    int len;

    if (fn_80405BE4() <= 0) {
        return -1;
    }
    temp_r31 = fn_80401968(&spC, &sp8);
    fn_80401868(sp8, 0);
    if (fn_80405BA8(sp10, 0x40) == 0) {
        fn_804015D4(sp8, sp10, 0x40);
        var_r31 = spC;
        len = sp10[0] - 0x40;
        if (len > 0) {
            if (fn_80405BA8(sp50, len) == 0) {
                fn_804015D4(sp8, sp50, sp10[0]);
            } else {
                fn_804018D8(var_r31);
                var_r31 = -1;
            }
        }
    } else {
        fn_804018D8(temp_r31);
        var_r31 = -1;
    }
    return var_r31;
}
