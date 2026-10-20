#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void fn_27_1D5448(char* p1, u8 p2, u32 p3, u32 p4) {
    u8* q = *(u8**)(p1 + p3 * 4 + 0x184);
    q[p4] = p2;
}
}
