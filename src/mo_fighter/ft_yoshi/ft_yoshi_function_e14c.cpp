#pragma force_active on
struct YoshiEventEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};

extern "C" {
YoshiEventEntry* fn_95_ECB8(void*, int);
YoshiEventEntry* fn_95_EBD0(void*, int);
YoshiEventEntry* fn_95_EAE8(void*, int);
YoshiEventEntry* fn_95_EA00(void*, int);
YoshiEventEntry* fn_95_E918(void*, int);
YoshiEventEntry* fn_95_E830(void*, int);
YoshiEventEntry* fn_95_E748(void*, int);
YoshiEventEntry* fn_95_E660(void*, int);
void fn_95_EC80(YoshiEventEntry*, void*);
void fn_95_EB98(YoshiEventEntry*, void*);
void fn_95_EAB0(YoshiEventEntry*, void*);
void fn_95_E9C8(YoshiEventEntry*, void*);
void fn_95_E8E0(YoshiEventEntry*, void*);
void fn_95_E7F8(YoshiEventEntry*, void*);
void fn_95_E710(YoshiEventEntry*, void*);
void fn_95_E628(YoshiEventEntry*, void*);
}

extern "C" void fn_95_E14C(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        YoshiEventEntry* entry = fn_95_ECB8(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_95_EC80(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        YoshiEventEntry* entry = fn_95_EBD0(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_95_EB98(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        YoshiEventEntry* entry = fn_95_EAE8(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_95_EAB0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        YoshiEventEntry* entry = fn_95_EA00(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_95_E9C8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        YoshiEventEntry* entry = fn_95_E918(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_95_E8E0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        YoshiEventEntry* entry = fn_95_E830(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_95_E7F8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        YoshiEventEntry* entry = fn_95_E748(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_95_E710(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        YoshiEventEntry* entry = fn_95_E660(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_95_E628(entry, event);
    }
}
