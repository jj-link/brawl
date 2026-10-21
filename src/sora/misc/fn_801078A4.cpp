#pragma force_active on
extern "C" {
void fn_80109540(void* arg0, int arg1);

void fn_801078A4(void* mngr, int arg) {
    void* ptr = *(void**)((char*)mngr + 0x6c);
    if (ptr)
        fn_80109540(ptr, arg);
}
}
