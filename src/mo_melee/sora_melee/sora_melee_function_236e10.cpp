#pragma force_active on
typedef unsigned char u8;

extern "C" void* getInstance__16CameraControllerFv();
extern "C" int fn_8009CC2C(void* cam, void* arg);

extern "C" void fn_27_236E10(u8* self) {
    if (getInstance__16CameraControllerFv()) {
        if (fn_8009CC2C(getInstance__16CameraControllerFv(), self + 0x10)) {
            u8* flag = *(u8**)(self + 0x8);
            *flag = 1;
        }
    }
}
