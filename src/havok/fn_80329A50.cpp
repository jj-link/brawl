#include <types.h>
#pragma force_active on

struct Flag {
    s8 value;
    Flag(bool b) : value(b) {}
    operator s8() const { return value; }
};

struct Node;
struct Info {
    u8 pad[0x1C];
    u8 level;
    Flag isAbove(s32 l) const { return level >= l; }
};
struct Edge {
    Info* info;
    Node* a;
    Node* b;
    u8 pad[0x18];
};
struct Link {
    u8 pad[0x28];
    Edge* edge;
};
struct Node {
    u8 pad0[0x6C];
    Edge* edges;
    s32 edgeCount;
    u8 pad74[4];
    Link** links;
    s32 linkCount;
    u8 pad80[0x10];
    u16 id;
    u8 pad92[0x16];
    u8 kind;
    u8 padA9[7];
    u8 transform[0x40];
    u8 other[0x40];
    Flag isType7() const { return kind == 7; }
};
struct Array {
    void** data;
    s32 count;
    s32 capacity;
};
struct Flags {
    u8* data;
};

extern "C" void fn_8027CE3C(void*, int);
extern "C" void fn_80285DA4(void*, void*, f32);
extern "C" void fn_8032931C(Node*, s32, void*, Flags*, f32);

static __inline void handleEdge(Edge* e, Node* node, s32 threshold, Flags* flags, Array* queue, Array* out, f32 dt)
{
    if (e->info->isAbove(threshold)) {
        Node* next = (Node*)((u32)e->a ^ (u32)e->b ^ (u32)node);
        if (next->isType7()) {
            if (out->count == (out->capacity & 0x3FFFFFFF))
                fn_8027CE3C(out, 4);
            out->data[out->count++] = e->info;
        } else if (flags->data[next->id] != 8) {
            if (out->count == (out->capacity & 0x3FFFFFFF))
                fn_8027CE3C(out, 4);
            out->data[out->count++] = e->info;
            if (flags->data[next->id] < 2) {
                if (queue->count == (queue->capacity & 0x3FFFFFFF))
                    fn_8027CE3C(queue, 4);
                queue->data[queue->count++] = next;
                if (flags->data[next->id] == 0) {
                    u8* q = (u8*)next + 0xB0;
                    flags->data[next->id] = 1;
                    fn_80285DA4(q + 0x40, q, dt);
                }
                flags->data[next->id] = 2;
            }
        }
    }
}

extern "C" void fn_80329A50(void* ctx, s32 threshold, Array* nodes, Flags* flags, Array* queue, Array* out, f32 dt)
{
    s32 i;
    Node* node;

    for (i = 0; i < nodes->count; i++) {
        node = (Node*)nodes->data[i];
        if (flags->data[node->id] == 0) {
            u8* p = (u8*)node + 0xB0;
            flags->data[node->id] = 1;
            fn_80285DA4(p + 0x40, p, dt);
        }
        flags->data[node->id] = 8;
        fn_8032931C(node, threshold, ctx, flags, dt);
        for (s32 j = 0; j < node->edgeCount; j++)
            handleEdge(&node->edges[j], node, threshold, flags, queue, out, dt);
        for (s32 k = 0; k < node->linkCount; k++)
            handleEdge(node->links[k]->edge, node, threshold, flags, queue, out, dt);
    }
}
