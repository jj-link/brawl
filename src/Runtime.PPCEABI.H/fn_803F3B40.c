struct dec {
    unsigned char flag;
    unsigned char pad0;
    short exp;
    unsigned char count;
    unsigned char dig[36];
};

extern const char lbl_8041F500[0xe0];
extern void fn_803F3A54(struct dec* rec, const char* digits, int exponent);
extern void fn_803F37CC(struct dec* out, const struct dec* lhs,
                      const struct dec* rhs);

void fn_803F3B40(struct dec* out, int exponent) {
    struct dec half;
    struct dec saved;

    switch (exponent) {
    case -64:
        fn_803F3A54(out, lbl_8041F500, -20);
        break;
    case -53:
        fn_803F3A54(out, lbl_8041F500 + 0x2e, -16);
        break;
    case -32:
        fn_803F3A54(out, lbl_8041F500 + 0x55, -10);
        break;
    case -16:
        fn_803F3A54(out, lbl_8041F500 + 0x6d, -5);
        break;
    case -8:
        fn_803F3A54(out, lbl_8041F500 + 0x7a, -3);
        break;
    case -7:
        fn_803F3A54(out, lbl_8041F500 + 0x81, -3);
        break;
    case -6:
        fn_803F3A54(out, lbl_8041F500 + 0x87, -2);
        break;
    case -5:
        fn_803F3A54(out, lbl_8041F500 + 0x8d, -2);
        break;
    case -4:
        fn_803F3A54(out, lbl_8041F500 + 0x92, -2);
        break;
    case -3:
        fn_803F3A54(out, lbl_8041F500 + 0x96, -1);
        break;
    case -2:
        fn_803F3A54(out, lbl_8041F500 + 0x9a, -1);
        break;
    case -1:
        fn_803F3A54(out, lbl_8041F500 + 0x9d, -1);
        break;
    case 0:
        fn_803F3A54(out, lbl_8041F500 + 0x9f, 0);
        break;
    case 1:
        fn_803F3A54(out, lbl_8041F500 + 0xa1, 0);
        break;
    case 2:
        fn_803F3A54(out, lbl_8041F500 + 0xa3, 0);
        break;
    case 3:
        fn_803F3A54(out, lbl_8041F500 + 0xa5, 0);
        break;
    case 4:
        fn_803F3A54(out, lbl_8041F500 + 0xa7, 1);
        break;
    case 5:
        fn_803F3A54(out, lbl_8041F500 + 0xaa, 1);
        break;
    case 6:
        fn_803F3A54(out, lbl_8041F500 + 0xad, 1);
        break;
    case 7:
        fn_803F3A54(out, lbl_8041F500 + 0xb0, 2);
        break;
    case 8:
        fn_803F3A54(out, lbl_8041F500 + 0xb4, 2);
        break;
    default:
        fn_803F3B40(&half, exponent / 2);
        fn_803F37CC(out, &half, &half);
        if (exponent & 1) {
            saved = *out;
            if (exponent > 0) {
                fn_803F3A54(&half, lbl_8041F500 + 0xa1, 0);
            } else {
                fn_803F3A54(&half, lbl_8041F500 + 0x9d, -1);
            }
            fn_803F37CC(out, &saved, &half);
        }
        break;
    }
}
