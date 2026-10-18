#pragma force_active on
extern "C" void fn_70_1DC0(void* a, int* b, float* c) {
    *b = *reinterpret_cast<int*>(static_cast<char*>(a) + 0x188);
    *c = *reinterpret_cast<float*>(static_cast<char*>(a) + 0x18C);
}
