#pragma force_active on
typedef void (*FnPtr)();

extern "C" void fn_801760C4();
extern "C" void fn_801760F4();

extern "C" FnPtr fn_80176028(int unused, int flag) {
    switch (flag) {
    case 0:
        return fn_801760F4;
    default:
        return fn_801760C4;
    }
}
