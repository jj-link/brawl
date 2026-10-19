#pragma force_active on
extern "C" {
int fn_800DAA30(int a, int b, int c, int d);

void fn_6_97C4(unsigned char* self) {
    *(int*)(self + 0x770) = fn_800DAA30(*(int*)(self + 0x754), *(int*)(self + 0x70), *(int*)(self + 0x78), *(int*)(self + 0x758) + 3);
}
}
