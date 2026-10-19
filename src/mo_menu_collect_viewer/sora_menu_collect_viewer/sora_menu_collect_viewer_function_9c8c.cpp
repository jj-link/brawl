#pragma force_active on
extern "C" void fn_6_9C8C(void* self) {
    int* p = (int*)self;
    if (p[0x72c / 4] > 0) {
        return;
    }
    p[0x748 / 4] = 1;
    p[0x74c / 4] = 1;
}
