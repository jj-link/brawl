#pragma force_active on
extern "C" {
extern float lbl_27_data_547E0;
extern const float lbl_70_rodata_48;
struct Obj {
    char pad0[0x64];
    float rate;
    char pad1[5];
    unsigned char flags;
    char pad2[0x1c8 - 0x6e];
    void* anim;
};
struct GG { char pad[0x44]; struct { float a; float b; float c; }* p; };
extern GG* g_GameGlobal;
void setUpdateRate__16gfModelAnimationFf(void*, float);
void processAnim__6GroundFv(void*);

void fn_70_2E94(Obj* self) {
    GG* g = g_GameGlobal;
    float k = lbl_27_data_547E0;
    float f = self->rate * k;
    f *= g->p->b;
    f *= g->p->c;
    if ((unsigned int)((self->flags >> 4) & 1) == 1) f = lbl_70_rodata_48;
    setUpdateRate__16gfModelAnimationFf(self->anim, f);
    processAnim__6GroundFv(self);
}
}
