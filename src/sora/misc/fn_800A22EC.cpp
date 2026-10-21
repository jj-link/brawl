#pragma force_active on
extern "C" {

extern float lbl_805A1E80;

void fn_800A22EC(void* p) {
    float x = lbl_805A1E80;
    *(float*)((char*)p + 0xB4) = x;
    *(float*)((char*)p + 0xB0) = x;
}

}
