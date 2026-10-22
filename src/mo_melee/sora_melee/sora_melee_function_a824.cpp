#include <types.h>
#pragma force_active on

union Vec3f {
    struct { float x, y, z; };
    u32 words[3];
    Vec3f() {}
    Vec3f(float a) : x(a), y(a), z(a) {}
};
struct Node {
    u32 id;
    u8 pad[0x18];
    Vec3f translate;
    u32 flags;
};
extern "C" void* fn_8015C1B0(void*, void*);
extern const f32 lbl_27_rodata_304;

struct List { u32 head; };

struct soModelModuleImpl {
    u8 pad[0x3C];
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
    Vec3f getNodeTranslate(u32 id);
};

Vec3f soModelModuleImpl::getNodeTranslate(u32 id) {
    Node* node = findNode(id);
    if (node == 0 || !(node->flags & 0x1C0)) {
        return Vec3f(lbl_27_rodata_304);
    }
    return node->translate;
}
