#pragma force_active on
typedef struct Obj {
    void (*fn0)(int, int, int);
    void (*fn4)(int);
} Obj;

extern Obj* lbl_805A0D18;
extern int lbl_805A0D1C;

void fn_80231864(void) {
    if (lbl_805A0D18 != 0) {
        if (lbl_805A0D18->fn0 != 0) {
            lbl_805A0D18->fn0(2, 1, 0x800);
        }
        if (lbl_805A0D18->fn4 != 0) {
            lbl_805A0D18->fn4(lbl_805A0D1C);
        }
    }
}
