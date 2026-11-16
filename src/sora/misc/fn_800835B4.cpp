#include <types.h>
#include <nw4r/math/math_types.h>
#include <mt/mt_common.h>
#pragma force_active on

using namespace nw4r::math;

struct Node;
struct Link { Node* parent; Node* child; };
struct Node {
    char pad0[0x34];
    VEC3 position;
    VEC3 previous;
    char pad4c[0x34];
    float length;
    char pad84[0x2c];
    float weight;
    char padb4[0x114];
    VEC3 velocity;
    float damping;
    VEC3 acceleration;
    float factor;
    char pad1e8[0x10];
    Link* parent;
};

extern "C" float fn_801ED04C(const VEC3*);
extern "C" void fn_801ED008(const VEC3*, VEC3*);
extern const float lbl_805A1BB8;
extern const float lbl_805A1BBC;
extern const float lbl_805A1BD0;
extern const float lbl_805A1BD4;
extern const float lbl_805A1BD8;
extern const float lbl_805A1BDC;
extern const float lbl_805A1BE0;
extern const float lbl_805A1BE4;
extern const float lbl_805A1BE8;

extern "C" void fn_800835B4(void* self, Node* node, int arg2, int arg3)
{
    if (lbl_805A1BB8 != node->weight && node->parent != 0) {
        VEC3 previous = node->previous;
        VEC3 position = node->position;
        if (arg2 == 0) {
            if (arg3 != 0) {
                position += node->velocity;
                position += node->acceleration * node->factor;
                node->velocity += node->acceleration * lbl_805A1BD0;
                node->velocity *= node->damping;
            }
        } else {
            float scale = lbl_805A1BD4;
            float accelerationScale = lbl_805A1BD8;
            if (lbl_805A1BB8 != node->length) {
                if (node->length >= lbl_805A1BDC) {
                    scale *= mtSqrtf(lbl_805A1BBC + (node->length - lbl_805A1BDC) / lbl_805A1BE0);
                    if (scale > lbl_805A1BE4)
                        scale = lbl_805A1BE4;
                } else {
                    scale *= mtSqrtf(lbl_805A1BBC - (lbl_805A1BDC - node->length) / lbl_805A1BE8);
                }
            }
            position += node->velocity;
            position += node->acceleration * scale;
            node->velocity += node->acceleration * accelerationScale;
            node->velocity *= node->damping;
        }
        VEC3 direction = position - previous;
        if (lbl_805A1BB8 != fn_801ED04C(&direction))
            fn_801ED008(&direction, &direction);
        previous = position - direction * node->length;
        node->position.x = position.x;
        node->previous = previous;
        node->position.y = position.y;
        node->position.z = position.z;
    }
    if (node->parent != 0)
        fn_800835B4(self, node->parent->parent, arg2, arg3);
}
