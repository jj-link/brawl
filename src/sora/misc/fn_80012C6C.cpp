#include <types.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on

using namespace nw4r::ut;

class List : public nw4r::ut::detail::LinkListImpl {
public:
    using nw4r::ut::detail::LinkListImpl::Erase;
    using nw4r::ut::detail::LinkListImpl::Insert;
    using nw4r::ut::detail::LinkListImpl::GetEndIter;
};

struct Rect {
    f32 left;
    f32 top;
    f32 right;
    f32 bottom;
};

struct Words {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

struct Node {
    f32 x;
    f32 y;
    f32 x2;
    f32 y2;
    u8 pad[1];
    u8 flags;
    u8 pad2[2];
    Node* parent;
    Node* child[4];
    List list;
};

struct Object {
    char pad[0x2c];
    Rect rect;
};

extern "C" int fn_80041920(float*, float*);
extern "C" unsigned int fn_800130A8(void*, void*);

extern "C" void fn_80012C6C(Node* self, LinkListNode* obj) {
    Node* cur = self;
    Rect key = ((Object*)obj)->rect;
    Rect* keyp = &key;
    Rect temp;
    Rect bounds;

    {
        register f32 t0, p1, p2, t3, p4, p5;
        p4 = self->x2;
        p5 = self->x;
        p1 = self->y2;
        p2 = self->y;
        asm { ps_sub t3, p5, p4 }
        asm { ps_sub t0, p2, p1 }
        asm { ps_sel t3, t3, p4, p5 }
        asm { ps_sel t0, t0, p1, p2 }
        bounds.left = t3;
        bounds.top = t0;
    }
    {
        register f32 t0, p1, p2, t3, p4, p5;
        p4 = self->x2;
        p5 = self->x;
        p1 = self->y2;
        p2 = self->y;
        asm { ps_sub t3, p5, p4 }
        asm { ps_sub t0, p2, p1 }
        asm { ps_sel t3, t3, p5, p4 }
        asm { ps_sel t0, t0, p2, p1 }
        bounds.right = t3;
        bounds.bottom = t0;
    }

    for (;;) {
        if (cur->parent == 0 || fn_80041920(&bounds.left, &keyp->left)) {
            break;
        }

        cur = cur->parent;
        {
            register f32 dy2, dx2, dy1, y2, y, dx1, x2, x;
            x2 = cur->x2;
            x = cur->x;
            y2 = cur->y2;
            y = cur->y;
            asm { ps_sub dx1, x, x2 }
            asm { ps_sub dx2, x, x2 }
            asm { ps_sub dy1, y, y2 }
            asm { ps_sub dy2, y, y2 }
            asm { ps_sel dx1, dx1, x2, x }
            asm { ps_sel dy1, dy1, y2, y }
            asm { ps_sel dx2, dx2, x, x2 }
            asm { ps_sel dy2, dy2, y, y2 }
            temp.left = dx1;
            temp.top = dy1;
            temp.right = dx2;
            temp.bottom = dy2;
        }
        *(Words*)&bounds = *(Words*)&temp;
    }

    for (;;) {
        if ((cur->flags >> 7) & 1) {
            break;
        }

        unsigned int idx = fn_800130A8(cur, &key);
        if (idx == 0xff || !cur->child[idx]) {
            break;
        }
        cur = cur->child[idx];
    }

    if (cur != self) {
        self->list.Erase(obj);
        cur->list.Insert(cur->list.GetEndIter(), obj);
    }
}
