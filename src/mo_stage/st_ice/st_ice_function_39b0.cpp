#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct grCollJoint {
    char pad0[0x4E];
    u16 m4e;
    u16 m50;
    char pad1[0x6];
    void* m58;
};

struct grCollision {
    char pad0[0x6];
    u16 m6;
};

struct Ground {
    char pad0[0x4c];
    grCollision* m4c;
    char pad1[0x160];
    grCollJoint* m1b0;
};

extern "C" {
    extern char lbl_62_data_DB0[];
    int getNodeIndex__6GroundFPUlUlPCc(Ground* self, u32* out, u32 flag, const char* name);
    grCollJoint* getJoint__11grCollisionFUs(grCollision* coll, u32 idx);
}

extern "C" void fn_62_39B0(Ground* self) {
    grCollision* coll;
    u32 idx;
    u32 i;
    u16 count;
    grCollJoint* j;

    if (self->m1b0 != 0) {
        return;
    }
    coll = self->m4c;
    if (coll == 0) {
        return;
    }
    if (getNodeIndex__6GroundFPUlUlPCc(self, &idx, 0, lbl_62_data_DB0) == 0) {
        return;
    }
    count = coll->m6;
    for (i = 0; i != count; i++) {
        j = getJoint__11grCollisionFUs(coll, i);
        if (j == 0) {
            return;
        }
        if (j->m58 == self && j->m4e == 0 && idx == j->m50) {
            self->m1b0 = j;
            return;
        }
    }
}
