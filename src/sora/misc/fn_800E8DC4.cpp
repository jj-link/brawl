#pragma force_active on
extern "C" int fn_800E8DC4(void* unused, void* arg) {
    unsigned int word;
    int result;
    char val = *(char*)((char*)arg + 0x31);
    if (val < 0) {
        int clamped = (val < -75) ? -75 : val;
        int temp = clamped * 0x3c;
        result = temp / 75;
    } else if (val > 0) {
        int clamped = (val > 75) ? 75 : val;
        int temp = clamped * 0x3c;
        result = temp / 75;
    } else {
        word = *(unsigned int*)((char*)arg + 0x4);
        if (word & 8) {
            result = 0x3c;
        } else {
            result = (word & 4) ? -0x3c : 0;
        }
    }
    return -result;
}