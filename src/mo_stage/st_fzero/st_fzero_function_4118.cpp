#pragma force_active on
extern "C" void* getJoint__11grCollisionFUs(void*, unsigned short);

struct Fzero {
    unsigned char pad0[0x4C];
    void* collision;
    unsigned char pad1[0x184];
    void* joints[7];
};

extern "C" void fn_61_4118(Fzero* self) {
    if (self->joints[0] == 0 ||
        self->joints[1] == 0 ||
        self->joints[2] == 0 ||
        self->joints[3] == 0 ||
        self->joints[4] == 0 ||
        self->joints[5] == 0 ||
        self->joints[6] == 0) {
        void* collision = self->collision;
        if (collision != 0) {
            self->joints[0] = getJoint__11grCollisionFUs(collision, 0);
            self->joints[1] = getJoint__11grCollisionFUs(collision, 1);
            self->joints[2] = getJoint__11grCollisionFUs(collision, 2);
            self->joints[3] = getJoint__11grCollisionFUs(collision, 3);
            self->joints[4] = getJoint__11grCollisionFUs(collision, 4);
            self->joints[5] = getJoint__11grCollisionFUs(collision, 5);
            self->joints[6] = getJoint__11grCollisionFUs(collision, 6);
        }
    }
}
