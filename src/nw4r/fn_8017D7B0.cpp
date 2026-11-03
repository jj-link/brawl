#pragma force_active on
typedef unsigned char u8;
typedef void (*FnPtr)();

extern "C" void fn_80177DBC();
extern "C" void fn_80177EC4();
extern "C" void fn_80177FB4();
extern "C" void fn_8017D864();
extern "C" void fn_8017A474();
extern "C" void fn_8017DC8C();
extern "C" void fn_8017DFB8();
extern "C" void fn_8017D9B0();

extern "C" FnPtr fn_8017D7B0(int unused, u8* arg) {
    u8* p = *(u8**)(arg + 0x24);
    switch (p[0x13e]) {
    case 0: return fn_80177DBC;
    case 1: return fn_80177EC4;
    case 2: return fn_80177FB4;
    case 3: return fn_8017D864;
    case 5: return fn_8017A474;
    case 6: {
        switch (p[0x142] & 7) {
        case 1: return fn_8017DC8C;
        case 2: return fn_8017DFB8;
        default: return fn_8017D9B0;
        }
    }
    default: return fn_80177DBC;
    }
}