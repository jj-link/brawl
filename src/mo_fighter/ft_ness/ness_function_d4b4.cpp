#pragma force_active on
extern "C" void fn_101_D4B4(unsigned char* self, int factor, unsigned int index) {
    int* data = *reinterpret_cast<int**>(self + 0xC);
    data[index] *= factor;
}
