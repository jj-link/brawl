#include <mt/mt_matrix.h>
#include <mt/mt_vector.h>
#pragma force_active on
struct Entry { char pad[4]; void* value; char rest[8]; };
struct Table { char pad[0xc]; Entry* entries; };
struct Node { char pad[0x30]; Vec3f rotation; };
struct Object {
    Vec3f position;
    Vec3f rotation;
    Vec3f scale;
    char pad24[8];
    int entryIndex;
    Table* table;
    Node** nodes;
    int nodeIndex;
    char pad3c[8];
    void* target;
    char pad48[8];
    int field50;
    char pad54[0x10];
    int field64;
};
extern "C" void fn_801AAF04(void*, int, Matrix*);
extern "C" void fn_800632D0(Object* self, const Vec3f* rotation) {
    Matrix mtx(true);
    self->rotation.m_x = rotation->m_x;
    self->rotation.m_y = rotation->m_y;
    self->rotation.m_z = rotation->m_z;
    if (self->field64 == 0 && self->field50 == 0 && self->target != 0) {
        mtx.setSRT(self->scale, self->rotation, self->position);
        fn_801AAF04(self->target, 0, &mtx);
    }
    Entry* entry = self->table->entries + self->entryIndex;
    if (entry[1].value && self->nodes) {
        Node* node = *(Node**)((char*)(self->nodes + self->nodeIndex) - 4);
        if (node) {
            node->rotation = self->rotation;
        }
    }
}