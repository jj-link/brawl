#pragma force_active on
extern "C" void* fn_85_5124(void* object) {
    int v = *(int*)((char*)object + 0x1d8);
    switch (v) {
    case 0:
        return (void*)0x140004b8;
    case 1:
        return (void*)0x14000496;
    case 2:
        return (void*)0x1400047d;
    default:
        return 0;
    }
}
