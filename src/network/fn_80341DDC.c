#pragma force_active on
#pragma optimization_level 1

struct State {
    char pad0[0xF];
    unsigned char f0F;
    char pad1[6];
    unsigned char f16;
    char pad2[0x1A5];
    unsigned char f1BC;
};

extern struct State* lbl_805A0FA8;
extern void fn_80347390(int, int);

void fn_80341DDC(int a) {
    int b;
    struct State *state = lbl_805A0FA8;
    if (state->f1BC == 2)
        return;
    b = 2;
    if (state->f16 != 0) {
        if (state->f16 != 1)
            goto done;
    }
    if (state->f0F != 0)
        goto done;
    b = 1;
done:
    fn_80347390(a, b);
}
