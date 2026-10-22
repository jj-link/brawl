#pragma force_active on
extern "C" {
extern int lbl_805A03E8;
extern int lbl_805A03F4;

int fn_8014B2E4(void) {
    switch (lbl_805A03E8) {
    case 7: {
        int v;
        switch (lbl_805A03F4) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            v = 1;
            break;
        default:
            v = 0;
            break;
        }
        if (v != 0) {
            return 1;
        }
        break;
    }
    case 14:
    case 3:
    case 2:
    case 6:
        return 1;
    default:
        break;
    }
    return 0;
}
}
