#pragma force_active on
extern "C" void fn_126_6F2C(char* obj, const char* src) {
    for (int i = 0; i < 2; i++) {
        *(int*)(obj + 0x10 + (i << 3)) = *(const int*)(src + 0x7C);
    }
}
