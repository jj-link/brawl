#pragma force_active on
extern "C" int* fn_27_1B0B70(int* p, int index) {
    return p + ((p[2] >> 22) + index >= 0x120
                    ? (p[2] >> 22) + index - 0x120
                    : (p[2] >> 22) + index) + 3;
}
