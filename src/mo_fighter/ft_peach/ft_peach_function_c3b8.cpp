#pragma force_active on
namespace {
typedef unsigned char Byte;
struct PeachEventEntry {
    Byte prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}
extern "C" {
PeachEventEntry* fn_103_CE7C(void*, int);
PeachEventEntry* fn_103_CD94(void*, int);
PeachEventEntry* fn_103_CCAC(void*, int);
PeachEventEntry* fn_103_CBC4(void*, int);
PeachEventEntry* fn_103_CADC(void*, int);
PeachEventEntry* fn_103_CA2C(void*, int);
PeachEventEntry* fn_103_C97C(void*, int);
PeachEventEntry* fn_103_C894(void*, int);
void fn_103_CE44(PeachEventEntry*, void*);
void fn_103_CD5C(PeachEventEntry*, void*);
void fn_103_CC74(PeachEventEntry*, void*);
void fn_103_CB8C(PeachEventEntry*, void*);
void fn_103_EE90(PeachEventEntry*, void*);
void fn_103_E8A8(PeachEventEntry*, void*);
void fn_103_C944(PeachEventEntry*, void*);
void fn_103_E2E0(PeachEventEntry*, void*);
}

extern "C" void fn_103_C3B8(Byte* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        PeachEventEntry* entry = fn_103_CE7C(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_103_CE44(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        PeachEventEntry* entry = fn_103_CD94(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_103_CD5C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        PeachEventEntry* entry = fn_103_CCAC(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_103_CC74(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        PeachEventEntry* entry = fn_103_CBC4(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_103_CB8C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        PeachEventEntry* entry = fn_103_CADC(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_103_EE90(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        PeachEventEntry* entry = fn_103_CA2C(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_103_E8A8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        PeachEventEntry* entry = fn_103_C97C(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_103_C944(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        PeachEventEntry* entry = fn_103_C894(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_103_E2E0(entry, event);
    }
}
