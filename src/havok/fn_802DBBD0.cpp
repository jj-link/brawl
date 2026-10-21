#pragma force_active on
extern "C" {
extern const float lbl_805A426C;

void fn_802DBBD0(void* p) {
    float x = lbl_805A426C;
    *(float*)((char*)p + 8) = x;
    *(float*)((char*)p + 12) = x;
}
}
