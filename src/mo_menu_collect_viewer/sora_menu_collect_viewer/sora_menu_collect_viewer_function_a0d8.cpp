#pragma force_active on
extern "C" {
int fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);
void fn_8005A0E4(int a1);
void fn_800557C0();

void fn_6_A0D8(void* p) {
    char* self = (char*)p;
    int r = fn_800BEEB8(0, *(int*)(*(int*)(self + 0x74) + 4), 0xa,
        *(int*)(self + 0x754), *(int*)(self + 0x70), *(int*)(self + 0x758) + 3, 0, 0x2a, 0x2b, 0, 0, 0xf0);
    *(int*)(self + 0x750) = r;
    int x = 0x1ef3;
    *(int*)(r + 0x128) = x;
    fn_8005A0E4(0x2e);
    fn_800557C0();
}
}
