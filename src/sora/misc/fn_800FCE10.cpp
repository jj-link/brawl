#pragma force_active on
extern "C" {
void* fn_800BEEB8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12);

void fn_800FCE10(char* self, int flag, int a3, int arg3) {
    int v;
    int r;
    int b;
    b = arg3 != 0;
    if (flag == 0) {
        v = *(int*)(self + 0x48);
    } else {
        v = *(int*)(self + 0x4C);
    }
    r = (int)fn_800BEEB8(b, v, a3, (int)(self + 0xC), *(int*)(self + 0x14), 0x40, 0x1E, 0x28, 0x2A, 1, 1, 0xF0);
    *(int*)(self + 0x44) = r;
}
}
