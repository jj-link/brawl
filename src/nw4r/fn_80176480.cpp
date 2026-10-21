#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_801764BC(int, int, u8*);
extern "C" void fn_80176C6C(int, int, u8*);
extern "C" void fn_801773C4(int, int, u8*);

extern "C" void fn_80176480(int a, int b, u8* obj) {
    u8* sub = *(u8**)(obj + 0x24);
    switch (sub[0x13d]) {
    case 0:
        fn_801764BC(a, b, obj);
        break;
    case 1:
        fn_80176C6C(a, b, obj);
        break;
    case 2:
        fn_801773C4(a, b, obj);
        break;
    }
}
