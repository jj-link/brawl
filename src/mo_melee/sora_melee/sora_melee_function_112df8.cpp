#pragma force_active on
typedef unsigned short u16;

extern "C" {
u16 fn_27_112DF8(void* p, unsigned int i) {
    char* base = *(char**)p;
    return *(u16*)(base + ((i & 0xFF) << 2) + 0x90);
}
}
