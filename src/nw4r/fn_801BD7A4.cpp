#pragma force_active on

struct Obj {
    char pad[0x10];
    unsigned char flag;
    char pad2[3];
    int unk14;
    int unk18;
    int unk1C;
};

extern "C" {
    int OSDisableInterrupts();
    void OSRestoreInterrupts(int);
    int fn_801C07F8(Obj*, int, int, int);
}

extern "C" void fn_801BD7A4(Obj* arg0, int arg1, int arg2) {
    int temp_r31 = OSDisableInterrupts();
    if (arg0->flag != 0) {
        OSRestoreInterrupts(temp_r31);
        return;
    }
    arg0->unk14 = fn_801C07F8(arg0, arg1, arg2, 0xEC);
    arg0->unk18 = arg1;
    arg0->unk1C = arg2;
    arg0->flag = 1;
    OSRestoreInterrupts(temp_r31);
}
