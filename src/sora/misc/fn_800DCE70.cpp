#pragma force_active on
extern "C" {
void fn_80105274();

void fn_800DCE70(unsigned char* p, void* v) {
    unsigned char* q = *(unsigned char**)(p + 0x78);
    *(void**)(q + 0xe4) = v;
    if (q[0x30] != 0) {
        fn_80105274();
    }
}
}
