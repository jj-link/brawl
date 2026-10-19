#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void fn_8006BCA8(char*);
int printf__5MuMsgFUlPCce(unsigned int, unsigned int, const char*, ...);

void fn_10_1915C(u8* self) {
    char buf[0x20];
    fn_8006BCA8(buf);
    printf__5MuMsgFUlPCce(*(u32*)(self + 0x40c), 0x1d, buf);
}
}
