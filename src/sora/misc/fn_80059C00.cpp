#pragma force_active on
extern "C" {
extern void* g_GameGlobal;
unsigned char* fn_8004E790(void*, int);
int fn_80055888(int, int);
unsigned int fn_8004F4A0(int);
int fn_80059C00(int arg) {
    int result = 0;
    unsigned char* a = fn_8004E790(g_GameGlobal, 0);
    unsigned char* b = fn_8004E790(g_GameGlobal, 1);
    switch (arg) {
    case 0x75:
        if (*a < 0x14 && fn_80055888(1, 0) >= 7) {
            result = 1;
            *a = 0x14;
        }
        break;
    case 0x76:
        if (*a >= 0x14 && *a < 0x1c && fn_80055888(1, 0) >= 0x12 &&
            fn_8004F4A0(0xb) == 1U && fn_8004F4A0(0x13) == 1U &&
            fn_8004F4A0(9) == 1U && fn_8004F4A0(0xa) == 1U &&
            fn_8004F4A0(0x24) == 1U && fn_8004F4A0(0x26) == 1U) {
            result = 1;
            *a = 0x1c;
        }
        break;
    case 0x77:
        if (*a >= 0x1c && *a < 0x28 && fn_80055888(1, 0) >= 0x14 &&
            fn_8004F4A0(0x15) == 1U && fn_8004F4A0(0x2a) == 1U &&
            fn_8004F4A0(0x16) == 1U && fn_8004F4A0(0x14) == 1U &&
            fn_8004F4A0(0x2b) == 1U && fn_8004F4A0(0x27) == 1U &&
            fn_8004F4A0(0x28) == 1U && fn_8004F4A0(0x29) == 1U) {
            result = 1;
            *a = 0x28;
        }
        break;
    case 0x78:
        if (*a == 0x28 && fn_80055888(1, 0) >= 0x28) {
            result = 1;
            *a = 0x29;
        }
        break;
    case 0x79:
        if (*b < 0xd && fn_8004F4A0(0xb) == 1U &&
            fn_8004F4A0(0x13) == 1U && fn_8004F4A0(9) == 1U &&
            fn_8004F4A0(0xa) == 1U && fn_8004F4A0(0x24) == 1U &&
            fn_8004F4A0(0x26) == 1U) {
            result = 1;
            *b = 0xd;
        }
        break;
    case 0x7a:
        if (*b >= 0xd && *b < 0x14 && fn_80055888(2, 0) >= 0xa &&
            fn_8004F4A0(0x15) == 1U && fn_8004F4A0(0x2a) == 1U &&
            fn_8004F4A0(0x16) == 1U && fn_8004F4A0(0x14) == 1U &&
            fn_8004F4A0(0x2b) == 1U && fn_8004F4A0(0x27) == 1U &&
            fn_8004F4A0(0x28) == 1U && fn_8004F4A0(0x29) == 1U) {
            result = 1;
            *b = 0x14;
        }
        break;
    case 0x7b:
        if (*b == 0x14 && fn_80055888(2, 0) >= 0x14) {
            result = 1;
            *b = 0x15;
        }
        break;
    }
    return result;
}
}