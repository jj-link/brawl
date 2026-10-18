#pragma force_active on
extern "C" void fn_125_B244(void* self, unsigned int index) {
    unsigned int* work = *(unsigned int**)((char*)self + 0x1c);
    work[index] = 0;
}
