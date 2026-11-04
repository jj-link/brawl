#pragma force_active on
namespace {
typedef unsigned char Byte;
struct KirbyEventEntry {
    Byte prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}
extern "C" {
KirbyEventEntry* fn_96_13260(void*, int);
KirbyEventEntry* fn_96_13178(void*, int);
KirbyEventEntry* fn_96_13090(void*, int);
KirbyEventEntry* fn_96_12FA8(void*, int);
KirbyEventEntry* fn_96_12EC0(void*, int);
KirbyEventEntry* fn_96_12E10(void*, int);
KirbyEventEntry* fn_96_12D60(void*, int);
KirbyEventEntry* fn_96_12CB0(void*, int);
void fn_96_13228(KirbyEventEntry*, void*);
void fn_96_13140(KirbyEventEntry*, void*);
void fn_96_13058(KirbyEventEntry*, void*);
void fn_96_12F70(KirbyEventEntry*, void*);
void fn_96_21420(KirbyEventEntry*, void*);
void fn_96_211CC(KirbyEventEntry*, void*);
void fn_96_20C78(KirbyEventEntry*, void*);
void fn_96_12C78(KirbyEventEntry*, void*);
}

extern "C" void fn_96_1279C(Byte* object, void* accesser) {
    for (int i = 0; i < 1; ++i) {
        KirbyEventEntry* entry = fn_96_13260(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_96_13228(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KirbyEventEntry* entry = fn_96_13178(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_96_13140(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KirbyEventEntry* entry = fn_96_13090(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_96_13058(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KirbyEventEntry* entry = fn_96_12FA8(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_96_12F70(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KirbyEventEntry* entry = fn_96_12EC0(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_96_21420(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KirbyEventEntry* entry = fn_96_12E10(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_96_211CC(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KirbyEventEntry* entry = fn_96_12D60(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_96_20C78(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        KirbyEventEntry* entry = fn_96_12CB0(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_96_12C78(entry, accesser);
    }
}
