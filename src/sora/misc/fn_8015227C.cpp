#pragma force_active on
extern "C" {

int fn_8033514C(int *arg0);

int fn_8015227C(int arg1, int arg2) {
    int sp8;

    sp8 = 0;
    switch (arg2) {
    case 2:
        fn_8033514C(&sp8);
        if (sp8 < 0) {
            sp8 -= sp8 * 2;
        }
        break;
    case 4:
        sp8 = 0x27D8;
        break;
    case 5:
        sp8 = 0x27D9;
        break;
    case 6:
        sp8 = 0x27DA;
        break;
    case 7:
        sp8 = 0x27DE;
        break;
    case 8:
        sp8 = 0x27DF;
        break;
    case 9:
        sp8 = 0x27E0;
        break;
    case 10:
        sp8 = 0x27E1;
        break;
    }
    return sp8;
}

}