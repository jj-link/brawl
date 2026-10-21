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
void fn_117_DBF4(DededeEventEntry*, void*);
void fn_117_DF94(DededeEventMask*, const DededeEventMask*);
bool fn_117_DCD4(void*, const DededeEventMask*, void*);
}

extern "C" void fn_117_DC44(void* object, const DededeEventMask* mask, void* event) {
    unsigned char* base = static_cast<unsigned char*>(object);
    DededeEventEntry* entry = reinterpret_cast<DededeEventEntry*>(base + 0xC);
    if ((mask->value & 2) && static_cast<unsigned int>(entry->enabled != 0) == 1 && entry->state == 0) {
        fn_117_DBF4(entry, event);
    }
    DededeEventMask local;
    fn_117_DF94(&local, mask);
    fn_117_DCD4(base + 4, &local, event);
}
