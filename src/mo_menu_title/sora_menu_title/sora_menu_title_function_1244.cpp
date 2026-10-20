#pragma force_active on
extern "C" {
extern const float lbl_24_rodata_28;
void setUpdateRate__16gfModelAnimationFf(void*, float);
}

struct AnimationHolder {
    char pad[0x14];
    void* animation;
};

struct Title {
    char pad[0x48];
    AnimationHolder* holder;
    int state;
    int counter;
};

extern "C" void fn_24_1244(Title* self) {
    switch (self->state) {
    case 0:
        break;
    case 1:
        self->state = 2;
        break;
    case 2:
        setUpdateRate__16gfModelAnimationFf(
            self->holder->animation, lbl_24_rodata_28);
        self->state = 3;
        break;
    case 3:
        break;
    }
    self->counter++;
}
