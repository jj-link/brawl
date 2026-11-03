#pragma force_active on
typedef unsigned char u8;
typedef void (*FnPtr)();

extern "C" void fn_80177DBC();
extern "C" void fn_80177EC4();
extern "C" void fn_80177FB4();
extern "C" void fn_80181D78();
extern "C" void fn_8017A474();
extern "C" void fn_801821A0();
extern "C" void fn_801824CC();
extern "C" void fn_80181EC4();

extern "C" FnPtr fn_80181CC4(int unused, u8* arg) {
    u8* p = *(u8**)(arg + 0x24);
    switch (p[0x13e]) {
    case 0:
        return fn_80177DBC;
    case 1:
        return fn_80177EC4;
    case 2:
        return fn_80177FB4;
    case 3:
        return fn_80181D78;
    case 5:
        return fn_8017A474;
    case 6:
        switch (p[0x142] & 7) {
        case 1:
            return fn_801821A0;
        case 2:
            return fn_801824CC;
        default:
            return fn_80181EC4;
        }
    default:
        return fn_80177DBC;
    }
}