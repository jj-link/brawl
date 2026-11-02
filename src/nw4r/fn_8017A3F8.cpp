#pragma force_active on
typedef unsigned char u8;
typedef void (*FnPtr)();

extern "C" void fn_80177DBC();
extern "C" void fn_80177EC4();
extern "C" void fn_80177FB4();
extern "C" void fn_80177FD0();
extern "C" void fn_8017A474();
extern "C" void fn_80178114();

extern "C" FnPtr fn_8017A3F8(int unused, u8* arg) {
    u8* p = *(u8**)(arg + 0x24);
    switch (p[0x13e]) {
    case 0:
        return fn_80177DBC;
    case 1:
        return fn_80177EC4;
    case 2:
        return fn_80177FB4;
    case 3:
        return fn_80177FD0;
    case 5:
        return fn_8017A474;
    case 6:
        return fn_80178114;
    default:
        return fn_80177DBC;
    }
}
