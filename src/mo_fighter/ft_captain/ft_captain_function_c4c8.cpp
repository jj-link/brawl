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
void fn_100_C478(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_C648(short*, const short*);
int fn_100_C558(void*, short*, soModuleAccesser*);
}

extern "C" void fn_100_C4C8(unsigned char* self, const short* flags,
                             soModuleAccesser* accesser) {
    CaptainProcessEntry* entry =
        reinterpret_cast<CaptainProcessEntry*>(self + 0xc);

    if ((*flags & 8) && entry->isEnabled() == true && !entry->suspended)
        fn_100_C478(entry, accesser);

    short local[4];
    fn_100_C648(local, flags);
    fn_100_C558(self + 4, local, accesser);
}
