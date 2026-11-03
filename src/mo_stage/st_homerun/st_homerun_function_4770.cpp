#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct grCollJoint {
    char pad0[0x4E];
    u16 m4e;
    u16 m50;
    char pad1[0x2];
    u8 f80 : 1;
    u8 f40 : 1;
    u8 f20 : 1;
    u8 f10 : 1;
    u8 frest : 4;
    char pad2[0x1];
    u8 m56;
    char pad3[0x1];
    void* m58;
};

struct grCollision {
    char pad0[0x6];
    u16 m6;
};

struct Ground {
    char pad0[0x4c];
    grCollision* m4c;
    char pad1[0x118];
    u8* m168;
    char pad2[0x14];
    grCollJoint* m180;
};

extern "C" {
    extern char lbl_88_data_AE8[];
    int getNodeIndex__6GroundFPUlUlPCc(Ground* self, u32* out, u32 flag, const char* name);
    grCollJoint* getJoint__11grCollisionFUs(grCollision* coll, u32 idx);
}

extern "C" void fn_88_4770(Ground* self) {
    grCollJoint* j;
    grCollision* coll;
    u32 idx;
    u32 i;
    u16 count;
    int state;

    if (self->m180 != 0) {
        state = *self->m168;
        switch (state) {
        case 3:
        case 4:
            j = self->m180;
            j->f80 = 0;
            j->f10 = j->f80;
            j->f40 = j->f10;
            break;
        default:
            break;
        }
        return;
    }
    coll = self->m4c;
    if (coll == 0) {
        return;
    }
    getNodeIndex__6GroundFPUlUlPCc(self, &idx, 0, lbl_88_data_AE8);
    count = coll->m6;
    for (i = 0; i != count; i++) {
        j = getJoint__11grCollisionFUs(coll, i);
        if (j == 0) {
            return;
        }
        if (j->m58 == self && j->m4e == 0 && idx == j->m50) {
            j->m56 = (u8)(j->m56 | 0x80);
            j->f10 = 1;
            j->f40 = j->f10;
            self->m180 = j;
            return;
        }
    }
}
