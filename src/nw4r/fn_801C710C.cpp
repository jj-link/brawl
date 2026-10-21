#pragma force_active on
extern "C" void fn_801C710C(void* p) {
    int* addr = (int*)((char*)p + 0x28);
    for (int i = 0; i < 7; i++)
        addr[i] = 0;
}
