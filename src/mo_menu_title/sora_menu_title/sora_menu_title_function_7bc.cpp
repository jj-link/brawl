#pragma force_active on
class gfModelAnimation {
public:
    void setUpdateRate(float);
};
class MuObject {
public:
    char pad[0x14];
    gfModelAnimation* anim;
};
extern "C" {
void fn_800B753C(MuObject*, float);
unsigned int fn_800B63B8(MuObject*);
extern float lbl_24_rodata_8;
extern float lbl_24_rodata_C;
}
struct S {
    char pad[0x48];
    MuObject* a;
    unsigned int state;
    int cnt;
};
extern "C" void fn_24_7BC(S* self) {
    switch (self->state) {
    case 0:
        break;
    case 1:
        self->state = 2;
        break;
    case 2:
        fn_800B753C(self->a, lbl_24_rodata_8);
        self->a->anim->setUpdateRate(lbl_24_rodata_C);
        self->state = 3;
        self->cnt = 0;
        break;
    case 3:
        if (fn_800B63B8(self->a) == 1) self->state = 4;
        break;
    case 4:
        if (self->cnt >= 0x78) self->state = 5;
        break;
    case 5:
        self->state = 6;
        break;
    case 6:
        break;
    case 7:
        self->state++;
        break;
    }
    self->cnt++;
}