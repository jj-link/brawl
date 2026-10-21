#pragma force_active on

extern "C" int fn_10_DA54(int* p, int kind) {
    int count = p[0x4E];
    int i;
    int result = -1;
    i = 0;

    for (; i < count; ++i) {
        int value = p[0x1C];
        switch (kind) {
        case 3:
        case 4:
            if (value == 3) result = i;
            break;
        case 14:
        case 15:
            if (value == 14) result = i;
            break;
        case 27:
        case 28:
        case 29:
        case 30:
            if (value == 27) result = i;
            break;
        default:
            if (value == kind) result = i;
            break;
        }
        if (result >= 0) break;
        ++p;
    }
    return result;
}
