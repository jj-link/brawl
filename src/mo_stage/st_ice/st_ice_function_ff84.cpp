#pragma force_active on
extern "C" void playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);

struct IceObject {
    unsigned char pad[0x188];
};

extern "C" void fn_62_FF84(void* self, const int* value) {
    int code = *value;

    if (code == 0x33) {
        *(int*)((char*)self + 0x198) = 0;
        return;
    }

    if (code <= 0x26 || code >= 0x29)
        return;

    if (code != 0x27)
        return;

    *(int*)((char*)self + 0x198) = 1;
    playSE__14snd3DGeneratorF5SndIDiii((char*)self + 0x188, 0x1c89, 0, 0, -1);
}
