#pragma force_active on
extern "C" void fn_802D5FAC(int, unsigned char* p) {
    *(int*)(p) = 1;
    *(p + 4) = 1;
}
