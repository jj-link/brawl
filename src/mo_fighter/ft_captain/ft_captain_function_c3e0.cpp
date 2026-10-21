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
void fn_100_C390(CaptainProcessEntry*, soModuleAccesser*);
void fn_100_C648(short*, const short*);
void fn_100_C470(void*, const short*, soModuleAccesser*);

void fn_100_C3E0(unsigned char* object, const short* flags,
                 soModuleAccesser* accesser) {
    CaptainProcessEntry* entry =
        reinterpret_cast<CaptainProcessEntry*>(object + 12);

    if ((*flags & 4) && entry->isEnabled() == true && !entry->suspended)
        fn_100_C390(entry, accesser);

    short tmp;
    fn_100_C648(&tmp, flags);
    fn_100_C470(object + 4, &tmp, accesser);
}
}
