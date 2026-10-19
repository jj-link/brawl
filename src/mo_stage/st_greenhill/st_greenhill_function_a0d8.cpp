#pragma force_active on
struct Joint {
    char padding[0x58];
    void* owner;
};

struct Collision {
    char padding[6];
    unsigned short count;
};

struct Object {
    char padding0[0x4C];
    Collision* collision;
    char padding1[0x138];
    Joint* joint;
};

extern "C" Joint* getJoint__11grCollisionFUs(Collision*, unsigned int);

extern "C" void fn_72_A0D8(Object* self) {
    if (self->joint == 0) {
        unsigned int count;
        Collision* collision = self->collision;
        if (collision != 0) {
            count = collision->count;
            unsigned int i;
            Joint* joint;
            for (i = 0; i != count; ++i) {
                joint = getJoint__11grCollisionFUs(collision, i);
                if (joint != 0 && joint->owner == self)
                    break;
            }
            if (i != count)
                self->joint = joint;
        }
    }
}
