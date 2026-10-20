#pragma force_active on
extern "C" void fn_27_2AB4D4(char* self, int idx, float val) {
    int flag = 0;
    if (idx > -1 && idx < 0xB2) {
        flag = 1;
    }
    if (flag) {
        *(float*)(self + idx * 4 + 0x11b4) = val;
    }
}
