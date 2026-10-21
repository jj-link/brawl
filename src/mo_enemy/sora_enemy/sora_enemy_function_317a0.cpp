#pragma force_active on
extern "C" const float lbl_41_rodata_E30;

struct AnimModule {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4(int, void*, float);
    virtual void vf5();
    virtual void vf6();
    virtual void vf7(int, int, void*);
};

struct ModuleTable {
    char pad[0x6C];
    AnimModule* anim;
};

struct Accesser {
    char pad[0xD8];
    ModuleTable* modules;
};

struct wnemSimple {
    char pad[0x6C];
    Accesser* accesser;
};

extern "C" void executeAnimCmd__10wnemSimpleFlll(
    wnemSimple* self, int command, int kind, int mode)
{
    if (command != 0) {
        AnimModule* anim = self->accesser->modules->anim;
        if (mode == 0) {
            if (kind == 2) {
                anim->vf7(kind, command, self->accesser);
                return;
            }
            anim->vf4(kind, self->accesser, lbl_41_rodata_E30);
            return;
        }
        anim->vf7(kind, command, self->accesser);
        anim->vf4(kind, self->accesser, lbl_41_rodata_E30);
        anim->vf7(kind, 0, self->accesser);
    }
}
