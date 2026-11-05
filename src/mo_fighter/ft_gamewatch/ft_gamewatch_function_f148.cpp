#pragma force_active on
struct GameWatchEventEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};

extern "C" {
GameWatchEventEntry* fn_107_FCB4(void*, int);
GameWatchEventEntry* fn_107_FBCC(void*, int);
GameWatchEventEntry* fn_107_FAE4(void*, int);
GameWatchEventEntry* fn_107_F9FC(void*, int);
GameWatchEventEntry* fn_107_F914(void*, int);
GameWatchEventEntry* fn_107_F82C(void*, int);
GameWatchEventEntry* fn_107_F744(void*, int);
GameWatchEventEntry* fn_107_F65C(void*, int);
void fn_107_FC7C(void*, void*);
void fn_107_FB94(void*, void*);
void fn_107_FAAC(void*, void*);
void fn_107_F9C4(void*, void*);
void fn_107_F8DC(void*, void*);
void fn_107_F7F4(void*, void*);
void fn_107_F70C(void*, void*);
void fn_107_F624(void*, void*);
}

// Dispatch enabled, unsuspended entries from each embedded singleton event array.
extern "C" void fn_107_F148(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        GameWatchEventEntry* entry = fn_107_FCB4(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_107_FC7C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        GameWatchEventEntry* entry = fn_107_FBCC(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_107_FB94(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        GameWatchEventEntry* entry = fn_107_FAE4(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_107_FAAC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        GameWatchEventEntry* entry = fn_107_F9FC(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_107_F9C4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        GameWatchEventEntry* entry = fn_107_F914(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_107_F8DC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        GameWatchEventEntry* entry = fn_107_F82C(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_107_F7F4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        GameWatchEventEntry* entry = fn_107_F744(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_107_F70C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        GameWatchEventEntry* entry = fn_107_F65C(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_107_F624(entry, event);
    }
}
