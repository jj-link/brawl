#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1B0(void*, void*);
extern const f32 lbl_27_rodata_304;

union Vec3f {
    struct {
        f32 x, y, z;
    };
    u32 words[3];

    Vec3f() {}
    Vec3f(f32 value) : x(value), y(value), z(value) {}
};

struct Node {
    u32 id;
    u8 pad0[0xC];
    Vec3f rotate;
    u8 pad1[0xC];
    u32 flags;
};

struct List {
    u32 head;
};

struct soModelModuleImpl {
    u8 pad[0x3C];
    List list;

    Node* findNode(u32 id) {
        Node* node = 0;
        while ((node = (Node*)fn_8015C1B0(&list, node)) != 0) {
            if (node->flags != 0) {
                if (id == node->id) {
                    return node;
                }
            } else {
                return node;
            }
        }
        return 0;
    }

    Vec3f getNodeRotate(u32 id);
};

Vec3f soModelModuleImpl::getNodeRotate(u32 id) {
    Node* node = findNode(id);
    if (node == 0 || !(node->flags & 0x38)) {
        return Vec3f(lbl_27_rodata_304);
    }
    return node->rotate;
}
