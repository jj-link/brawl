#pragma force_active on
extern "C" int fn_98_A480(void);

extern "C" float fn_98_A428(char* self, int unused, int a, int b) {
    int idx = fn_98_A480();
    char* row = self + idx * 0xb8;
    row += a * 4;
    float* values = *(float**)(row - 0x3e70);
    return values[b];
}
