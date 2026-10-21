#pragma force_active on

class WorkModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int getInt(unsigned int);
};

class MotionModule {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void setRate(float);
};

extern "C" {
extern void* g_ftManager;
extern const float lbl_102_rodata_3C;

int fn_27_10A4B0(void*, int);
int fn_27_10AA8C(void*, int, int);
void fn_27_10C0DC(void*, int, unsigned char, bool, bool);
void fn_27_10D968(void*, int, int, int, int, int);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned long, unsigned long);
void fn_27_130D64(void*);

void fn_102_12F1C(void* self) {
    void* accesser = *(void**)((char*)self + 0x60);
    void* modules = *(void**)((char*)accesser + 0xd8);
    WorkModule* work = *(WorkModule**)((char*)modules + 0x64);

    if (work->getInt(0x10000040) > 0 &&
        (unsigned char)fn_27_10A4B0(
            g_ftManager, *(int*)((char*)self + 0x10c)) > 1) {
        int enabled = fn_27_10AA8C(
            g_ftManager, *(int*)((char*)self + 0x10c),
            *(int*)((char*)self + 0x28));

        MotionModule* motion = *(MotionModule**)(
            (char*)*(void**)((char*)accesser + 0xd8) + 8);
        motion->setRate(lbl_102_rodata_3C);

        fn_27_10C0DC(
            g_ftManager, *(int*)((char*)self + 0x10c),
            !(unsigned char)enabled, 0, 0);

        int id = *(int*)((char*)self + 0x10c);
        void* manager = g_ftManager;
        int frames =
            getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                accesser, 0x5a38, 0);
        fn_27_10D968(
            manager, id, 6, frames, 0, *(int*)((char*)self + 0x28));
    }

    fn_27_130D64(self);
}
}
