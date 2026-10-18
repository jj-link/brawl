#pragma force_active on
extern "C" {

struct DXGreenGlobal
{
    unsigned char pad0[0x24];
    float f24;
    float f28;
    float f2c;
    unsigned char pad1[8];
    int i38;
    unsigned char pad2[0x2c];
};

struct Chain
{
    void *next;
    void *destructor;
    void *object;
};

extern DXGreenGlobal lbl_79_bss_D8;
extern signed char lbl_79_bss_D0;
extern float lbl_79_rodata_44;
extern Chain lbl_79_bss_3C;
void __register_global_object(void *object, void *destructor, void *chain);
void fn_79_31DC(void *object);

void *fn_79_55DC()
{
    if (lbl_79_bss_D0 == 0)
    {
        lbl_79_bss_D8.f24 = lbl_79_rodata_44;
        lbl_79_bss_D8.f28 = lbl_79_rodata_44;
        lbl_79_bss_D8.f2c = lbl_79_rodata_44;
        lbl_79_bss_D8.i38 &= ~0x1f;
        __register_global_object(&lbl_79_bss_D8, (void *)fn_79_31DC, &lbl_79_bss_3C);
        lbl_79_bss_D0 = 1;
    }
    return &lbl_79_bss_D8;
}

}
