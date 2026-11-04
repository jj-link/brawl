#pragma force_active on
// Entry layout shared by Lucario's embedded process collections.
struct LucarioProcessEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};

extern "C" {
LucarioProcessEntry* fn_118_D19C(void*, int);
LucarioProcessEntry* fn_118_D0B4(void*, int);
LucarioProcessEntry* fn_118_CFCC(void*, int);
LucarioProcessEntry* fn_118_CEE4(void*, int);
LucarioProcessEntry* fn_118_CDFC(void*, int);
LucarioProcessEntry* fn_118_CD14(void*, int);
LucarioProcessEntry* fn_118_CC2C(void*, int);
LucarioProcessEntry* fn_118_CB44(void*, int);
void fn_118_D164(LucarioProcessEntry*, void*);
void fn_118_D07C(LucarioProcessEntry*, void*);
void fn_118_CF94(LucarioProcessEntry*, void*);
void fn_118_CEAC(LucarioProcessEntry*, void*);
void fn_118_CDC4(LucarioProcessEntry*, void*);
void fn_118_CCDC(LucarioProcessEntry*, void*);
void fn_118_CBF4(LucarioProcessEntry*, void*);
void fn_118_CB0C(LucarioProcessEntry*, void*);
}

extern "C" void fn_118_C630(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        LucarioProcessEntry* entry = fn_118_D19C(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_118_D164(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        LucarioProcessEntry* entry = fn_118_D0B4(object + 0x1cc, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_118_D07C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        LucarioProcessEntry* entry = fn_118_CFCC(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_118_CF94(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        LucarioProcessEntry* entry = fn_118_CEE4(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_118_CEAC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        LucarioProcessEntry* entry = fn_118_CDFC(object + 0xf0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_118_CDC4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        LucarioProcessEntry* entry = fn_118_CD14(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_118_CCDC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        LucarioProcessEntry* entry = fn_118_CC2C(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_118_CBF4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        LucarioProcessEntry* entry = fn_118_CB44(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_118_CB0C(entry, event);
    }
}
