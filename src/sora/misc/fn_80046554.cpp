#pragma force_active on

extern "C" void* get__17gfArchiveDatabaseCFl(void*, int);
extern "C" void* fn_80015E34(void*, int, int, int, int*, unsigned short);

struct DbHolder {
    void* _0;
    void* db;
};

extern "C" void* fn_80046554(DbHolder* arg0, int archiveId, int nodeType,
                             int fileIndex, int* nodeSize, int groupId,
                             int lastArg) {
    void* arc = get__17gfArchiveDatabaseCFl(arg0->db, archiveId);
    if (arc != 0) {
        if (lastArg == -1) {
            return fn_80015E34(arc, groupId, nodeType, fileIndex, nodeSize,
                              0xFFFEU);
        }
        return fn_80015E34(arc, groupId, nodeType, fileIndex, nodeSize,
                          (unsigned short)lastArg);
    }
    return 0;
}
