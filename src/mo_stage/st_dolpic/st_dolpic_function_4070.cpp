#pragma force_active on

struct Vec3f {
    float x;
    float y;
    float z;
};

struct snd3DGenerator {
    char _pad[0x20];
};

struct DolpicObject {
    char _pad[0x224];
    snd3DGenerator se;
    int handle;
};

extern "C" const float lbl_46_rodata_0;
extern "C" void* g_sndSystem;

extern "C" int playSE__14snd3DGeneratorF5SndIDiii(
    snd3DGenerator*, int, int, int, int);
extern "C" void setPos__14snd3DGeneratorFP5Vec3f(snd3DGenerator*, Vec3f*);
extern "C" void stopSE__14snd3DGeneratorFll(snd3DGenerator*, int, int);
extern "C" void fn_800777DC(void*, int, float, int);
extern "C" void fn_800778CC(void*, int, float);

extern "C" void fn_46_4070(DolpicObject* self, float value, int index) {
    if (index >= 5 || index < 0)
        return;

    int handle = self->handle;
    if (handle == -1) {
        if (value > lbl_46_rodata_0) {
            handle = playSE__14snd3DGeneratorF5SndIDiii(
                &self->se, 0x1b4d, 0, 0, -1);
            self->handle = handle;

            Vec3f position;
            position.x = lbl_46_rodata_0;
            position.y = lbl_46_rodata_0;
            position.z = lbl_46_rodata_0;
            setPos__14snd3DGeneratorFP5Vec3f(&self->se, &position);
            return;
        }
    }

    if (handle == -1)
        return;

    fn_800777DC(g_sndSystem, handle, value, 0);
    fn_800778CC(g_sndSystem, self->handle, value);

    if (lbl_46_rodata_0 == value) {
        stopSE__14snd3DGeneratorFll(&self->se, self->handle, 0);
        self->handle = -1;
    }
}
