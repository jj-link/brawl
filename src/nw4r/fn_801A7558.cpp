#pragma force_active on
extern "C" {

extern unsigned char* fn_801A12A0();
extern void fn_801A75A8(void*, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short, unsigned short);

void fn_801A7558(void* arg0) {
    unsigned char* ptr = fn_801A12A0();
    fn_801A75A8(arg0, *(unsigned short*)(ptr + 4), *(unsigned short*)(ptr + 6), *(unsigned short*)(ptr + 4), *(unsigned short*)(ptr + 8), *(unsigned short*)(ptr + 0xE), *(unsigned short*)(ptr + 0x10));
}

}
