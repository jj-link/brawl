#pragma force_active on

class CameraController {
public:
    enum Kind { kind0 = 0 };
    void changeInput(Kind kind);
};

extern void* lbl_805A0278;
extern "C" void fn_800AA184(void*, int, int, int, int);

extern "C" void fn_8009CDE8(CameraController* self, int a, int b, int c, int d) {
    void* p = lbl_805A0278;
    char* target = *(char**)((char*)p + 0x78);
    fn_800AA184(target, a, b, c, d);
    *(unsigned char*)(target + 0x10) = *(int*)((char*)self + 0x40);
    self->changeInput((CameraController::Kind)0xB);
}
