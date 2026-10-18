#pragma force_active on
extern "C" {
void fn_800C2BB4(void* a, void* b);

void fn_6_604C(int* a, char* b) {
    *a = 0;
    void* x = *(void**)(b + 0x1A0);
    *(int*)(b + 0x1A0) = 0;
    fn_800C2BB4(a, x);
}
}
