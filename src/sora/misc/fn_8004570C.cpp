#include <gf/gf_archive.h>
#include <gf/gf_archive_db.h>
#include <sr/sr_common.h>
#include <types.h>
#include <ut/ut_list.h>
#pragma force_active on

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long size, int heap);
extern "C" gfArchive* __ct__9gfArchiveFv(gfArchive* self);

struct ArchiveLoadNode {
    char pad0[8];
    s16 unk8;
    char padA[2];
    s32 unkC;
    s32 unk10;
    gfArchive* unk14;
};

struct ArchiveLoader {
    char pad0[4];
    gfArchiveDatabase* db;
    char pad8[8];
    utList freeList;
    char pad1c[0xC];
    utList usedList;
};

extern "C" s32 fn_8004570C(ArchiveLoader* self, void* data, s32 size, Heaps::HeapType heap) {
    ArchiveLoadNode* node = (ArchiveLoadNode*)self->freeList.getNode(0);
    if (node != nullptr) {
        self->freeList.remove((utListNode*)node);
        gfArchive* p = (gfArchive*)__nw__FUlQ25Heaps8HeapType(sizeof(gfArchive), heap);
        gfArchive* arc = p;
        if (p != nullptr) {
            arc = __ct__9gfArchiveFv(p);
        }
        arc->setFileImage(data, size, heap);
        node->unkC = 0xFFFF;
        node->unk10 = 0xFFFF;
        node->unk14 = nullptr;
        node->unk8 = 1;
        node->unkC = self->db->add(arc, false);
        node->unk14 = arc;
        self->usedList.addTail((utListNode*)node);
        return node->unkC;
    }
    return 0xFFFF;
}
