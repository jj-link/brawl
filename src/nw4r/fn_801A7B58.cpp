#pragma force_active on
extern "C" void fn_801A7B58(char** self, float x, float y) {
    char* p = *self;
    if (p == 0) {
        return;
    }
    *(float*)(p + 0xec) = x;
    *(float*)(p + 0xf0) = y;
}
