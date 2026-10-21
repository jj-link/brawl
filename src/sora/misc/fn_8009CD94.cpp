#pragma force_active on
struct CameraController {
    char pad0[0x40];
    int unk40;
};

extern "C" void fn_800A9E58(void*, int, int, int);
extern "C" void changeInput__16CameraControllerFQ216CameraController4Kind(CameraController*, int);
extern void* lbl_805A0278;

extern "C" void fn_8009CD94(CameraController* arg0, int a, int b, int c) {
    char* target = *(char**)((char*)lbl_805A0278 + 0x78);
    fn_800A9E58(target, a, b, c);
    target[0x10] = (char)arg0->unk40;
    changeInput__16CameraControllerFQ216CameraController4Kind(arg0, 0xB);
}
