#include <types.h>
#pragma force_active on

extern "C" void* fn_8015C1B0(void*, void*);
extern const float lbl_27_rodata_300;

union Vec3f {
    struct { float x, y, z; };
    u32 words[3];

    Vec3f() {}
    Vec3f(float a) : x(a), y(a), z(a) {}
};

struct Node {
    u32 id;
    Vec3f scale;
    u8 pad[0x18];
    u32 flags;
};

struct List {
    u32 head;
};

struct soModelModuleImpl {
    u8 pad[0x3c];
    List list;

    Node* findNode(u32 id) {
        Node* node = 0;
        while ((node = (Node*)fn_8015C1B0(&list, node)) != 0) {
            if (node->flags != 0) {
                if (id == node->id) return node;
            } else {
                return node;
            }
        }
        return 0;
    }

    Vec3f getNodeScale(u32 id);
};

Vec3f soModelModuleImpl::getNodeScale(u32 id) {
    Node* node = findNode(id);
    if (node == 0 || !(node->flags & 7)) {
        return Vec3f(lbl_27_rodata_300);
    }
    return node->scale;
}
