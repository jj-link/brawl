#pragma force_active on
extern "C" void fn_801BC3A4(void* arg0);

extern "C" void fn_801CDB9C(void* self) {
    fn_801BC3A4(self);
    unsigned char* b = reinterpret_cast<unsigned char*>(self);
    int* w = reinterpret_cast<int*>(self);
    b[0xBA] = 0;
    b[0xBB] = 0;
    b[0xC6] = 0;
    b[0xBF] = 0;
    b[0xC0] = 0;
    b[0xC1] = 0;
    b[0xC2] = 0;
    b[0xC5] = 0;
    b[0xC3] = 0;
    b[0xC4] = 0;
    w[0x1F1] = 0;
    w[0x32] = 0;
    w[0x1F2] = 1;
    w[0x1F3] = 0;
    w[0x1F4] = 0;
    w[0x201] = 0;
    w[0x202] = 0;
}