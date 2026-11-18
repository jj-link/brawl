#include <types.h>
#include <nw4r/ut/ut_LinkList.h>
#pragma force_active on

struct Bounds { u32 v[4]; };
struct Rect { f32 v[4]; };
struct Class_804207E4_base {
    struct Class_804207E4* next;
    char pad4[0x18];
    u8 flag7 : 1;
    u8 flag6 : 1;
    u8 dirty : 1;
    u8 flagRest : 5;
    char pad1D[0xF];
    Bounds bounds;
    char pad3C[8];
};
class Class_804207E4 : public Class_804207E4_base {
public:
    virtual void fn_80011148();
    virtual void fn_80011170();
    virtual void fn_80011150();
    virtual void fn_80011C2C();
};
struct Tree {
    f32 rect[4];
    char pad10;
    u8 leaf : 1;
    u8 rest : 7;
    char pad12[2];
    Tree* parent;
    Tree* children[4];
    u32 size;
    Class_804207E4* head;
    void* prev;
};
class ListAccess : public nw4r::ut::detail::LinkListImpl {
public:
    using nw4r::ut::detail::LinkListImpl::Erase;
    using nw4r::ut::detail::LinkListImpl::Insert;
};
extern "C" {
int fn_80041920(Rect*, Bounds*);
u32 fn_800130A8(Tree*, Bounds*);
void fn_80012C6C(Tree*, Class_804207E4*);
void fn_800129FC(Tree*);
void fn_80011F0C(char*, Tree*);
}
inline void bounds(Rect* out, f32* e) {
    {
        register f32 p5, p4, t3, p2, p1, t0;
        p4 = e[2]; p5 = e[0]; p1 = e[3]; p2 = e[1];
        asm { ps_sub t3, p5, p4 }
        asm { ps_sub t0, p2, p1 }
        asm { ps_sel t3, t3, p4, p5 }
        asm { ps_sel t0, t0, p1, p2 }
        out->v[0] = t3; out->v[1] = t0;
    }
    {
        register f32 p5, p4, t3, p2, p1, t0;
        p4 = e[2]; p5 = e[0]; p1 = e[3]; p2 = e[1];
        asm { ps_sub t3, p5, p4 }
        asm { ps_sub t0, p2, p1 }
        asm { ps_sel t3, t3, p5, p4 }
        asm { ps_sel t0, t0, p2, p1 }
        out->v[2] = t3; out->v[3] = t0;
    }
}
inline void process(Tree* c) {
    Class_804207E4* end = (Class_804207E4*)&c->head;
    Class_804207E4* m = c->head;
    while (m != end) {
        m->fn_80011C2C();
        if (m->dirty) {
            fn_80012C6C(c, m);
            m->dirty = 0;
        }
        m = m->next;
    }
    for (u32 j = 0; j < 4; j++) {
        if (c->children[0]) fn_800129FC(c->children[0]);
        c = (Tree*)((char*)c + 4);
    }
}
extern "C" void fn_80012660(char* arg) {
    Bounds* bp;
    Class_804207E4* n;
    Tree* t;
    Tree* root;
    char* self = arg;
    if (*(u8*)(self + 0x74) == 0) {
        root = (Tree*)(self + 0x40);
        n = root->head;
        Bounds b;
        bp = &b;
        while (n != (Class_804207E4*)&root->head) {
            n->fn_80011C2C();
            if (n->dirty) {
                t = root;
                Rect tmp;
                Rect r;
                b = n->bounds;
                bounds(&r, root->rect);
            loop_parent:
                if (t->parent != 0 && fn_80041920(&r, bp) == 0) {
                    t = t->parent;
                    bounds(&tmp, t->rect);
                    r = tmp;
                    goto loop_parent;
                }
            loop_child:
                if (!t->leaf) {
                    u32 idx = fn_800130A8(t, &b);
                    if (idx != 0xFF) {
                        Tree* c = t->children[idx];
                        if (c != 0) {
                            t = c;
                            goto loop_child;
                        }
                    }
                }
                if (t != root) {
                    ((ListAccess*)&root->size)->Erase((nw4r::ut::LinkListNode*)n);
                    ((ListAccess*)&t->size)->Insert(nw4r::ut::detail::LinkListImpl::Iterator((nw4r::ut::LinkListNode*)&t->head), (nw4r::ut::LinkListNode*)n);
                }
                n->dirty = 0;
            }
            n = n->next;
        }
        for (u32 i = 0; i < 4; i++) {
            Tree* c = root->children[0];
            if (c != 0) process(c);
            root = (Tree*)((char*)root + 4);
        }
        fn_80011F0C(self, (Tree*)(self + 0x40));
    }
}