#pragma force_active on
struct Entry {
    int state; char pad[4]; Entry* next; char pad2[8];
    struct Player { unsigned char active; char pad[0x17]; } players[4];
};
struct Manager { char pad[0x454]; Entry* entries; };
struct Object {
    char pad[0x11]; unsigned char flag; char pad2[0x9e];
    struct Player { signed char active; char pad[0x1f]; } players[4];
};
extern Manager* lbl_805A0390;
extern "C" void fn_80140C84(Object*);
inline bool checkPlayers(Object* obj, Entry::Player* players) {
    for (int i = 0; i < 4; i++) {
        if (obj->players[i].active && !players[(unsigned char)i].active) return false;
    }
    return true;
}
extern "C" void fn_801416CC(Object* obj) {
    Entry::Player* playerData;
    Entry* second;
    Entry* first;
    fn_80140C84(obj);
    if (obj->flag == 1) {
        first = lbl_805A0390->entries;
        while (first) {
            if ((unsigned int)(first->state - 2) <= 1) first->state = 4;
            first = first->next;
        }
    } else {
        second = lbl_805A0390->entries;
        while (second) {
            if (second->state == 3) {
                playerData = second->players;
                if (checkPlayers(obj, playerData)) second->state = 4;
            }
            second = second->next;
        }
    }
}