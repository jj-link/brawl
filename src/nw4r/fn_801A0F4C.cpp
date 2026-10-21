#pragma force_active on
extern unsigned char lbl_804A5514[0x2A2C];

extern "C" void* fn_801A0F4C(int id) {
    if (id >= 0 && id < 0x80) {
        return lbl_804A5514 + id * 0x44 + 0x2C;
    }
    return 0;
}
