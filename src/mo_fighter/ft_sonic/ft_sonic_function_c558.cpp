#pragma force_active on
struct SonicProcessEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};

extern "C" {
SonicProcessEntry* fn_123_EC84(void*, int);
SonicProcessEntry* fn_123_E880(void*, int);
SonicProcessEntry* fn_123_E47C(void*, int);
SonicProcessEntry* fn_123_E078(void*, int);
SonicProcessEntry* fn_123_DC74(void*, int);
SonicProcessEntry* fn_123_D884(void*, int);
SonicProcessEntry* fn_123_D488(void*, int);
SonicProcessEntry* fn_123_D08C(void*, int);
void fn_123_E930(void*, void*);
void fn_123_E52C(void*, void*);
void fn_123_E128(void*, void*);
void fn_123_DD24(void*, void*);
void fn_123_D934(void*, void*);
void fn_123_D538(void*, void*);
void fn_123_D13C(void*, void*);
void fn_123_CD38(void*, void*);
}

extern "C" void fn_123_C558(unsigned char* object, void* accesser) {
    for (int i = 0; i < 1; ++i) {
        SonicProcessEntry* entry = fn_123_EC84(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_123_E930(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        SonicProcessEntry* entry = fn_123_E880(object + 0x1cc, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_123_E52C(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        SonicProcessEntry* entry = fn_123_E47C(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_123_E128(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        SonicProcessEntry* entry = fn_123_E078(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_123_DD24(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        SonicProcessEntry* entry = fn_123_DC74(object + 0xf0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_123_D934(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        SonicProcessEntry* entry = fn_123_D884(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_123_D538(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        SonicProcessEntry* entry = fn_123_D488(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_123_D13C(entry, accesser);
    }
    for (int i = 0; i < 1; ++i) {
        SonicProcessEntry* entry = fn_123_D08C(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_123_CD38(entry, accesser);
    }
}
