#pragma force_active on
extern "C" {

extern float lbl_805A35C8;

void fn_801C60AC(void* p) {
    float x = lbl_805A35C8;
    *(float*)((char*)p + 0x30) = x;
    *(float*)((char*)p + 0x34) = x;
    *(float*)((char*)p + 0x38) = x;
}

}
