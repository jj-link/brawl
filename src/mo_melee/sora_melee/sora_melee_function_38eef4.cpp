#pragma force_active on
extern "C" float fn_27_38EEF4(void* self, int unused, int a, int b) {
    char* p = (char*)self;
    int base = *(int*)(p + 0x10);
    float* row = *(float**)(p + 0x18 + ((a - base) << 2));
    return row[b];
}
