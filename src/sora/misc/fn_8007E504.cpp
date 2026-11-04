#pragma force_active on
extern "C" {
extern unsigned char g_thpObject[];
extern void* PopReadedBuffer__Fv();
extern void* PopReadedBuffer2__Fv();
extern void PushFreeReadBuffer__FPv(void* arg);
extern int fn_8007E70C(void* arg);

void fn_8007E504(void) {
    int r29;
    char* r31;

    r29 = 0;
    while (1) {
        if (g_thpObject[0xA7] != 0) {
            while (r29 != 0) {
                r31 = (char*)PopReadedBuffer2__Fv();
                unsigned int val = *(unsigned int*)(r31 + 4);
                unsigned int c0 = *(unsigned int*)(g_thpObject + 0xC0);
                unsigned int d50 = *(unsigned int*)(g_thpObject + 0x50);
                unsigned int sum = val + c0;
                unsigned int rem = sum % d50;
                if (rem == d50 - 1 && !(g_thpObject[0xA6] & 1)) {
                    fn_8007E70C(r31);
                }
                PushFreeReadBuffer__FPv(r31);
                r29--;
                *(int*)(g_thpObject + 0xD8) = *(int*)(g_thpObject + 0xD8) + 1;
            }
        }
        if (g_thpObject[0xA7] != 0) {
            r31 = (char*)PopReadedBuffer2__Fv();
        } else {
            r31 = (char*)PopReadedBuffer__Fv();
        }
        r29 = fn_8007E70C(r31);
        PushFreeReadBuffer__FPv(r31);
    }
}
}