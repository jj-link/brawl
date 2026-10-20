#pragma force_active on
extern const float lbl_27_rodata_320;

extern "C" {
float fn_27_118E0(char* self, int idx) {
    void* a = *(void**)(self + 0x28);
    if (a != 0) {
        void** arr = *(void***)a;
        return *(float*)((char*)arr[idx] + 0x80);
    }
    void* b = *(void**)(self + 0x2c);
    if (b != 0) {
        void** q = *(void***)b;
        void** arr = *(void***)q;
        return *(float*)((char*)arr[idx] + 0x80);
    }
    return lbl_27_rodata_320;
}
}
