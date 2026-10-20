#pragma force_active on
extern "C" {
void fn_8015BFB4(void*, void*);

void fn_27_4FF88(char* base, void* arg, int idx) {
    fn_8015BFB4(base + idx * 12 + 0x40, arg);
}
}
