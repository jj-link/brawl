// Declaration-only view of the common prefix of Captain's process entries.
// The containing aggregate owns each one-element process collection.
struct CaptainProcessEntry {
    void* vtable;
    unsigned char reserved;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool suspended;

    bool isEnabled() const { return enabled; }
};

class soModuleAccesser;
extern "C" {
CaptainProcessEntry* fn_100_C598(void*, int);
CaptainProcessEntry* fn_100_C4B0(void*, int);
CaptainProcessEntry* fn_100_C3C8(void*, int);
CaptainProcessEntry* fn_100_C2E0(void*, int);
CaptainProcessEntry* fn_100_C1F8(void*, int);
CaptainProcessEntry* fn_100_C110(void*, int);
CaptainProcessEntry* fn_100_C060(void*, int);
CaptainProcessEntry* fn_100_BF78(void*, int);
void fn_100_C560(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_C478(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_C390(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_C2A8(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_C1C0(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_CD4C(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_C028(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_BF40(CaptainProcessEntry*, soModuleAccesser*);
}

extern "C" void fn_100_BA60(unsigned char* processes, soModuleAccesser* accesser) {
    for (int i = 0; i < 1; ++i) {
        CaptainProcessEntry* entry = fn_100_C598(processes + 0x208, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_100_C560(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        CaptainProcessEntry* entry = fn_100_C4B0(processes + 0x1cc, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_100_C478(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        CaptainProcessEntry* entry = fn_100_C3C8(processes + 0x180, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_100_C390(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        CaptainProcessEntry* entry = fn_100_C2E0(processes + 0x138, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_100_C2A8(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        CaptainProcessEntry* entry = fn_100_C1F8(processes + 0xf0, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_100_C1C0(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        CaptainProcessEntry* entry = fn_100_C110(processes + 0x98, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_100_CD4C(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        CaptainProcessEntry* entry = fn_100_C060(processes + 0x64, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_100_C028(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        CaptainProcessEntry* entry = fn_100_BF78(processes + 8, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_100_BF40(entry, accesser);
    }
}
