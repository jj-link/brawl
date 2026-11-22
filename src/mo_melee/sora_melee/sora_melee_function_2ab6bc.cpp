#include <types.h>
#include <it/it_manager.h>
#include <so/so_array.h>
#pragma force_active on

extern "C" {
bool fn_27_2B2A9C(void*);
void* fn_27_2B2C80(void*, u32, s32);
u32 fn_27_2B2D44(void*, u32);
extern s32 lbl_27_data_71BF0[];
extern s32 lbl_27_data_737A0[];
}

struct KeyPair {
    s32 m_0;
    u32 m_4;
};

struct ArchiveEntry {
    u32 m_0;
    KeyPair m_key;
    u32 m_id;
    u8 m_10;
    u8 m_loaded;

    KeyPair getInfo() const {
        return m_key;
    }
};

struct ArchiveList {
    virtual void v0();
    virtual void v1();
    virtual ArchiveEntry*& at(s32);
    virtual s32 size();
};
struct ManagerLayout {
    char pad[0x1170];
    ArchiveList list;
};

struct ItemListEntry {
    u32 m_0;
    u32 m_4;
    u32 m_8;
    char* m_items;
    u32 m_count;
};

inline bool variationMatches(KeyPair& key, ArchiveEntry* entry) {
    KeyPair t2 = entry->m_key;
    return key.m_4 == t2.m_4;
}
inline ArchiveEntry* findArchive(itManager* arg0, KeyPair& key) {
    ManagerLayout* mgr = (ManagerLayout*)arg0;
    ArchiveEntry* entry;
    s32 i = 0;
    goto list_test;

list_body:
    entry = mgr->list.at(i);
    s32 f1;
    s32 f2;
    f2 = 0;
    f1 = 0;
    if (entry != NULL) {
        if (key.m_0 == entry->getInfo().m_0) {
            f1 = 1;
        }
    }
    if (f1 != 0) {
        if (variationMatches(key, entry)) {
            f2 = 1;
        }
    }
    switch (f2) {
    case 0:
        goto list_increment;
    default:
        goto found_entry;
    }

list_increment:
    ++i;

list_test:
    if (i < mgr->list.size()) {
        goto list_body;
    }
    entry = NULL;

found_entry:
    return entry;
}

extern "C" s32 fn_27_2AB6BC(itManager* arg0, KeyPair* arg1, itArchive::Type arg2) {
    KeyPair key = *arg1;
    ArchiveEntry* entry = findArchive(arg0, key);
    if (entry == NULL) {
        return 0;
    }
    if (!fn_27_2B2A9C(entry)) {
        return 0;
    }
    if (entry->m_loaded != 0) {
        return 1;
    }

    s32 off;
    u32 setIdx = 0;
    do {
        u32 numItemsIdx = fn_27_2B2D44(entry, setIdx);
        for (u32 j = 0; j < numItemsIdx; j++) {
            ItemListEntry* e = (ItemListEntry*)fn_27_2B2C80(entry, j, setIdx);
            if (e != NULL && (e->m_0 != 0x2710U || *((u8*)arg0 + 0x14A0) != 0)) {
                u32 k = 0;
                off = 0;
                for (; k < e->m_count; off += 0x10, k++) {
                    s32 kind = *(s32*)(e->m_items + off);
                    if (kind == -1) {
                        break;
                    }
                    switch (kind) {
                    case 0x7D1:
                        kind = 0x40;
                        break;
                    case 0x7D2:
                    case 0x7D3:
                        if (*((u8*)arg0 + 0x14A0) != 0) {
                            arg0->preloadItemKindArchive((itKind)0x3E, 0x1388U, (itArchive::Type)0, true);
                        } else {
                            for (u32 n = 0; n < 4; n++) {
                                arg0->preloadItemKindArchive((itKind)lbl_27_data_737A0[n], 0x1388U, arg2, true);
                            }
                        }
                        continue;
                    case 0x7D4:
                    case 0x7D5:
                        continue;
                    }
                    s32 v;
                    if (kind == -3) {
                        v = 1;
                    } else if (kind < 0 || kind >= 0xB2) {
                        v = -1;
                    } else {
                        v = lbl_27_data_71BF0[kind];
                    }
                    if (v != 2) {
                        s32 w;
                        if (kind == -3) {
                            w = 1;
                        } else if (kind < 0 || kind >= 0xB2) {
                            w = -1;
                        } else {
                            w = lbl_27_data_71BF0[kind];
                        }
                        if (w != 3) {
                            if (kind == 0x46) {
                                s32 var = *(s32*)(e->m_items + off + 4);
                                if (var != 0x1388) {
                                    arg0->preloadItemKindArchive((itKind)kind, (u32)var, arg2, true);
                                }
                            } else {
                                arg0->preloadItemKindArchive((itKind)kind, 0x1388U, arg2, true);
                            }
                        }
                    }
                }
            }
        }
        setIdx++;
    } while (setIdx < 5);

    entry->m_loaded = 1;
    return 1;
}
