#include <types.h>
#include <mt/mt_matrix.h>
#include <gr/collision/gr_collision_handle.h>
#pragma force_active on

namespace nw4r { namespace g3d { class ScnMdlSimple; } }
struct Entry {
    char pad[4];
    void* value;
    char rest[8];
};
struct Table { char pad[12]; Entry* entries; };
struct Node { char pad[0x24]; Vec3f position; };
struct Vertex { Vec2f pos; char pad[8]; };
struct Collision { char pad[0x10]; Vertex* vertices; };
struct Object {
    Vec3f position;
    Vec3f rotation;
    Vec3f scale;
    char pad24[8];
    int entryIndex;
    Table* table;
    Node** nodes;
    int nodeIndex;
    void* p3c;
    char pad40[4];
    void* target;
    char pad48[8];
    nw4r::g3d::ScnMdlSimple* model;
    unsigned short index;
    unsigned short flags;
    char pad58[4];
    Collision* collision;
    char pad60[4];
    unsigned short* indices;
    char pad68[4];
    float fraction;
};
extern "C" void fn_800613B8(Matrix*, nw4r::g3d::ScnMdlSimple*, unsigned short, const Vec3f*, const Vec3f*, const Vec3f*);
extern "C" void fn_801AAF04(void*, int, Matrix*);
inline void setPosition(Vec3f& p, float z, float y, float x) { p.m_y = y; p.m_x = x; p.m_z = z; }
extern "C" void fn_8006242C(Object* self) {
    Entry* entry = self->table->entries + self->entryIndex;
    if (self->model) {
        Matrix m(true);
        if (!(self->flags & 1)) {
            if (self->p3c && self->target) {
                fn_800613B8(&m, self->model, self->index, &self->scale, &self->rotation, &self->position);
                fn_801AAF04(self->target, 0, &m);
            }
        } else {
            fn_800613B8(&m, self->model, self->index, &self->scale, &self->rotation, &self->position);
            Vec3f pos;
            float z = m.m[2][3];
            float y = m.m[1][3];
            float x = m.m[0][3];
            setPosition(pos, z, y, x);
            if (self->p3c && self->target) {
                m.setSRT(self->scale, self->rotation, pos);
                fn_801AAF04(self->target, 0, &m);
            }
            if (entry[1].value && self->nodes) {
                Node* node = *(Node**)((char*)(self->nodes + self->nodeIndex) - 4);
                if (node) node->position = pos;
            }
        }
    } else if (self->indices && ((grCollisionHandle*)&self->collision)->isValid()) {
        Vertex* vertices = self->collision->vertices;
        if (vertices) {
            Vec2f point;
            Vec2f a = vertices[self->indices[0]].pos;
            Vec2f b = vertices[self->indices[1]].pos;
            point = (b - a) * self->fraction + a;
            Vec3f pos;
            Vec3f temp(self->position.m_x + point.m_x, self->position.m_y + point.m_y, self->position.m_z);
            pos = temp;
            if (self->p3c && self->target) {
                Matrix m(true);
                m.setSRT(self->scale, self->rotation, pos);
                fn_801AAF04(self->target, 0, &m);
            }
            if (entry[1].value && self->nodes) {
                Node* node = *(Node**)((char*)(self->nodes + self->nodeIndex) - 4);
                if (node) node->position = pos;
            }
        }
    }
}
