#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

extern "C" void setAreaSleep__9stTriggerFb(void* trigger, bool sleep);
extern "C" int playSE__14snd3DGeneratorF5SndIDiii(void* gen, int id, int a, int b, int c);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void* gen, Vec3f* pos);
extern "C" const float lbl_73_rodata_78;

extern "C" void fn_73_78E0(char* self) {
    if (*(void**)(self + 0x2a0) != 0) {
        setAreaSleep__9stTriggerFb(*(void**)(self + 0x2a0), false);
    }
    *(int*)(self + 0x29c) = playSE__14snd3DGeneratorF5SndIDiii(self + 0x294, 0x1d27, 0, 0, -1);
    Vec3f pos;
    pos.x = lbl_73_rodata_78;
    pos.y = lbl_73_rodata_78;
    pos.z = lbl_73_rodata_78;
    setPos__14snd3DGeneratorFP5Vec3f(self + 0x294, &pos);
}
