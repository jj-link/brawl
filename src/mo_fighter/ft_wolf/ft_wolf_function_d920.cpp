#pragma force_active on
namespace {
typedef unsigned char Byte;
struct WolfEventEntry {
    Byte prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}
extern "C" {
WolfEventEntry* fn_125_E48C(void*, int);
WolfEventEntry* fn_125_E3A4(void*, int);
WolfEventEntry* fn_125_E2BC(void*, int);
WolfEventEntry* fn_125_E1D4(void*, int);
WolfEventEntry* fn_125_E0EC(void*, int);
WolfEventEntry* fn_125_E004(void*, int);
WolfEventEntry* fn_125_DF1C(void*, int);
WolfEventEntry* fn_125_DE34(void*, int);
void fn_125_E454(WolfEventEntry*, void*);
void fn_125_E36C(WolfEventEntry*, void*);
void fn_125_E284(WolfEventEntry*, void*);
void fn_125_E19C(WolfEventEntry*, void*);
void fn_125_E0B4(WolfEventEntry*, void*);
void fn_125_DFCC(WolfEventEntry*, void*);
void fn_125_DEE4(WolfEventEntry*, void*);
void fn_125_DDFC(WolfEventEntry*, void*);
}

extern "C" void fn_125_D920(Byte* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        WolfEventEntry* entry = fn_125_E48C(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_125_E454(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        WolfEventEntry* entry = fn_125_E3A4(object + 0x1cc, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_125_E36C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        WolfEventEntry* entry = fn_125_E2BC(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_125_E284(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        WolfEventEntry* entry = fn_125_E1D4(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_125_E19C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        WolfEventEntry* entry = fn_125_E0EC(object + 0xf0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_125_E0B4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        WolfEventEntry* entry = fn_125_E004(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_125_DFCC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        WolfEventEntry* entry = fn_125_DF1C(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_125_DEE4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        WolfEventEntry* entry = fn_125_DE34(object + 8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_125_DDFC(entry, event);
    }
}
