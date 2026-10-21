#pragma force_active on
void fn_80278C34(char* self) {
    float val;
    if (*(int*)(self + 0x18) == 1) {
        val = *(float*)(self + 0x4);
    } else {
        val = *(float*)(self + 0x8);
    }
    *(float*)(self + 0xc) = val;
}
