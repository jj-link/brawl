#pragma force_active on

extern "C" int fn_27_8D3E4(void* p);

extern "C" void fn_27_384DE8(char* self) {
    for (int i = 0; i < 1; ++i) {
        char* e;
        if (i == 0)
            e = self + 0x2094;
        else
            e = 0;
        if (fn_27_8D3E4(e + 0x88) == 0)
            return;
    }
    for (int i = 0; i < 1; ++i) {
        char* e;
        if (i == 0)
            e = self + 0x18;
        else
            e = 0;
        if (fn_27_8D3E4(e + 0x88) == 0)
            return;
    }
}
