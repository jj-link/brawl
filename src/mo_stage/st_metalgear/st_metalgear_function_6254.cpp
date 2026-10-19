#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;

struct grCollJoint {
    char pad0[0x50];
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
    char pad1[0x130];
    grCollJoint* m180;
    grCollJoint* m184;
};

extern "C" {
    extern char lbl_71_data_15A0[];
    extern char lbl_71_data_15B8[];
    void getNodeIndex__6GroundFPUlUlPCc(Ground* self, u32* out, u32 flag, const char* name);
    grCollJoint* getJoint__11grCollisionFUs(grCollision* coll, u32 idx);
}

extern "C" void fn_71_6254(Ground* self) {
    grCollision* coll;
    u32 i;
    u16 count;
    u32 idx1;
    u32 idx2;
    grCollJoint* j;

    if (self->m180 != 0) {
        return;
    }
    coll = self->m4c;
    if (coll == 0) {
        return;
    }
    getNodeIndex__6GroundFPUlUlPCc(self, &idx1, 0, lbl_71_data_15A0);
    getNodeIndex__6GroundFPUlUlPCc(self, &idx2, 0, lbl_71_data_15B8);
    count = coll->m6;
    for (i = 0; i != count; i++) {
        j = getJoint__11grCollisionFUs(coll, i);
        if (j != 0 && j->m58 == self) {
            if (idx1 == j->m50) {
                self->m180 = j;
            } else if (idx2 == j->m50) {
                self->m184 = j;
            }
        }
        if (self->m180 != 0 && self->m184 != 0) {
            break;
        }
    }
}
