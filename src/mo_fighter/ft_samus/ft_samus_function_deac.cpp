#pragma force_active on
struct Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
extern "C" {
Entry* fn_94_EA18(void*, int);
Entry* fn_94_E930(void*, int);
Entry* fn_94_E848(void*, int);
Entry* fn_94_E760(void*, int);
Entry* fn_94_E678(void*, int);
Entry* fn_94_E590(void*, int);
Entry* fn_94_E4A8(void*, int);
Entry* fn_94_E3C0(void*, int);
void fn_94_E9E0(Entry*, void*);
void fn_94_E8F8(Entry*, void*);
void fn_94_E810(Entry*, void*);
void fn_94_E728(Entry*, void*);
void fn_94_E640(Entry*, void*);
void fn_94_E558(Entry*, void*);
void fn_94_E470(Entry*, void*);
void fn_94_E388(Entry*, void*);
}
extern "C" void fn_94_DEAC(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_94_EA18(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_94_E9E0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_94_E930(object + 0x1cc, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_94_E8F8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_94_E848(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_94_E810(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_94_E760(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_94_E728(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_94_E678(object + 0xf0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_94_E640(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_94_E590(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_94_E558(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_94_E4A8(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_94_E470(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_94_E3C0(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_94_E388(entry, event);
    }
}
