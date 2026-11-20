#include <gf/gf_archive.h>
#include <gf/gf_archive_db.h>
#include <types.h>
#include <ut/ut_list.h>
#include <string.h>
#pragma force_active on
struct ArcListNode {
    char pad0[8];
    u16 unk8;
    char pad1[2];
    s32 unkC;
    s32 unk10;
    gfArchive* unk14;
};
struct ArcDb;
extern "C" {
extern char lbl_8042B618[];
extern char lbl_8059C790[5];
void OSReport(const char* fmt, ...);
ArcListNode* fn_80045240(ArcDb* self, utList* list, const char* name);
gfArchive* fn_800137C0(gfArchive* mem, s32 heap, gfArchive* other);
u32 fn_800151FC(gfArchive* arc, const char* name, s32 heap, u32 a, u32 b, u32 c);
u32 fn_80014ED4(gfArchive* arc, const char* name, s32 heap, u32 a);
}
struct ArcDb {
    char pad0[4];
    gfArchiveDatabase* db;
    char pad1[8];
    utList freeList;
    utList list1C;
    utList list28;
    s32 load(const char* name, s32 heap, u32 a4, u32 a5, u32 a6, u8 flag, ArcListNode* existing, u32& mode, u32& loaded) {
        gfArchive* arc;
        ArcListNode* node = (ArcListNode*)freeList.getNode(0);
        if (node != NULL) {
            freeList.remove((utListNode*)node);
            mode = 0xFFFF;
            node->unkC = 0xFFFF;
            node->unk10 = 0xFFFF;
            node->unk14 = NULL;
            node->unk8 = 1;
            loaded = 0;
            if (existing == NULL) {
                arc = new ((Heaps::HeapType)heap) gfArchive();
                if (strstr(name, lbl_8059C790) == 0) {
                    if (flag == 1) {
                        loaded = fn_800151FC(arc, name, heap, a4, a5, a6);
                    } else {
                        loaded = fn_80014ED4(arc, name, heap, a4);
                    }
                }
            } else {
                gfArchive* tmp = (gfArchive*)operator new(0x80, (Heaps::HeapType)heap);
                if (tmp != NULL) {
                    tmp = fn_800137C0(tmp, heap, existing->unk14);
                }
                mode = existing->unkC;
                arc = tmp;
                loaded = 1;
            }
            if (loaded == 1) {
                node->unkC = db->add(arc, true);
                node->unk14 = arc;
                node->unk10 = mode;
                if (flag == 1) {
                    list1C.addTail((utListNode*)node);
                } else {
                    list28.addTail((utListNode*)node);
                }
            } else {
                OSReport(lbl_8042B618, name);
                delete arc;
                return 0xFFFF;
            }
            return node->unkC;
        }
        return 0xFFFF;
    }
};
extern "C" s32 fn_800453AC(ArcDb* self, const char* name, s32 heap, u32 mode, u32 a4, u32 a5, u32 a6, u32 unused, u8 flag) {
    u32 loaded;
    u32 id;
    ArcListNode* existing = NULL;
    ArcListNode* found = NULL;
    if (name != NULL) {
        found = fn_80045240(self, &self->list28, name);
        if (found == NULL) {
            found = fn_80045240(self, &self->list1C, name);
        }
    }
    if (found != NULL) {
        if (mode == 1) {
            existing = found;
        } else {
            found->unk8 = found->unk8 + 1;
            return found->unkC;
        }
    }
    return self->load(name, heap, a4, a5, a6, flag, existing, id, loaded);
}