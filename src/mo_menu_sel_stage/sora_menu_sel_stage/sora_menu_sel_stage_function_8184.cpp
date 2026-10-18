#pragma force_active on
extern "C" {
void fn_800398C8(void* a, int b);
void fn_11_8184(void* p) {
    fn_800398C8(*(void**)((char*)p + 0x68), 3);
}
}
