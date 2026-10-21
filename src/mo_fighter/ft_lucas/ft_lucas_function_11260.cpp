#pragma force_active on
class LucasLinkModule {
    virtual void slot_08() = 0;
    virtual void slot_0C() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1C() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;

public:
    virtual void unlink(int) = 0;
    virtual int isLink(int) = 0;
};

class LucasArticleManager {
    virtual void slot_08() = 0;
    virtual void slot_0C() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1C() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2C() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3C() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;

public:
    virtual void remove(int, int) = 0;
};

struct LucasModules {
    unsigned char pad[0x54];
    LucasLinkModule* link;
    unsigned char pad2[0x2C];
    LucasArticleManager* articles;
};

struct LucasAccessor {
    unsigned char pad[0xD8];
    LucasModules* modules;
};

extern "C" {
extern unsigned char g_ftCommonDataAccesser;
void* getData__20ftCommonDataAccesserCF6ftKind(const void*, int);

void fn_114_11260(void*, LucasAccessor* accesser, int eventKind) {
    LucasLinkModule* link = accesser->modules->link;
    if (link->isLink(6)) {
        link->unlink(6);
    }

    accesser->modules->articles->remove(2, 0);

    if (eventKind == 16) {
        getData__20ftCommonDataAccesserCF6ftKind(&g_ftCommonDataAccesser, 26);
    }
}
}
