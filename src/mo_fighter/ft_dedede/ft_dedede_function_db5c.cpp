#pragma force_active on
namespace {
struct DededeEventMask {
    short value;
};
struct DededeEventEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_117_DB0C(DededeEventEntry*, void*);
void fn_117_DF94(DededeEventMask*, const DededeEventMask*);
void fn_117_DBEC(void*, const DededeEventMask*, void*);
}

extern "C" void fn_117_DB5C(void* object, const DededeEventMask* mask, void* event) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    DededeEventEntry* entry = reinterpret_cast<DededeEventEntry*>(composite + 0xC);
    if ((mask->value & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_117_DB0C(entry, event);

    DededeEventMask local;
    fn_117_DF94(&local, mask);
    fn_117_DBEC(composite + 4, &local, event);
}
