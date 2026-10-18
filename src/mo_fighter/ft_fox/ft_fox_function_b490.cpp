#pragma force_active on
extern "C" void fn_97_B490(void* p, unsigned int val, unsigned int idx) {
    unsigned int base = *(unsigned int*)((char*)p + 12);
    ((unsigned int*)base)[idx] = val;
}
