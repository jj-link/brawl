#pragma force_active on
extern "C" int fn_98_A480(void);

extern "C" int fn_98_A48C(char* self, int unused, int a, int b) {
    int offset = fn_98_A480() * 0x24;
    char* row = (self - 0x10000) + offset;
    row += a * 4;
    int* values = *(int**)(row - 0x7580);
    return values[b];
}
