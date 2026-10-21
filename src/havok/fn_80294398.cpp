#pragma force_active on
extern "C" {

extern float lbl_805A3E10;

void fn_80294398(void* p) {
    float x = lbl_805A3E10;
    *(float*)((char*)p + 0xC) = x;
    *(float*)((char*)p + 0x8) = x;
    *(float*)((char*)p + 0x4) = x;
    *(float*)((char*)p + 0x0) = x;
}

}
