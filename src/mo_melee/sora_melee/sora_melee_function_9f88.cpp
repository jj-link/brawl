#include <nw4r/math/math_types.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on

typedef unsigned long u32;
typedef signed char s8;

struct Vec3f {
    float x;
    float y;
    float z;
};

struct Node {
    u32 id;
    Vec3f a;
    Vec3f b;
    Vec3f c;
    u32 flags;
};

struct ModuleBase {
    char pad0[8];
};

class soModelModuleImpl : public ModuleBase {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();

    char padC[0x30];
    char list[12];
    char pad48[4];
    float scale;
    char pad50[0x72];
    s8 unkC2;
};

extern "C" Node* fn_8015C1B0(void*, Node*);
extern "C" Node* fn_8015C1D0(void*, int);
extern "C" void fn_8015C144(void*, Node*);
extern "C" void fn_8015C024(void*, Node*, Node*);

inline Node* findNode(soModelModuleImpl* self, u32 id) {
    Node* node = 0;

    while ((node = fn_8015C1B0(self->list, node)) != 0) {
        if (node->flags != 0) {
            if (id == node->id) {
                return node;
            }
            if (id < node->id) {
                Node* fresh = fn_8015C1D0(self->list, 0);
                fn_8015C144(self->list, fresh);
                fn_8015C024(self->list, node, fresh);
                return fresh;
            }
        } else {
            return node;
        }
    }

    return 0;
}

extern "C" void setNodeSRT__17soModelModuleImplFUlP5Vec3fP5Vec3fP5Vec3f(
    soModelModuleImpl* self, u32 id, Vec3f* p1, Vec3f* p2, Vec3f* p3
) {
    Node* node = findNode(self, id);
    node->id = id;

    Vec3f v;
    union {
        u32 words[3];
        nw4r::math::VEC3 vec;
    } scaled;
    u32* src;

    if (id == 0) {
        LocalScale((const Vec*)p1, (Vec*)&scaled.vec, self->scale);
        src = scaled.words;
    } else {
        src = (u32*)p1;
    }

    *(u32*)&v.x = src[0];
    *(u32*)&v.y = src[1];
    *(u32*)&v.z = src[2];

    if ((s8)self->unkC2 < 1 || node->flags != 0x1FF ||
        node->c.x != p3->x || node->c.y != p3->y || node->c.z != p3->z ||
        node->b.x != p2->x || node->b.y != p2->y || node->b.z != p2->z ||
        node->a.x != v.x || node->a.y != v.y || node->a.z != v.z) {
        node->a.x = v.x;
        node->a.y = v.y;
        float x = p2->x;
        node->a.z = v.z;
        float y = p2->y;
        node->b.x = x;
        float z = p2->z;
        node->b.y = y;
        x = p3->x;
        node->b.z = z;
        y = p3->y;
        node->c.x = x;
        z = p3->z;
        node->c.y = y;
        node->c.z = z;
        node->flags = 0x1FF;
        self->fn_27_7AEDC();
    }
}
