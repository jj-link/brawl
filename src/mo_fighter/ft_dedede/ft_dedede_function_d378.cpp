namespace {
typedef unsigned char Byte;
struct DededeEventEntry {
    Byte prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}
extern "C" {
DededeEventEntry* fn_117_DEE4(void*, int);
DededeEventEntry* fn_117_DDFC(void*, int);
DededeEventEntry* fn_117_DD14(void*, int);
DededeEventEntry* fn_117_DC2C(void*, int);
DededeEventEntry* fn_117_DB44(void*, int);
DededeEventEntry* fn_117_DA5C(void*, int);
DededeEventEntry* fn_117_D974(void*, int);
DededeEventEntry* fn_117_D88C(void*, int);
void fn_117_DEAC(DededeEventEntry*, void*);
void fn_117_DDC4(DededeEventEntry*, void*);
void fn_117_DCDC(DededeEventEntry*, void*);
void fn_117_DBF4(DededeEventEntry*, void*);
void fn_117_DB0C(DededeEventEntry*, void*);
void fn_117_DA24(DededeEventEntry*, void*);
void fn_117_D93C(DededeEventEntry*, void*);
void fn_117_D854(DededeEventEntry*, void*);
}

// Dispatch enabled, unsuspended entries from each embedded singleton event array.
extern "C" void fn_117_D378(Byte* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        DededeEventEntry* entry = fn_117_DEE4(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_117_DEAC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        DededeEventEntry* entry = fn_117_DDFC(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_117_DDC4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        DededeEventEntry* entry = fn_117_DD14(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_117_DCDC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        DededeEventEntry* entry = fn_117_DC2C(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_117_DBF4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        DededeEventEntry* entry = fn_117_DB44(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_117_DB0C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        DededeEventEntry* entry = fn_117_DA5C(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_117_DA24(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        DededeEventEntry* entry = fn_117_D974(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_117_D93C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        DededeEventEntry* entry = fn_117_D88C(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_117_D854(entry, event);
    }
}
