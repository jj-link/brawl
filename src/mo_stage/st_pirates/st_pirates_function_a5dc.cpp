#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct grCollJoint {
    char pad0[0x4E];
    u16 m4e;
    u16 m50;
    char pad1[0x4];
    u8 m56;
    char pad2[0x1];
    void* m58;
};

struct grCollision {
    char pad0[0x6];
    u16 m6;
};

struct Ground {
    char pad0[0x4c];
    grCollision* m4c;
    char pad1[0x120];
    grCollJoint* m170;
};

extern "C" {
    extern char lbl_52_data_2338[];
    int getNodeIndex__6GroundFPUlUlPCc(Ground* self, u32* out, u32 flag, const char* name);
    grCollJoint* getJoint__11grCollisionFUs(grCollision* coll, u32 idx);
}

extern "C" void fn_52_A5DC(Ground* self) {
    grCollision* coll;
    u32 idx;
    u16 count;
    u32 i;
    grCollJoint* j;

    if (self->m170 != 0) {
        return;
    }
    coll = self->m4c;
    if (coll == 0) {
        return;
    }
    if (getNodeIndex__6GroundFPUlUlPCc(self, &idx, 0, lbl_52_data_2338) == 0) {
        return;
    }
    count = coll->m6;
    for (i = 0; i != count; i++) {
        j = getJoint__11grCollisionFUs(coll, i);
        if (j == 0) {
            continue;
        }
        if (j->m58 == self && j->m4e == 0 && idx == j->m50) {
            self->m170 = j;
            j->m56 = (u8)(j->m56 | 0x80);
            return;
        }
    }
}