#pragma force_active on
extern "C" float fn_802E43E4(void* ptr) {
    extern float lbl_805A43B0;
    extern float lbl_805A43B4;
    float val = *(float*)((char*)ptr + 0xdc);
    if (lbl_805A43B0 == val)
        return lbl_805A43B0;
    return lbl_805A43B4 / val;
}
