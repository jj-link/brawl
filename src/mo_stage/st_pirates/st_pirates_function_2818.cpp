#pragma force_active on
extern "C" float randf__Fv();

extern "C" void fn_52_2818(char* self) {
    char* obj = *(char**)(self + 0x9c);
    if (obj != 0) {
        float b = *(float*)(obj + 0x60);
        float sum = b + *(float*)(obj + 0x64);
        float pa = b / sum;
        float pb = (*(float*)(obj + 0x64)) / sum;
        float r = randf__Fv();
        if (r < pb) {
            self[0x55d] = 5;
        } else if (r < pa + pb) {
            self[0x55d] = 4;
        } else {
            self[0x55d] = 0;
        }
    }
}
