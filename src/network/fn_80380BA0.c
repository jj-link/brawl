#pragma force_active on
typedef struct {
    unsigned char pad0[4];
    int field_4;
    unsigned char pad8[0x8];
    int field_10;
    unsigned char pad14[0x14];
    int field_28;
    unsigned char pad2C[0x10];
    int field_3C;
    unsigned char pad40[0xE0];
    int field_120;
    unsigned char pad124[0x70];
    int field_194;
} Context;

void fn_8037BDD4(Context *, int, int);
void fn_8035D720(void);
int fn_803809F4(Context *);
int fn_8037CA28(int, int);

void fn_80380BA0(Context *arg0) {
    int temp;

    fn_8037BDD4(arg0, 0, 0);
    fn_8035D720();

    if (fn_803809F4(arg0) == 0) {
        arg0->field_120 = 1;
        arg0->field_3C = 3;
        return;
    }

    temp = arg0->field_28;
    if (temp == 1 && arg0->field_194 == 0) {
        fn_8037CA28(arg0->field_4, 1);
    } else if (temp != 1 && arg0->field_194 != 0) {
        fn_8037CA28(arg0->field_4, 0);
    }

    arg0->field_10 = 1;
    fn_8037BDD4(arg0, 0, 0);
}
