#pragma force_active on
extern "C" {
void fn_93_10C84(void*, int);
void fn_93_10D18(void*, int);

void fn_93_10A34(void*, void* p2, int p3) {
    switch (p3) {
    case 0x116:
    case 0x11A:
    case 0x11B:
        break;
    default: {
        int base = 0x20000000;
        fn_93_10C84(p2, base + 1);
        fn_93_10C84(p2, base + 2);
        break;
    }
    }
    fn_93_10D18(p2, p3);
}
}
