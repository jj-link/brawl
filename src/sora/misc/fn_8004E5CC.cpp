#pragma force_active on

struct MenuData {
    char pad[0x100];
};

struct GameGlobal {
    char pad[0x24];
    MenuData* m_record;
    char pad2[0x28];
};

extern "C" MenuData* getGlobalRecordMenuDatap__10GameGlobalFv(GameGlobal* global) {
    return reinterpret_cast<MenuData*>(reinterpret_cast<char*>(global->m_record) + 0x810);
}
