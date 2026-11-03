#pragma force_active on
enum itKind { };

class ItemList {
public:
    virtual void v0();
    virtual void v1();
    virtual int* at(int i);
    virtual int size();
};

class itManager {
public:
    char pad[0x6D8];
    ItemList list;
    int getItemNum(itKind kind, int variation, int taskId, int p4);
};

int itManager::getItemNum(itKind kind, int variation, int taskId, int p4) {
    int count = 0;
    for (int i = 0; i < list.size(); i++) {
        char* item = *(char**)list.at(i);
        if (item != 0) {
            if ((int)kind == *(int*)(item + 0x8c0) || (int)kind == -1) {
                if (variation == 0 || variation == *(int*)(item + 0x8c4)) {
                    if ((unsigned)taskId == 0xffffffff || (unsigned)taskId == *(unsigned*)(item + 0x8c8)) {
                        if ((unsigned)p4 == 0xffffffff || (unsigned)p4 == *(unsigned*)(item + 0x3d28)) {
                            count++;
                        }
                    }
                }
            }
        }
    }
    return count;
}
