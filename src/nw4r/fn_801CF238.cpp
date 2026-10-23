#pragma force_active on

extern "C" {
int OSDisableInterrupts();
void OSRestoreInterrupts(int);
void fn_801D0DA4(void*);
}

struct FnState {
    char pad[0x7C0];
    int field7C0;
};

extern "C" void fn_801CF238(void* arg0, int arg1, FnState* arg2) {
    int enabled = OSDisableInterrupts();

    switch (arg1) {
    case 0:
    case 1:
        fn_801D0DA4(arg0);
        arg2->field7C0 = 0;
        break;
    case 2:
    case 3:
        arg2->field7C0 = 0;
        break;
    default:
        OSRestoreInterrupts(enabled);
        return;
    }

    OSRestoreInterrupts(enabled);
}
