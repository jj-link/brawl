#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;

struct Node;
struct Link { Node* parent; Node* child; };
struct Node {
    char pad00[0x80];
    float length;
    char pad84[0x2C];
    float weight;
    char padB4[0x28];
    MTX34 matrix;
    char pad10C[0xB8];
    unsigned char flag;
    char pad1C5[0x33];
    Link* parent;
    Link** children;
    int childCount;
};
struct Context {
    char pad00[0x3A];
    unsigned char flag;
    unsigned char flip;
};
extern "C" {
void fn_801EC158(MTX34*);
void fn_801ED0B0(const VEC3*, const VEC3*, VEC3*);
void fn_80162974(MTX34*, const VEC3*, float);
void fn_801629AC(MTX34*, float, float, float);
void fn_801EC868(const MTX34*, MTX34*, float, float, float);
void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);
extern const float lbl_805A1BB8;
extern const float lbl_805A1BBC;
extern const float lbl_805A1BFC;
extern const float lbl_805A1C00;
extern const float lbl_805A1C04;
}
extern "C" void fn_80084524(Context* self, Node* node) {
    if (lbl_805A1BB8 != node->weight || node->parent == 0) {
        MTX34 identity;
        fn_801EC158(&identity);
        MTX34 current = node->matrix;
        VEC3 direction(node->length, lbl_805A1BB8, lbl_805A1BB8);
        VEC3 up(lbl_805A1BB8, lbl_805A1BBC, lbl_805A1BB8);
        VEC3 axis;
        fn_801ED0B0(&up, &direction, &axis);
        MTX34 rotation;
        fn_80162974(&rotation, &axis, lbl_805A1BFC);
        MTX34 translation;
        fn_801EC868(&identity, &translation, direction.x, direction.y, direction.z);
        MTX34 combined;
        fn_801EC1B8(&translation, &rotation, &combined);
        if (node->flag && node->parent) {
            node->matrix = node->parent->parent->matrix;
        } else {
            fn_801EC1B8(&current, &combined, &current);
            node->matrix = current;
        }
    } else if (node->parent) {
        node->matrix = node->parent->parent->matrix;
    }
    if (self->flag) {
        if (self->flip) {
            MTX34 current;
            MTX34 rotation;
            fn_801629AC(&rotation, lbl_805A1BFC, lbl_805A1BB8, lbl_805A1BB8);
            current = node->matrix;
            fn_801EC1B8(&current, &rotation, &current);
            node->matrix = current;
        }
        if (node->parent == 0) {
            MTX34 current;
            MTX34 rotation;
            fn_801629AC(&rotation, lbl_805A1BB8, lbl_805A1BB8, lbl_805A1C00);
            current = node->matrix;
            fn_801EC1B8(&current, &rotation, &current);
            node->matrix = current;
        } else if (node->parent && node->parent->parent->parent == 0) {
            MTX34 current;
            MTX34 rotation;
            fn_801629AC(&rotation, lbl_805A1BB8, lbl_805A1BB8, lbl_805A1C04);
            current = node->matrix;
            fn_801EC1B8(&current, &rotation, &current);
            node->matrix = current;
        }
    }
    int offset;
    int i;
    i = 0;
    offset = 0;
    for (; i < node->childCount; offset += 4, ++i) {
        Link* link = *(Link**)((char*)node->children + offset);
        if (link)
            fn_80084524(self, link->child);
    }
}
