#pragma force_active on
class soModuleAccesser;

struct CaptainProcessVTable {
    virtual void first();
    virtual void callback(soModuleAccesser*) __attribute__((noreturn));
};

struct CaptainProcessEntry : CaptainProcessVTable {
    unsigned char reserved;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool suspended;

    bool isEnabled() const { return enabled; }
};

extern "C" void fn_100_C2A8(CaptainProcessEntry* entry, soModuleAccesser* accesser) {
    if (entry->isEnabled() == true && !entry->suspended)
        entry->callback(accesser);
}