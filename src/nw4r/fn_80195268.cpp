#pragma force_active on
extern "C" {

extern float lbl_805A31F4;
void fn_801EC158(void* p);

void fn_80195268(void* p) {
    float x = lbl_805A31F4;
    *(float*)((char*)p + 0x4) = x;
    *(float*)((char*)p + 0x8) = x;
    *(float*)((char*)p + 0xC) = x;
    fn_801EC158((char*)p + 0x1C);
}

}
