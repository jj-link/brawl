#pragma force_active on
typedef unsigned long u32;
typedef unsigned short u16;

enum ARCNodeType { Data_Type_Misc = 0 };

struct utArchiveManager {
    char pad0[4];
    void* db;
};

extern "C" void* get__17gfArchiveDatabaseCFl(void* db, long id);
extern "C" void* fn_80015E34(void* arc, u32 a, ARCNodeType type, u32 b, u32* out, u16 archiveId);

extern "C" void* getResFileFromId__16utArchiveManagerFl11ARCNodeTypeUlUlUl(const utArchiveManager* self, long id, ARCNodeType type, u32 index, u32 group, u32 archiveId) {
    u32 sp8 = 0;
    void* arc = get__17gfArchiveDatabaseCFl(self->db, id);
    if (arc != 0) {
        if ((long)archiveId == -1) {
            return fn_80015E34(arc, group, type, index, &sp8, 0xFFFE);
        }
        return fn_80015E34(arc, group, type, index, &sp8, (u16)archiveId);
    }
    return 0;
}
