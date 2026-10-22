#pragma force_active on
struct Joint {
    unsigned char pad[0x56];
    unsigned char flags;
};

struct Collision {
    unsigned char pad[0x6];
    unsigned short num_joints;
};

extern "C" {
void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
Joint* getJoint__11grCollisionFUs(Collision*, int);
}

struct GwObj {
    unsigned char pad0[0x4C];
    Collision* collision;
    unsigned char pad1[0x154];
    Joint** joint_array;
};

extern "C" void fn_63_3E58(GwObj* self) {
    int off;
    if (self->joint_array == 0) {
        Collision* col = self->collision;
        if (col != 0) {
            Joint** arr = (Joint**)__nwa__FUlQ25Heaps8HeapType(0x50, 15);
            self->joint_array = arr;
            if (arr != 0) {
                unsigned i = 0;
                unsigned short count = col->num_joints;
                off = 0;
                while (i != count) {
                    Joint* j = getJoint__11grCollisionFUs(col, i);
                    if (j != 0) {
                        j->flags |= 0x80;
                        *(Joint**)((char*)self->joint_array + off) = j;
                    }
                    off += 4;
                    i++;
                }
            }
        }
    }
}
