#pragma force_active on
struct Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
extern "C" {
Entry* fn_116_D8EC(void*, int);
Entry* fn_116_D804(void*, int);
Entry* fn_116_D71C(void*, int);
Entry* fn_116_D634(void*, int);
Entry* fn_116_D54C(void*, int);
Entry* fn_116_D464(void*, int);
Entry* fn_116_D37C(void*, int);
Entry* fn_116_D294(void*, int);
void fn_116_1A27C(Entry*, void*);
void fn_116_1A1AC(Entry*, void*);
void fn_116_1A0DC(Entry*, void*);
void fn_116_1A00C(Entry*, void*);
void fn_116_1ACAC(Entry*, void*);
void fn_116_19EA4(Entry*, void*);
void fn_116_1AFD0(Entry*, void*);
void fn_116_19D3C(Entry*, void*);
}
extern "C" void fn_116_19860(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D8EC(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_1A27C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D804(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_1A1AC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D71C(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_1A0DC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D634(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_1A00C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D54C(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_1ACAC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D464(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_19EA4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D37C(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_1AFD0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D294(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_19D3C(entry, event);
    }
}