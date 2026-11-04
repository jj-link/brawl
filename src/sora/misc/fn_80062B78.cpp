#include <mt/mt_matrix.h>
#pragma force_active on

namespace nw4r { namespace g3d { class ScnMdlSimple; } }
struct Node {
    char pad[0x1c];
    nw4r::g3d::ScnMdlSimple* model;
    char pad20[2];
    unsigned short index;
    Vec3f position;
    void set(nw4r::g3d::ScnMdlSimple* m, unsigned short i) { model = m; index = i; }
};
struct Entry {
    char pad[4];
    void* value;
    char rest[8];
};
struct Table {
    char pad[0xc];
    Entry* entries;
};
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
    nw4r::g3d::ScnMdlSimple* model;
    unsigned short index;
    unsigned short flags;
};
extern "C" void fn_800613B8(Matrix*, nw4r::g3d::ScnMdlSimple*, unsigned short, const Vec3f*, const Vec3f*, const Vec3f*);
extern "C" void fn_801AAF04(void*, int, Matrix*);
inline void setPosition(Vec3f& p, float z, float y, float x) { p.m_y = y; p.m_x = x; p.m_z = z; }
extern "C" void fn_80062B78(Object* self) {
    Entry* entry = self->table->entries + self->entryIndex;
    if (!(self->flags & 1)) {
        if (self->target) {
            Matrix m(true);
            fn_800613B8(&m, self->model, self->index, &self->scale, &self->rotation, &self->position);
            fn_801AAF04(self->target, 0, &m);
        }
        if (entry[1].value && self->nodes) {
            Node* node = *(Node**)((char*)(self->nodes + self->nodeIndex) - 4);
            if (node) {
                node->set(self->model, self->index);
            }
        }
    } else {
        Matrix m(true);
        fn_800613B8(&m, self->model, self->index, &self->scale, &self->rotation, &self->position);
        Vec3f pos;
        float z = m.m[2][3];
        float y = m.m[1][3];
        float x = m.m[0][3];
        setPosition(pos, z, y, x);
        if (self->target) {
            m.setSRT(self->scale, self->rotation, pos);
            fn_801AAF04(self->target, 0, &m);
        }
        if (entry[1].value && self->nodes) {
            Node* node = *(Node**)((char*)(self->nodes + self->nodeIndex) - 4);
            if (node) {
                node->position = pos;
            }
        }
    }
}