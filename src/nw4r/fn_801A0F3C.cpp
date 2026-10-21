#pragma force_active on

extern "C" {
    extern unsigned char lbl_804A5514[0x2A2C];
    extern void* fn_8019EBAC(void* a, void* b);

    void* fn_801A0F3C(void* self)
    {
        return fn_8019EBAC(lbl_804A5514, self);
    }
}
