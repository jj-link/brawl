#pragma force_active on
class soModuleAccesser;
struct soValueAccesser {
    static float getValueFloat(soModuleAccesser*, unsigned long, unsigned long);
};
struct A { char pad[0x1c]; int unk1c; };
struct B { char pad[0x3c]; soModuleAccesser* acc; };

extern "C" float fn_41_12784(B* self, A* p) {
    float v = soValueAccesser::getValueFloat(self->acc, 0xbea, 0);
    if (p->unk1c != 0) {
        v *= soValueAccesser::getValueFloat(self->acc, 0xbf8, 0);
    }
    return v;
}
