#pragma force_active on
namespace {
typedef unsigned char Byte;
struct FalcoEventEntry {
    Byte prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}
extern "C" {
FalcoEventEntry* fn_108_E3E0(void*, int);
FalcoEventEntry* fn_108_E2F8(void*, int);
FalcoEventEntry* fn_108_E210(void*, int);
FalcoEventEntry* fn_108_E128(void*, int);
FalcoEventEntry* fn_108_E040(void*, int);
FalcoEventEntry* fn_108_DF58(void*, int);
FalcoEventEntry* fn_108_DE70(void*, int);
FalcoEventEntry* fn_108_DD88(void*, int);
void fn_108_E3A8(FalcoEventEntry*, void*);
void fn_108_E2C0(FalcoEventEntry*, void*);
void fn_108_E1D8(FalcoEventEntry*, void*);
void fn_108_E0F0(FalcoEventEntry*, void*);
void fn_108_E008(FalcoEventEntry*, void*);
void fn_108_DF20(FalcoEventEntry*, void*);
void fn_108_DE38(FalcoEventEntry*, void*);
void fn_108_DD50(FalcoEventEntry*, void*);
}

extern "C" void fn_108_D874(Byte* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        FalcoEventEntry* entry = fn_108_E3E0(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_108_E3A8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        FalcoEventEntry* entry = fn_108_E2F8(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_108_E2C0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        FalcoEventEntry* entry = fn_108_E210(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_108_E1D8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        FalcoEventEntry* entry = fn_108_E128(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_108_E0F0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        FalcoEventEntry* entry = fn_108_E040(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_108_E008(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        FalcoEventEntry* entry = fn_108_DF58(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_108_DF20(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        FalcoEventEntry* entry = fn_108_DE70(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_108_DE38(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        FalcoEventEntry* entry = fn_108_DD88(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_108_DD50(entry, event);
    }
}
