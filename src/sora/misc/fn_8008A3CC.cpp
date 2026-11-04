#include <nw4r/math/math_types.h>
#pragma force_active on
using namespace nw4r::math;

struct Node;
struct Link { Node* parent; Node* child; };
struct Node {
    char pad00[0xDC];
    MTX34 matrix;
    MTX34 world;
    char pad13C[0xBC];
    Link* parent;
    Link** children;
    int childCount;
};

extern "C" {
void fn_801EC41C(const MTX34*, MTX34*);
void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);
}

extern "C" void fn_8008A3CC(void* arg0, Node* node) {
    int j;
    Node* child;
    Node* grand;
    int offI;
    int offJ;
    int i;
    int k;
    int offK;
    if (node->parent != 0) {
        MTX34 parent = node->parent->parent->matrix;
        MTX34 inverse;
        fn_801EC41C(&parent, &inverse);
        MTX34 combined;
        fn_801EC1B8(&inverse, &node->matrix, &combined);
        node->world = combined;
    }
    i = 0;
    offI = 0;
    for (; i < node->childCount; offI += 4, ++i) {
        child = (*(Link**)((char*)node->children + offI))->child;
        if (child->parent != 0) {
            MTX34 combined;
            MTX34 inverse;
            MTX34 parent = child->parent->parent->matrix;
            fn_801EC41C(&parent, &inverse);
            fn_801EC1B8(&inverse, &child->matrix, &combined);
            child->world = combined;
        }
        j = 0;
        offJ = 0;
        for (; j < child->childCount; offJ += 4, ++j) {
            grand = (*(Link**)((char*)child->children + offJ))->child;
            if (grand->parent != 0) {
                MTX34 combined;
                MTX34 inverse;
                MTX34 parent = grand->parent->parent->matrix;
                fn_801EC41C(&parent, &inverse);
                fn_801EC1B8(&inverse, &grand->matrix, &combined);
                grand->world = combined;
            }
            k = 0;
            offK = 0;
            for (; k < grand->childCount; offK += 4, ++k) {
                fn_8008A3CC(arg0, (*(Link**)((char*)grand->children + offK))->child);
            }
        }
    }
}
