#include <types.h>
#include <ut/ut_list.h>
#include <gf/gf_archive_db.h>
#include <revolution/OS/OSError.h>

#pragma force_active on

extern "C" {
extern char lbl_8042B600[];
void __dt__9gfArchiveFv(gfArchive*, int);
}

struct Node : utListNode {
    u16 value;
    u16 pad;
    u32 index;
    u32 other;
    gfArchive* archive;
    u32 pad18;
};

struct DBView {
    u16 capacity;
    u16 size;
    gfArchiveDatabaseEntry* entries;
};

struct Manager {
    void* vtable;
    DBView* db;
    u32 count;
    Node* nodes;
    utList freeList;
    utList list1;
    utList list2;
    utList list3;
    utList list4;
};

inline Node* findNode(Manager* self, u32 id) {
    if (id != 0xffff) {
        u32 offset;
        u32 i = 0;
        offset = 0;
        u32 count = self->count;
        while (i < count) {
            Node* base = self->nodes;
            Node* cur = (Node*)((u8*)base + offset);
            if (id == cur->index)
                return (Node*)((u8*)base + i * 0x1c);
            offset += 0x1c;
            ++i;
        }
    }
    return 0;
}

inline void processNode(Manager* self, Node* node) {
    if (self->list3.isExistNode(node) != -1) self->list3.remove(node);
    if (self->list2.isExistNode(node) != -1) self->list2.remove(node);
    if (self->list1.isExistNode(node) != -1) self->list1.remove(node);
    if (self->list4.isExistNode(node) != -1) self->list4.remove(node);
    if (node->archive->m_refCount <= 0)
        OSReport(lbl_8042B600, (char*)node->archive + 0x28);
    DBView* db = self->db;
    s32 index = node->index;
    gfArchiveDatabaseEntry* entry = &db->entries[index];
    if (--entry->m_archive->m_refCount == 0) {
        if (entry->m_isOwner) __dt__9gfArchiveFv(entry->m_archive, 1);
        entry->m_archive = 0;
        entry->m_isActive = false;
    }
    if (!db->entries[index].m_isActive) --db->size;
    node->index = 0xffff;
    node->other = 0xffff;
    node->value = 0;
    node->archive = 0;
    self->freeList.addTail(node);
}

extern "C" void fn_80045E64(Manager* self, u32 id) {
    Node* node = findNode(self, id);
    if (node) {
        if (node->value) {
            if (--node->value == 0) {
                if (self->list1.isExistNode(node) != -1 && !node->archive->unk9) {
                    self->list1.remove(node);
                    self->list3.addTail(node);
                    return;
                }
                processNode(self, node);
            }
        } else {
            processNode(self, node);
        }
    }
}
