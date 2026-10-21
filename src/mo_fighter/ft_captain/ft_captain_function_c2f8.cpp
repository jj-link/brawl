#pragma force_active on
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
void fn_100_C2A8(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_C648(short*, const short*);
int fn_100_C388(void*, short*, soModuleAccesser*);
}

extern "C" void fn_100_C2F8(unsigned char* object, short* source,
                          soModuleAccesser* accesser) {
    CaptainProcessEntry* entry =
        reinterpret_cast<CaptainProcessEntry*>(object + 0xc);

    if ((source[0] & 2) != 0) {
        if (entry->isEnabled() == true && !entry->suspended)
            fn_100_C2A8(entry, accesser);
    }

    short local[4];
    fn_100_C648(local, source);
    fn_100_C388(object + 4, local, accesser);
}
