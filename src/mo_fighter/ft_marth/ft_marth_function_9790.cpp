#pragma force_active on
struct Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
extern "C" {
Entry* fn_106_A2FC(void*, int);
Entry* fn_106_A214(void*, int);
Entry* fn_106_A12C(void*, int);
Entry* fn_106_A044(void*, int);
Entry* fn_106_9F5C(void*, int);
Entry* fn_106_9E74(void*, int);
Entry* fn_106_9D8C(void*, int);
Entry* fn_106_9CA4(void*, int);
void fn_106_A2C4(Entry*, void*);
void fn_106_A1DC(Entry*, void*);
void fn_106_A0F4(Entry*, void*);
void fn_106_A00C(Entry*, void*);
void fn_106_9F24(Entry*, void*);
void fn_106_9E3C(Entry*, void*);
void fn_106_9D54(Entry*, void*);
void fn_106_9C6C(Entry*, void*);
}
extern "C" void fn_106_9790(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_106_A2FC(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_106_A2C4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_106_A214(object + 0x1cc, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_106_A1DC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_106_A12C(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_106_A0F4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_106_A044(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_106_A00C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_106_9F5C(object + 0xf0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_106_9F24(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_106_9E74(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_106_9E3C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_106_9D8C(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_106_9D54(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_106_9CA4(object + 8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_106_9C6C(entry, event);
    }
}