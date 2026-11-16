#include <gf/gf_archive.h>
#include <gf/gf_archive_db.h>
#include <types.h>
#include <ut/ut_list.h>
#pragma force_active on

struct ArchiveNode {
    char pad0[8];
    u16 refCount;
    char padA[2];
    u32 id;
    u32 unk10;
    gfArchive* archive;
    char pad18[4];
};

struct ArchiveCache {
    char pad0[4];
    gfArchiveDatabase* db;
    u32 entryCount;
    ArchiveNode* entries;
    utList freeList;
    char pad1c[0xC];
    utList usedList;

    s32 insert(gfArchive* archive) {
        ArchiveNode* fresh = (ArchiveNode*)freeList.getNode(0);
        if (fresh != nullptr) {
            freeList.remove((utListNode*)fresh);
            fresh->id = 0xFFFF;
            fresh->unk10 = 0xFFFF;
            fresh->archive = nullptr;
            fresh->refCount = 1;
            fresh->id = db->add(archive, false);
            fresh->archive = archive;
            usedList.addTail((utListNode*)fresh);
            return fresh->id;
        }
        return 0xFFFF;
    }

    ArchiveNode* find(gfArchive* archive) {
        if (archive != nullptr) {
            for (u32 i = 0; i < entryCount; i++) {
                ArchiveNode* node = &entries[i];
                if (node->id != 0xFFFF) {
                    gfArchive* arc = db->get(node->id);
                    if (arc != nullptr) {
                        if (arc == archive) {
                            return node;
                        }
                    } else {
                        return nullptr;
                    }
                }
            }
        }
        return nullptr;
    }
};

extern "C" s32 fn_800455E0(ArchiveCache* self, gfArchive* archive) {
    ArchiveNode* node = self->find(archive);
    if (node != nullptr) {
        node->refCount = node->refCount + 1;
        return node->id;
    }
    return self->insert(archive);
}
