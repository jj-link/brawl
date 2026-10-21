#pragma force_active on
extern "C" void fn_8002B4E8(int);
extern "C" void fn_80218D5C(void (*)(int));
extern "C" int fn_80218D58(void);

struct gfPadSystem {
    char pad0[0x34];
    unsigned char unk34;

    bool startSimpleSync();
};

bool gfPadSystem::startSimpleSync() {
    unk34 = (unsigned char)(unk34 & 0xFFFFFFBF);
    fn_80218D5C(fn_8002B4E8);
    return (fn_80218D58() - 1) == 0;
}
