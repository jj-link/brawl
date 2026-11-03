#pragma force_active on
typedef unsigned char Byte;
struct Entry {
    Byte prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
extern "C" {
Entry* fn_93_E89C(void*, int);
void fn_93_E864(Entry*, void*);
Entry* fn_93_E7B4(void*, int);
void fn_93_E77C(Entry*, void*);
Entry* fn_93_E6CC(void*, int);
void fn_93_E694(Entry*, void*);
Entry* fn_93_E5E4(void*, int);
void fn_93_E5AC(Entry*, void*);
Entry* fn_93_E4FC(void*, int);
void fn_93_E4C4(Entry*, void*);
Entry* fn_93_E414(void*, int);
void fn_93_E3DC(Entry*, void*);
Entry* fn_93_E32C(void*, int);
void fn_93_E2F4(Entry*, void*);
Entry* fn_93_E244(void*, int);
void fn_93_E20C(Entry*, void*);
}
extern "C" void fn_93_DD30(Byte* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_93_E89C(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_93_E864(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_93_E7B4(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_93_E77C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_93_E6CC(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_93_E694(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_93_E5E4(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_93_E5AC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_93_E4FC(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_93_E4C4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_93_E414(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_93_E3DC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_93_E32C(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_93_E2F4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_93_E244(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_93_E20C(entry, event);
    }
}
