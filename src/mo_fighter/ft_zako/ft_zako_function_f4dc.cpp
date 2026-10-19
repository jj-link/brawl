#pragma force_active on
extern "C" void fn_126_F4DC(unsigned char* obj, const unsigned char* data) {
    for (int i = 0; i < 2; ++i) {
        *(int*)(obj + i * 8 + 0x10) = *(const int*)(data + 0x7C);
    }
}
