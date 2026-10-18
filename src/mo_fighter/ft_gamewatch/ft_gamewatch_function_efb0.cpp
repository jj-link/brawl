#pragma force_active on
typedef unsigned char u8;

struct FtGamewatchState {
    u8 pad[0x31];
    u8 flag31;
};

extern "C" void fn_107_EFB0(FtGamewatchState* object) {
    object->flag31 = 0;
}
