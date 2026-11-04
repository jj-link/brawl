#pragma force_active on
struct Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};

extern "C" {
Entry* fn_97_E574(void*, int);
Entry* fn_97_E48C(void*, int);
Entry* fn_97_E3A4(void*, int);
Entry* fn_97_E2BC(void*, int);
Entry* fn_97_E1D4(void*, int);
Entry* fn_97_E0EC(void*, int);
Entry* fn_97_E004(void*, int);
Entry* fn_97_DF1C(void*, int);
void fn_97_E53C(Entry*, void*);
void fn_97_E454(Entry*, void*);
void fn_97_E36C(Entry*, void*);
void fn_97_E284(Entry*, void*);
void fn_97_E19C(Entry*, void*);
void fn_97_E0B4(Entry*, void*);
void fn_97_DFCC(Entry*, void*);
void fn_97_DEE4(Entry*, void*);
}

extern "C" void fn_97_DA08(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_97_E574(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_97_E53C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_97_E48C(object + 0x1cc, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_97_E454(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_97_E3A4(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_97_E36C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_97_E2BC(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_97_E284(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_97_E1D4(object + 0xf0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_97_E19C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_97_E0EC(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_97_E0B4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_97_E004(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_97_DFCC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_97_DF1C(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_97_DEE4(entry, event);
    }
}
