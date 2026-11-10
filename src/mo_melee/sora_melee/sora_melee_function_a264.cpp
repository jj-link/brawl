#include <types.h>
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

struct Vec3f {
    f32 x, y, z;
};

struct Node {
    u32 id;
    f32 scaleX, scaleY, scaleZ;
    char pad10[0x18];
    u32 flags;
};

struct Class_90D8_base {
    char pad[0x8];
};

class Class_90D8 : public Class_90D8_base {
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
    char list[0x10];
    f32 scale;
};

extern "C" Node* fn_8015C1B0(void*, Node*);
extern "C" Node* fn_8015C1D0(void*, int);
extern "C" void fn_8015C144(void*, Node*);
extern "C" void fn_8015C024(void*, Node*, Node*);

inline Node* findNode(Class_90D8* self, u32 id) {
    Node* node = 0;
    while ((node = fn_8015C1B0(self->list, node)) != 0) {
        if (node->flags != 0) {
            if (id == node->id) {
                return node;
            } else if (id < node->id) {
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

inline void scaleVector(f32 factor, const Vec* in, Vec* out) {
    LocalScale(in, out, factor);
}

extern "C" void setNodeScale__17soModelModuleImplFUlP5Vec3f(
    Class_90D8* self, u32 id, Vec3f* scale
) {
    f32 x, y, z;
    Vec tmp;
    Node* node = findNode(self, id);
    node->id = id;

    if (id == 0) {
        scaleVector(self->scale, (const Vec*)scale, &tmp);
        node->scaleX = tmp.x;
        node->scaleY = tmp.y;
        node->scaleZ = tmp.z;
    } else {
        x = scale->x;
        y = scale->y;
        node->scaleX = x;
        z = scale->z;
        node->scaleY = y;
        node->scaleZ = z;
    }

    node->flags |= 7;
    self->fn_27_7AEDC();
}
