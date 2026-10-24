#pragma force_active on

struct Vec3f {
    float x, y, z;
};

struct StatusModule {
    virtual void s08();
    virtual void s0C();
    virtual void invoke(int);
};

struct WorkModule {
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual int getInt(unsigned int);
};

struct EffectModule {
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void s2C();
    virtual void s30();
    virtual void invoke(unsigned int, unsigned int,
                        const Vec3f*, const Vec3f*,
                        float, int, int, int, int);
};

extern "C" {
extern void* g_ftManager;
extern const float lbl_113_rodata_C;
extern const float lbl_113_rodata_4;

void fn_113_2435C(void*);
void fn_27_12BAF8(void*, int);
void* getOwner__9ftManagerFi(void*, int);
int fn_27_111E30(void*);
int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
    void*, unsigned int, unsigned int);
Vec3f* fn_113_A1D0(Vec3f*, float, float, float);

void fn_113_A084(char* self, int arg1) {
    StatusModule* status =
        *(StatusModule**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x84);
    status->invoke(1);

    fn_113_2435C(self + 0x1FD08);
    fn_27_12BAF8(self, arg1);

    WorkModule* work =
        *(WorkModule**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x64);
    int id = work->getInt(0x10000000);

    if (fn_27_111E30(getOwner__9ftManagerFi(g_ftManager, id)) == 0) {
        arg1 = getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
            *(void**)(self + 0x60), 0x10000036, 0);
        if (arg1 == 0xC) {
            arg1 = 0;
        }

        EffectModule* effect =
            *(EffectModule**)(*(char**)(*(char**)(self + 0x60) + 0xD8) + 0x88);
        Vec3f a, b;

        effect->invoke(
            0x1A000E, 0x1E,
            fn_113_A1D0(&a, lbl_113_rodata_C,
                        lbl_113_rodata_C, lbl_113_rodata_C),
            fn_113_A1D0(&b, lbl_113_rodata_C,
                        lbl_113_rodata_C, lbl_113_rodata_C),
            lbl_113_rodata_4, 1, 0x10, arg1, -1);
    }
}
}
