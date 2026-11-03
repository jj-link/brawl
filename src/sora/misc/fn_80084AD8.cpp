#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;

struct Node;
struct Link { Node* parent; Node* child; };
struct Node {
    int kind;
    char pad04[0x24];
    VEC3 initial;
    VEC3 position;
    VEC3 anchor;
    VEC3 previous;
    VEC3 oldAnchor;
    char pad64[0x1c];
    float length;
    char pad84[0x2c];
    float weight;
    char padB4[0x28];
    MTX34 matrix;
    char pad10C[0xec];
    Link* parent;
    Link** children;
    int childCount;
};
struct Context {
    char pad00[0x3c];
    unsigned char flag;
    char pad3D[3];
    int mode;
    float pad44;
    float scale;
};

extern "C" {
void fn_801EC158(MTX34*);
void fn_801EC41C(const MTX34*, MTX34*);
void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);
void fn_8009BD44(const MTX34*, MTX34*, MTX34*);
float fn_801ED04C(const VEC3*);
void fn_801ED008(const VEC3*, VEC3*);
void fn_800893F0(Context*, Node*);
int fn_800867E8(Context*, Node*, unsigned char, VEC2*);
int fn_800879FC(Context*, Node*, unsigned int, int);
void fn_80081DC4(Node*);
extern const float lbl_805A1BB8;
extern const float lbl_805A1BBC;
extern const float lbl_805A1C08;
extern const float lbl_805A1C0C;
}

extern "C" int fn_80084AD8(Context* self, Node* node, int unused,
    float* scale, void* arg4, int useInitial, unsigned int mode,
    unsigned char depth, unsigned char a, unsigned char b, unsigned char c) {
    int offset;
    unsigned int nextDepth;
    int result = 0;
    int hit = 0;
    int moved = 0;
    MTX34 identity;
    fn_801EC158(&identity);
    VEC2 contact;
    if (lbl_805A1BB8 != node->weight && node->parent != 0 &&
        (mode == 0 || depth == 0)) {
        MTX34 parent = node->parent->parent->matrix;
        if (node->kind == 0) {
            VEC3 target;
            if (lbl_805A1BB8 != node->parent->parent->weight)
                target = node->parent->parent->position;
            else if (useInitial)
                target = node->initial;
            else
                target = node->anchor;
            VEC3 delta = target - node->anchor;
            node->anchor += delta;
            if (mode != 3)
                fn_800893F0(self, node);
            VEC3 acceleration;
            if (mode == 1 || mode == 3)
                acceleration = VEC3(lbl_805A1BB8, lbl_805A1BB8, lbl_805A1BB8);
            else
                acceleration = VEC3(lbl_805A1BB8, lbl_805A1C08, lbl_805A1BB8);
            node->position += acceleration * node->weight * *scale * self->scale;
            VEC3 direction = node->position - node->anchor;
            if (lbl_805A1BB8 != fn_801ED04C(&direction))
                fn_801ED008(&direction, &direction);
            node->position = node->anchor + direction * node->length;
            if ((!self->flag || !self->mode) &&
                (node->childCount == 0 ||
                 (node->childCount != 0 && node->children[0]->child->kind != 0))) {
                if (direction.x >= lbl_805A1BB8) {
                    node->position.x += lbl_805A1C0C;
                    node->anchor.x -= lbl_805A1BBC;
                    node->oldAnchor.x -= lbl_805A1BBC;
                } else {
                    node->position.x -= lbl_805A1C0C;
                    node->anchor.x += lbl_805A1BBC;
                    node->oldAnchor.x += lbl_805A1BBC;
                }
                hit = fn_800867E8(self, node, a, &contact);
                if (direction.x >= lbl_805A1BB8) {
                    node->position.x -= lbl_805A1C0C;
                    node->anchor.x += lbl_805A1BBC;
                    node->oldAnchor.x += lbl_805A1BBC;
                } else {
                    node->position.x += lbl_805A1C0C;
                    node->anchor.x -= lbl_805A1BBC;
                    node->oldAnchor.x -= lbl_805A1BBC;
                }
            }
            if (mode != 3) {
                moved = fn_800879FC(self, node, mode, 0);
                if (mode != 0 && hit != 0)
                    moved = 1;
            }
            MTX34 inverse;
            fn_801EC41C(&parent, &inverse);
            MTX34 base = identity;
            if (mode != 3) {
                MTX34 combined;
                MTX34 current = node->matrix;
                fn_801EC1B8(&inverse, &current, &combined);
                MTX34 local, rotation, scaling;
                fn_8009BD44(&combined, &rotation, &scaling);
                fn_801EC1B8(&rotation, &base, &local);
                fn_801EC1B8(&parent, &local, &node->matrix);
            }
            fn_80081DC4(node);
        }
    }
    if (hit == 0)
        node->previous = node->position;
    else {
        node->previous.x = contact.x;
        node->previous.y = contact.y;
    }
    node->oldAnchor = node->anchor;
    nextDepth = depth - 1;
    int i = 0;
    offset = 0;
    for (; i < node->childCount; offset += 4, ++i) {
        if (*(int*)((char*)node->children + offset) != 0) {
            if (mode == 1 && depth >= 1)
                result = fn_80084AD8(self, (*(Link**)((char*)node->children + offset))->child, 0, scale,
                    arg4, useInitial, mode, (unsigned char)nextDepth, a, b, c);
            else
                result = fn_80084AD8(self, (*(Link**)((char*)node->children + offset))->child, 0, scale,
                    arg4, useInitial, mode, 0, a, b, c);
        }
    }
    if (result != 0) return result;
    if (hit != 0) return 2;
    if (moved != 0 && (node->childCount == 0 ||
        (node->childCount != 0 && node->children[0]->child->kind != 0)))
        return 1;
    return 0;
}
