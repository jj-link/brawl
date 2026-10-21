#pragma force_active on
extern "C" int randi__Fl(long);

extern "C" int fn_1_3D12C(int x) {
    int ret;
    int r;
    switch (x) {
        case 0x48:
            switch (randi__Fl(3)) {
                case 0:
                    return 0x1D;
                case 1:
                    return 0x1F;
                default:
                    return 0x21;
            }
        case 0x49:
            r = randi__Fl(2);
            ret = 4;
            if (r == 0) {
                ret = 3;
            }
            return ret;
        case 0x4A:
            r = randi__Fl(2);
            ret = 15;
            if (r == 0) {
                ret = 14;
            }
            return ret;
        default:
            return x;
    }
}
