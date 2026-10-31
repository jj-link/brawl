#pragma force_active on
class soModuleAccesser;

class CaptainProcessEntry {
public:
    virtual ~CaptainProcessEntry();
    virtual void process(soModuleAccesser*);

    unsigned char reserved;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool suspended;

    bool isEnabled() const { return enabled; }
};

extern "C" void fn_100_C1C0(CaptainProcessEntry* entry, soModuleAccesser* accesser) {
    if (entry->isEnabled() == true && !entry->suspended)
        entry->process(accesser);
}
