#pragma force_active on
struct MarioVec3Slot {
    unsigned int pad;
    unsigned int x;
    unsigned int y;
    unsigned int z;
};

extern "C" {
void* fn_91_AA30(void*, void*, void*);

void* fn_91_A9DC(void* self, void* arg) {
    struct Triple {
        unsigned int a;
        unsigned int b;
        unsigned int c;
    } tmp;
    fn_91_AA30(&tmp, self, arg);
    MarioVec3Slot* dst = static_cast<MarioVec3Slot*>(self);
    dst->x = tmp.a;
    dst->y = tmp.b;
    dst->z = tmp.c;
    return &dst->x;
}
}
