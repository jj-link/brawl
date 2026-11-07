#pragma force_active on
struct Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};

extern "C" {
Entry* fn_115_D66C(void*, int);
Entry* fn_115_D584(void*, int);
Entry* fn_115_D49C(void*, int);
Entry* fn_115_D3B4(void*, int);
Entry* fn_115_D2CC(void*, int);
Entry* fn_115_D1E4(void*, int);
Entry* fn_115_D0FC(void*, int);
Entry* fn_115_D014(void*, int);
void fn_115_D634(Entry*, void*);
void fn_115_D54C(Entry*, void*);
void fn_115_D464(Entry*, void*);
void fn_115_D37C(Entry*, void*);
void fn_115_D294(Entry*, void*);
void fn_115_D1AC(Entry*, void*);
void fn_115_D0C4(Entry*, void*);
void fn_115_CFDC(Entry*, void*);
}

extern "C" void fn_115_CB00(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_115_D66C(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_115_D634(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_115_D584(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_115_D54C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_115_D49C(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_115_D464(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_115_D3B4(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_115_D37C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_115_D2CC(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_115_D294(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_115_D1E4(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_115_D1AC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_115_D0FC(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_115_D0C4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_115_D014(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_115_CFDC(entry, event);
    }
}