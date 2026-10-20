#pragma force_active on
class soModuleAccesser;

struct CaptainProcessEntry {
    void* vtable;
    unsigned char reserved;
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool suspended;

    bool isEnabled() const { return enabled; }
};

extern "C" {
void fn_100_BF40(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_C648(short*, const short*);
void fn_100_C020(unsigned char*, short*, soModuleAccesser*);
}

extern "C" void fn_100_BF90(unsigned char* object, const short* flags, soModuleAccesser* accesser) {
    CaptainProcessEntry* entry = reinterpret_cast<CaptainProcessEntry*>(object + 0xC);
    if (flags[0] & 1) {
        if (entry->isEnabled() == true && !entry->suspended) {
            fn_100_BF40(entry, accesser);
        }
    }
    short tmp;
    fn_100_C648(&tmp, flags);
    fn_100_C020(object + 4, &tmp, accesser);
}
