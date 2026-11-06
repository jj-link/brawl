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
extern "C" void fn_801EC1B8(const MTX34*, const MTX34*, MTX34*);
extern "C" void fn_8008A750(void* arg0, Node* node, MTX34 input) {
    int j, k;
    Node *child, *grand;
    int oi, oj, ok, i;
    if (node->parent)
        fn_801EC1B8(&input, &node->world, &node->matrix);
    else
        node->matrix = input;
    i = 0;
    oi = 0;
    for (; i < node->childCount; oi += 4, ++i) {
        Link* link = *(Link**)((char*)node->children + oi);
        if (link) {
            child = link->child;
            MTX34 m = node->matrix;
            if (child->parent)
                fn_801EC1B8(&m, &child->world, &child->matrix);
            else
                child->matrix = m;
            j = 0;
            oj = 0;
            for (; j < child->childCount; oj += 4, ++j) {
                Link* link2 = *(Link**)((char*)child->children + oj);
                if (link2) {
                    grand = link2->child;
                    MTX34 m2 = child->matrix;
                    if (grand->parent)
                        fn_801EC1B8(&m2, &grand->world, &grand->matrix);
                    else
                        grand->matrix = m2;
                    k = 0;
                    ok = 0;
                    for (; k < grand->childCount; ok += 4, ++k) {
                        Link* link3 = *(Link**)((char*)grand->children + ok);
                        if (link3) {
                            Node* next = link3->child;
                            fn_8008A750(arg0, next, grand->matrix);
                        }
                    }
                }
            }
        }
    }
}