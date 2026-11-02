#pragma force_active on
struct ZeldaProcessEntry {
    void* vtable;
    unsigned char reserved;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool suspended;

    bool isEnabled() const { return enabled; }
};

class soModuleAccesser;
extern "C" {
ZeldaProcessEntry* fn_104_DB98(void*, int);
ZeldaProcessEntry* fn_104_DAB0(void*, int);
ZeldaProcessEntry* fn_104_D9C8(void*, int);
ZeldaProcessEntry* fn_104_D8E0(void*, int);
ZeldaProcessEntry* fn_104_D7F8(void*, int);
ZeldaProcessEntry* fn_104_D710(void*, int);
ZeldaProcessEntry* fn_104_D628(void*, int);
ZeldaProcessEntry* fn_104_D540(void*, int);
void fn_104_DB60(ZeldaProcessEntry*, soModuleAccesser*);
void fn_104_DA78(ZeldaProcessEntry*, soModuleAccesser*);
void fn_104_D990(ZeldaProcessEntry*, soModuleAccesser*);
void fn_104_D8A8(ZeldaProcessEntry*, soModuleAccesser*);
void fn_104_D7C0(ZeldaProcessEntry*, soModuleAccesser*);
void fn_104_D6D8(ZeldaProcessEntry*, soModuleAccesser*);
void fn_104_D5F0(ZeldaProcessEntry*, soModuleAccesser*);
void fn_104_D508(ZeldaProcessEntry*, soModuleAccesser*);
}

extern "C" void fn_104_1D2CC(unsigned char* processes, soModuleAccesser* accesser) {
    for (int i = 0; i < 1; ++i) {
        ZeldaProcessEntry* entry = fn_104_DB98(processes + 0x208, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_104_DB60(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        ZeldaProcessEntry* entry = fn_104_DAB0(processes + 0x1cc, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_104_DA78(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        ZeldaProcessEntry* entry = fn_104_D9C8(processes + 0x180, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_104_D990(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        ZeldaProcessEntry* entry = fn_104_D8E0(processes + 0x138, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_104_D8A8(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        ZeldaProcessEntry* entry = fn_104_D7F8(processes + 0xf0, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_104_D7C0(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        ZeldaProcessEntry* entry = fn_104_D710(processes + 0x98, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_104_D6D8(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        ZeldaProcessEntry* entry = fn_104_D628(processes + 0x64, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_104_D5F0(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        ZeldaProcessEntry* entry = fn_104_D540(processes + 8, i);
        if (entry->isEnabled() == true && !entry->suspended)
            fn_104_D508(entry, accesser);
    }
}
