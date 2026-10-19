#pragma force_active on
extern "C" const float lbl_68_rodata_98;

struct Thing {
    unsigned char _[0x60];
    float x, y, z;
    unsigned char _2[8];
    unsigned int flag;
};

extern "C" void fn_68_61E0(Thing* t) {
    t->x = lbl_68_rodata_98;
    t->y = lbl_68_rodata_98;
    t->z = lbl_68_rodata_98;
    t->flag &= ~0x1F;
}
