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
void fn_100_C560(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_C648(short*, const short*);
void fn_100_C640(unsigned char*, short*, soModuleAccesser*);
}

extern "C" void fn_100_C5B0(unsigned char* self, const short* src, soModuleAccesser* accesser) {
    short local[4];
    CaptainProcessEntry* entry = reinterpret_cast<CaptainProcessEntry*>(self + 0xc);
    if (*src & 4) {
        if (entry->isEnabled() == true && !entry->suspended) {
            fn_100_C560(entry, accesser);
        }
    }
    fn_100_C648(local, src);
    fn_100_C640(self + 4, local, accesser);
}
