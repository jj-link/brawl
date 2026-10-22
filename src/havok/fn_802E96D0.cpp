#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_802E2FF8(void* self, int a, int b, int c);
extern "C" void fn_802ECBC0(void* a, void* b);

extern "C" void fn_802E96D0(void* obj, void* arg) {
    int state = *(int*)((u8*)obj + 0x2c);
    switch (state) {
    case 0:
        fn_802E2FF8(arg, 7, 1, 0);
        break;
    case 2:
        fn_802ECBC0(*(void**)((u8*)obj + 0x10), arg);
        break;
    case 1:
        fn_802E2FF8(arg, 7, 1, 0);
        break;
    }
}
