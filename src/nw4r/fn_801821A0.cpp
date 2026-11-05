#include <nw4r/math/math_types.h>
#pragma force_active on
extern "C" float fn_801622A0(float);
extern "C" const float lbl_805A3070;
extern "C" const float lbl_805A3074;
extern "C" const float lbl_805A3078;
using namespace nw4r::math;
struct Node;
struct Info {
    char pad[0x38];
    Node* last;
    Node* first;
    char pad40[2];
    u16 linkOffset;
};
struct Node {
    char pad0[0xC];
    int kind;
    char pad10[0xAC - 0x10];
    VEC3 pos;
};
struct Link { Node* next; Node* prev; };
struct Owner {
    Info* info;
    char pad4[0x98 - 4];
    VEC3 defaultDir;
};
inline float magnitude(float s) {
    if (s <= lbl_805A3074) return lbl_805A3074;
    return s * fn_801622A0(s);
}
inline VEC3& divBy(VEC3& v, f32 x) {
    return v *= (lbl_805A3078 / x);
}
inline bool normalize(VEC3* v) {
    float s = VEC3Dot(v, v);
    if (s < lbl_805A3070) return false;
    divBy(*v, magnitude(s));
    return true;
}
inline Node* findNext(Node* n, u16 off) {
    Node* p = ((Link*)((u32)n + off))->next;
    while (p != NULL && p->kind != 1) {
        p = ((Link*)((u32)p + off))->next;
    }
    return p;
}
inline Node* findPrev(Node* n, u16 off) {
    Node* p = ((Link*)((char*)n + off))->prev;
    while (p != NULL && p->kind != 1) {
        p = ((Link*)((char*)p + off))->prev;
    }
    return p;
}
extern "C" void fn_801821A0(VEC3* out, Owner* owner, Node* node) {
    Info* info = owner->info;
    u16 off = info->linkOffset;
    Node* next = findNext(node, off);
    if (next == NULL) {
        next = info->first;
        while (next != NULL && next->kind != 1)
            next = findNext(next, *(u16*)((char*)info + 0x42));
    }
    Node* prev = findPrev(node, off);
    if (prev == NULL) {
        prev = info->last;
        while (prev != NULL && prev->kind != 1)
            prev = ((Link*)((char*)prev + *(u16*)((char*)info + 0x42)))->prev;
    }
    VEC3 a;
    VEC3Sub(&a, &next->pos, &node->pos);
    if (!normalize(&a)) {
        a = VEC3(lbl_805A3074, lbl_805A3074, lbl_805A3074);
    }
    VEC3 b;
    VEC3Sub(&b, &prev->pos, &node->pos);
    if (!normalize(&b)) {
        b = VEC3(lbl_805A3074, lbl_805A3074, lbl_805A3074);
    }
    VEC3Sub(out, &a, &b);
    if (!normalize(out)) {
        *out = owner->defaultDir;
    }
}