#pragma force_active on
extern "C" void fn_57_AE7C(void* self) {
    unsigned int* p = (unsigned int*)((char*)self + 8);
    *p &= ~0x80000;
}
