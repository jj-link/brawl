#include <gf/gf_camera.h>
#pragma force_active on

class Class_4328 {
public:
    virtual void fn_27_48BE8();
    virtual void* fn_27_48DA8(int);
    virtual void fn_27_48E2C();
    virtual int fn_27_48ED0();
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
};

struct CameraData { int words[12]; };
struct Self {
    char pad[0x20];
    void* data;
    char pad24[4];
    char field28[0x20];
    Class_4328* object;
};

extern "C" void fn_27_47180(void*, void*, void*, void*);

extern "C" void fn_27_49958(Self* self) {
    CameraData camera = *reinterpret_cast<CameraData*>(gfCameraManager::getManager());
    int count = self->object->fn_27_48ED0();
    for (int i = 0; i < count; i++) {
        fn_27_47180(self->object->fn_27_48DA8(i), &camera, self->field28, self->data);
    }
}
