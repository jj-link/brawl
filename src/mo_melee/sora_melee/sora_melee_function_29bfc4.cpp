#pragma force_active on
extern "C" void* getInstance__16CameraControllerFv();
extern "C" void fn_8009D250(void*);

extern "C" void fn_27_29BFC4() {
    if (getInstance__16CameraControllerFv() != 0) {
        fn_8009D250(getInstance__16CameraControllerFv());
    }
}
