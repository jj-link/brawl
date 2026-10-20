#pragma force_active on
struct aiMgrStub {
    char pad[0x138];
    char *table;
};

extern struct aiMgrStub *g_aiMgr;

extern "C" {
char *fn_27_1F218C(int id)
{
    if (id < 0 || id > 0x35) {
        id = 0;
    }
    return g_aiMgr->table + (id << 5);
}
}
