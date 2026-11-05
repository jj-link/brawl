#pragma force_active on
struct Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
extern "C" {
Entry* fn_121_E898(void*, int);
Entry* fn_121_E7B0(void*, int);
Entry* fn_121_E6C8(void*, int);
Entry* fn_121_E5E0(void*, int);
Entry* fn_121_E4F8(void*, int);
Entry* fn_121_E410(void*, int);
Entry* fn_121_E328(void*, int);
Entry* fn_121_E240(void*, int);
void fn_121_E860(Entry*, void*);
void fn_121_E778(Entry*, void*);
void fn_121_E690(Entry*, void*);
void fn_121_E5A8(Entry*, void*);
void fn_121_E4C0(Entry*, void*);
void fn_121_E3D8(Entry*, void*);
void fn_121_E2F0(Entry*, void*);
void fn_121_E208(Entry*, void*);
}
extern "C" void fn_121_DD2C(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_121_E898(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_121_E860(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_121_E7B0(object + 0x1cc, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_121_E778(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_121_E6C8(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_121_E690(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_121_E5E0(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_121_E5A8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_121_E4F8(object + 0xf0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_121_E4C0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_121_E410(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_121_E3D8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_121_E328(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_121_E2F0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_121_E240(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_121_E208(entry, event);
    }
}
