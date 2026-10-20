#pragma force_active on
namespace {
struct DededeEventMask {
    short value;
};
struct DededeEventEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    unsigned char state;
};
}

extern "C" {
void fn_117_DCDC(DededeEventEntry*, void*);
void fn_117_DF94(DededeEventMask*, const DededeEventMask*);
void fn_117_DDBC(void*, DededeEventMask*, void*);
}

extern "C" void fn_117_DD2C(void* object, const DededeEventMask* mask, void* event) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    DededeEventEntry* entry = reinterpret_cast<DededeEventEntry*>(composite + 0xC);
    if ((mask->value & 4) && static_cast<unsigned int>(entry->enabled != 0) == 1 && entry->state == 0) {
        fn_117_DCDC(entry, event);
    }

    DededeEventMask local;
    fn_117_DF94(&local, mask);
    fn_117_DDBC(composite + 4, &local, event);
}
