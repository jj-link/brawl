#pragma force_active on
extern "C" void changeInput__16CameraControllerFQ216CameraController4Kind(void*, int);
extern "C" void fn_800A9E4C(void*);

struct Inner {
    char pad0[8];
    unsigned int a8;
    char padc[4];
    unsigned char a10;
};
struct Mgr {
    char pad0[0x78];
    Inner* p78;
};
struct Ctrl {
    char pad0[0x40];
    int a40;
};
extern Mgr* lbl_805A0278;

extern "C" void fn_8009CE3C(Ctrl* self, unsigned int arg) {
    if (self->a40 == 0xb) {
        Inner* p = lbl_805A0278->p78;
        if (arg == 0 || arg == p->a8) {
            fn_800A9E4C(p);
            changeInput__16CameraControllerFQ216CameraController4Kind(self, p->a10);
        }
    }
}
