#pragma force_active on
extern "C" void* fn_73_ABA0(char* self, int index) {
    int flag = *(int*)(self + 8);
    int sum = (flag >> 29) + index;
    if (sum >= 2) {
        sum -= 2;
    }
    return self + sum * 0x90 + 0xc;
}
