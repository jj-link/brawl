#include <types.h>
#include <ut/ut_list.h>
#include <gf/gf_archive_db.h>
#include <revolution/OS/OSError.h>
#pragma force_active on
extern "C" {
extern char lbl_8042B644[];
extern char lbl_8042B600[];
void* fn_80044BFC(void*, int);
void fn_803F0D4C(void*, void* (*)(void*, int));
void __dt__9gfArchiveFv(gfArchive*, int);
void __dt__17gfArchiveDatabaseFv(gfArchiveDatabase*, int);
void __dl__FPv(void*);
}
struct Node : utListNode { u16 value; u16 pad; u32 index; u32 other; gfArchive* archive; };
struct DBView { u16 capacity; u16 size; gfArchiveDatabaseEntry* entries; };
struct Manager { void* vtable; DBView* db; u32 count; void* nodes; utList freeList; utList list1; utList list2; utList list3; utList list4; };
inline void processNode(Manager* self, Node* node) {
    if (self->list3.isExistNode(node) != -1) self->list3.remove(node);
    if (self->list2.isExistNode(node) != -1) self->list2.remove(node);
    if (self->list1.isExistNode(node) != -1) self->list1.remove(node);
    if (self->list4.isExistNode(node) != -1) self->list4.remove(node);
    if (node->archive->m_refCount <= 0) OSReport(lbl_8042B600, (char*)node->archive + 0x28);
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
inline void processFirstNode(Manager* self, utListNode* listNode) {
    Node* node = (Node*)listNode;
    if (self->list3.isExistNode(node) != -1) self->list3.remove(node);
    if (self->list2.isExistNode(node) != -1) self->list2.remove(node);
    if (self->list1.isExistNode(node) != -1) self->list1.remove(node);
    if (self->list4.isExistNode(node) != -1) self->list4.remove(node);
    if (node->archive->m_refCount <= 0) OSReport(lbl_8042B600, (char*)node->archive + 0x28);
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
#define PROCESS(LIST) processNode(self, (Node*)LIST.getNode(0));
extern "C" void* fn_80044C3C(void* p, int flag) {
    Manager* self = (Manager*)p;
    if (self) {
        self->vtable = lbl_8042B644;
        while (*(u32*)((char*)&self->list3 + 8)) { processFirstNode(self, self->list3.getNode(0)); }
        while (*(u32*)((char*)&self->list1 + 8)) { PROCESS(self->list2) }
        while (*(u32*)((char*)&self->list2 + 8)) { PROCESS(self->list2) }
        while (*(u32*)((char*)&self->list4 + 8)) { PROCESS(self->list4) }
        fn_803F0D4C(self->nodes, fn_80044BFC);
        self->nodes = 0;
        __dt__17gfArchiveDatabaseFv((gfArchiveDatabase*)self->db, 1);
        self->db = 0;
        if (flag > 0) __dl__FPv(self);
    }
    return p;
}