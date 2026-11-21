#include <gf/gf_archive.h>
#include <gf/gf_memory_pool.h>
#pragma force_active on
struct ArchiveFields : gfArchiveFileHeader { u16 count; };
struct Entry { int type; int unused; ArchiveFields* file; int extra; };
struct Node { u16 id; u16 count; Node* next; };
struct Object { u8 pad0[9]; u8 flags; u8 padA[0x12]; Node* buffer; u8 pad20[0x48]; Node* root; };
extern "C" void fn_80014DA8(Object*, Node*, gfArchiveFileHeader*);
inline Node* initNode(Node* p, u16 id, u16 count) {
    if (p) { p->id = id; p->count = count; p->next = 0; }
    return p;
}
inline Node* initNodeReverse(Node* p, u16 count, u16 id) {
    if (p) { p->id = id; p->count = count; p->next = 0; }
    return p;
}
inline Node* initNodeFromEntry(Node* p, Entry* entry, ArchiveFields* file) {
    return initNodeReverse(p, file->count, *(u16*)((u8*)entry + 2));
}
extern "C" void fn_80014BF4(Object* self, ArchiveFields* file, gfMemoryPool* heap) {
    Entry* entry;
    Node* root = self->buffer;
    Node* space = 0;
    if (root) {
        initNode(root, 0xffff, file->count);
        space = (Node*)(8 + root->count * 16 + (u32)root);
    } else {
        u16 count = file->count;
        root = initNode((Node*)gfMemoryPool::alloc(heap, count * 16 + 8, 0x20), 0xffff, count);
    }
    fn_80014DA8(self, root, file);
                    u16 subCount;
    Node* node;
    Node* last = root;
    file->getDataChunk();
    u16 count = file->count;
    entry = (Entry*)((u8*)root + 8);
    for (u32 i = 0; i < count; entry++, i++) {
        if ((entry->type >> 24) == 7) {
            ArchiveFields* subfile = entry->file;
            if (subfile->count) {
                subfile->getDataChunk();
                if (space) {
                    node = initNodeFromEntry(space, entry, subfile);
                    space = (Node*)(8 + node->count * 16 + (u32)node);
                } else {
                    subCount = subfile->count;
                    node = initNode((Node*)gfMemoryPool::alloc(heap, subCount * 16 + 8, 0x20), (*(u16*)((u8*)entry + 2)), subCount);
                }
                fn_80014DA8(self, node, subfile);
                last->next = node;
                last = node;
            }
        }
    }
    self->root = root;
    self->flags |= 0x10;
}