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
void fn_117_D854(DededeEventEntry*, void*);
void fn_117_DF94(DededeEventMask*, const DededeEventMask*);
void fn_117_D934(void*, const DededeEventMask*, void*);
}

extern "C" void fn_117_D8A4(void* object, const DededeEventMask* mask, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    DededeEventEntry* entry = reinterpret_cast<DededeEventEntry*>(composite + 0xC);
    if ((mask->value & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_117_D854(entry, argument);

    DededeEventMask operation;
    fn_117_DF94(&operation, mask);
    fn_117_D934(composite + 4, &operation, argument);
}
