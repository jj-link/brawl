#pragma force_active on
extern "C" void* fn_105_9FB8(void* a, int b);

extern "C" void* fn_105_A0A4(void* r3, int r4) {
    switch (r4) {
        case 0:
            return r3;
        case 1:
            return (void*)((char*)r3 + 0x490);
        case 2:
            return fn_105_9FB8(r3, r4);
        default:
            return fn_105_9FB8(r3, r4);
    }
}