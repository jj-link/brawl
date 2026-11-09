#include <types.h>
#pragma force_active on

extern "C" void fn_10_17644(void*, int, u8);

extern "C" void fn_10_8388(void* self) {
    int sp8[4];
    int* q;
    int filled;
    char* p = (char*)self;
    int total = 0;
    int i;

    for (i = 0; i < *(int*)((char*)self + 0x648); i++) {
        if (*(int*)(*(char**)(p + 0x44) + 0x1b4) != 0)
            total++;
        p += 4;
    }

    int divisor;
    for (divisor = total - 1; divisor > 0; divisor--) {
        if (total % divisor == 0)
            break;
    }
    if (divisor <= 0)
        divisor = 1;

    q = sp8;
    filled = 0;
    int value = 0;
    while (value < 3 && filled < 4) {
        int k = 0;
        while (k < divisor && filled < 4) {
            *q = value;
            k++;
            q++;
            filled++;
        }
        value++;
    }

    char* p2 = (char*)self;
    int* q2 = sp8;
    for (int n = 0; n < *(int*)((char*)self + 0x648); n++) {
        char* hand = *(char**)(p2 + 0x44);
        if (*(int*)(hand + 0x1b4) != 0) {
            fn_10_17644(hand, *q2, *(u8*)(hand + 0x1c4));
            q2++;
        }
        p2 += 4;
    }
}
