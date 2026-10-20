#pragma force_active on
typedef unsigned char u8;

extern "C" void fn_27_26399C(void*);
extern "C" void playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(void*, void*);

extern "C" void fn_63_11CF8(void* self) {
    u8* p = reinterpret_cast<u8*>(self);
    fn_27_26399C(*reinterpret_cast<void**>(p + 0x14c));
    void* obj = *reinterpret_cast<void**>(p + 0x174);
    if (obj != 0) {
        if (reinterpret_cast<u8*>(obj)[0x60] != 1) {
            playSE__14snd3DGeneratorF5SndIDiii(p + 0x1a4, 0x1c94, 0, 0, -1);
            setPos__14snd3DGeneratorFP5Vec3f(p + 0x1a4, p + 0x180);
        }
        reinterpret_cast<u8*>(*reinterpret_cast<void**>(p + 0x174))[0x60] = 1;
    }
}
