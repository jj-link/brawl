#include <nw4r/math/math_types.h>
#pragma force_active on

extern "C" float fn_801622A0(float);
extern "C" const float lbl_805A3048;
extern "C" const float lbl_805A304C;
extern "C" const float lbl_805A303C;

using namespace nw4r::math;

struct Info {
    char pad[0x42];
    u16 linkOffset;
};

struct Node {
    char pad0[0xC];
    int kind;
    char pad10[0xAC - 0x10];
    VEC3 pos;
};

struct Link {
    Node* next;
    Node* prev;
};

struct Owner {
    Info* info;
    char pad4[0x98 - 0x4];
    VEC3 defaultDir;
    VEC3 pos;
};

inline float magnitude(float s) {
    if (s <= lbl_805A304C) {
        return lbl_805A304C;
    }
    return s * fn_801622A0(s);
}

inline VEC3& divBy(VEC3& v, f32 x) {
    return v *= (lbl_805A303C / x);
}

inline bool normalize(VEC3* v) {
    float s = VEC3Dot(v, v);
    if (s < lbl_805A3048) {
        return false;
    }
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

extern "C" void fn_8017DFB8(VEC3* out, Owner* owner, Node* node) {
    u16 off = owner->info->linkOffset;
    Node* next = findNext(node, off);
    Node* prev = findPrev(node, off);

    VEC3 a(lbl_805A304C, lbl_805A304C, lbl_805A304C);
    if (next != NULL) {
        VEC3Sub(&a, &next->pos, &node->pos);
        normalize(&a);
    }
    VEC3 b;
    if (prev != NULL) {
        VEC3Sub(&b, &prev->pos, &node->pos);
    } else {
        VEC3Sub(&b, &owner->pos, &node->pos);
    }
    normalize(&b);
    VEC3Sub(out, &a, &b);
    if (!normalize(out)) {
        *out = owner->defaultDir;
    }
}
