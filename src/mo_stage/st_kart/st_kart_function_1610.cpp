#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct grCollJoint {
    char pad0[0x4E];
    u16 m4e;
    u16 m50;
    char pad1[0x3];
    u8 m55;
    char pad2[0x2];
    void* m58;
};

struct grCollision {
    char pad0[0x6];
    u16 m6;
};

struct Ground {
    char pad0[0x4C];
    grCollision* m4c;
    char pad1[0x108];
    u8* m158;
    grCollJoint* m15c;
    grCollJoint* m160;
    grCollJoint* m164;
    grCollJoint* m168;
};

extern "C" {
    int getNodeIndex__6GroundFPUlUlPCc(Ground* self, u32* out, u32 flag, const char* name);
    grCollJoint* getJoint__11grCollisionFUs(grCollision* coll, u32 idx);
}

extern "C" void fn_49_1610(Ground* self) {
    grCollision* coll;
    u32 idx4;
    u32 idx3;
    u32 idx2;
    u32 idx1;
    u32 i;
    u16 count;
    grCollJoint* j;

    if (self->m15c != 0 && self->m160 != 0 && self->m164 != 0 && self->m168 != 0) {
        switch (*self->m158) {
        case 8:
            self->m15c->m55 = (u8)(self->m15c->m55 & ~0x08);
            self->m160->m55 = (u8)(self->m160->m55 & ~0x08);
            self->m164->m55 = (u8)(self->m164->m55 & ~0x08);
            self->m168->m55 = (u8)(self->m168->m55 | 0x08);
            return;
        case 9:
            self->m15c->m55 = (u8)(self->m15c->m55 | 0x08);
            self->m160->m55 = (u8)(self->m160->m55 | 0x08);
            self->m164->m55 = (u8)(self->m164->m55 | 0x08);
            self->m168->m55 = (u8)(self->m168->m55 & ~0x08);
            return;
        default:
            self->m15c->m55 = (u8)(self->m15c->m55 & ~0x08);
            self->m160->m55 = (u8)(self->m160->m55 & ~0x08);
            self->m164->m55 = (u8)(self->m164->m55 & ~0x08);
            self->m168->m55 = (u8)(self->m168->m55 & ~0x08);
            return;
        }
    } else {
        coll = self->m4c;
        if (coll != 0 &&
            getNodeIndex__6GroundFPUlUlPCc(self, &idx1, 0, "AshibaCN") != 0 &&
            getNodeIndex__6GroundFPUlUlPCc(self, &idx2, 0, "AshibaLN") != 0 &&
            getNodeIndex__6GroundFPUlUlPCc(self, &idx3, 0, "AshibaRN") != 0 &&
            getNodeIndex__6GroundFPUlUlPCc(self, &idx4, 0, "lord") != 0) {
            count = coll->m6;
            for (i = 0; i != count; i++) {
                j = getJoint__11grCollisionFUs(coll, i);
                if (j == 0) {
                    return;
                }
                if (j->m58 == self && j->m4e == 0) {
                    if (idx1 == j->m50) {
                        self->m15c = j;
                    } else if (idx2 == j->m50) {
                        self->m160 = j;
                    } else if (idx3 == j->m50) {
                        self->m164 = j;
                    } else if (idx4 == j->m50) {
                        self->m168 = j;
                    }
                }
                if (self->m15c != 0 && self->m160 != 0 && self->m164 != 0 && self->m168 != 0) {
                    return;
                }
            }
        }
    }
}
