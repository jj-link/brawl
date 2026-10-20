#pragma force_active on
extern "C" void fn_27_110674(void* p)
{
    char* self = (char*)p;
    int a = *(int*)(self + 0x60);
    int b = *(int*)(*(char**)(self + 0x44) + 0x28);
    if (a >= b) {
        return;
    }
    *(char*)(self + 0x7d) = 1;
    *(char*)(self + 0x7e) = 1;
}
