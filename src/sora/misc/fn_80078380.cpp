#pragma force_active on
extern "C" int fn_80078380(void* self, int kind, unsigned int mode) {
    int result = -1;
    if (mode == 1) {
        result = 0;
    } else if (mode == 2) {
        switch (kind) {
        case 0x1b85: return 1;
        case 0x2074: return 2;
        case 0x2073: return 3;
        case 0x2072: return 4;
        default: return 5;
        }
    }
    return result;
}