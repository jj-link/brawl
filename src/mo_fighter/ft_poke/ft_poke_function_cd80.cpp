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
void fn_116_D8B4(Entry*, void*);
Entry* fn_116_D804(void*, int);
void fn_116_D7CC(Entry*, void*);
Entry* fn_116_D71C(void*, int);
void fn_116_D6E4(Entry*, void*);
Entry* fn_116_D634(void*, int);
void fn_116_D5FC(Entry*, void*);
Entry* fn_116_D54C(void*, int);
void fn_116_D514(Entry*, void*);
Entry* fn_116_D464(void*, int);
void fn_116_D42C(Entry*, void*);
Entry* fn_116_D37C(void*, int);
void fn_116_D344(Entry*, void*);
Entry* fn_116_D294(void*, int);
void fn_116_D25C(Entry*, void*);
}
extern "C" void fn_116_CD80(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D8EC(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_D8B4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D804(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_D7CC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D71C(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_D6E4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D634(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_D5FC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D54C(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_D514(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D464(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_D42C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D37C(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_D344(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_116_D294(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_116_D25C(entry, event);
    }
}
