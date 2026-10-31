#pragma force_active on
struct Obj1 {
    int pad0[3];
    int field_c;
    int pad_d;
    int field_14;
    int pad18[4];
    int field_28;
    int field_2c;
    int field_30;
    int field_34;
};

struct Obj2 {
    int field_0;
    int field_4;
    int field_8;
    int field_c;
};

struct Quad {
    int a;
    int b;
    int c;
    int d;
};

void fn_803774A0(void);

int fn_80374320(struct Obj1* arg0, struct Obj2* arg1) {
    if (arg0->field_14 != 0) {
        arg0->field_14 = 0;
        return 0;
    }

    arg0->field_14 = 0;
    if (arg0->field_c != 4) {
        return 0;
    }

    fn_803774A0();
    arg0->field_c = 5;

    if (arg1 != 0) {
        *(struct Quad*)&arg0->field_28 = *(struct Quad*)arg1;
    }

    return 1;
}
