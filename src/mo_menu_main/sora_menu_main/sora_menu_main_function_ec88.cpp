#pragma force_active on
extern "C" {
void* fn_800F1820(void* a, void* b, void* c, void* d, int e, int f, int g, int h);
void fn_1_6DA0(void*, void*);
void fn_2_EC88(char* s);
}

void fn_2_EC88(char* s) {
    *(char*)(*(char**)(*(char**)(s + 0x40) + 0x8) + 0xc) = 1;
    *(void**)(s + 0x188) = fn_800F1820(s + 0xa8, s + 0xb0, *(void**)(s + 0xac), *(void**)(s + 0x18c), 1, 0x2a, 0x2b, 0xff);
    fn_1_6DA0(*(void**)(s + 0x40), *(void**)(s + 0x18c));
}
