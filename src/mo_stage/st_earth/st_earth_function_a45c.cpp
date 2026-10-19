#pragma force_active on
extern "C" void* fn_66_A45C(char* self, int index) {
    int offset = *(int*)(self + 8) >> 30;
    int sum = offset + index;
    index = (sum >= 1) ? sum - 1 : sum;
    return self + index * 0x68 + 0xc;
}
