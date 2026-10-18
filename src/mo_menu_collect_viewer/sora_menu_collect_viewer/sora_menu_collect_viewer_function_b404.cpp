#include <string.h>
#pragma force_active on

extern "C" {
void fn_6_AECC(void* self, int flag);
void fn_16_5A8(void* self, const char* name, int a, int c);
int fn_800B5854(void* p, int a, int b, int c, int d);
}

extern "C" void fn_6_B404(char* self) {
    char buf[0x30];
    int a;
    int c;
    fn_6_AECC(self, *(unsigned char*)(self + 0x261));
    if (*(unsigned char*)(self + 0x261)) {
        strcpy(buf, self + 0x179);
        a = (int)(self + 0x238);
        c = 10;
    } else {
        strcpy(buf, self + 0x164);
        a = 0;
        c = 5;
    }
    *(int*)(self + 0x234) = *(int*)(self + 0x13c);
    fn_16_5A8(self + 0x1a4, buf, a, c);
    fn_800B5854(*(void**)(self + 0x40), *(unsigned char*)(self + 0x261) ? 3 : 1, 1, 1, 0);
}
