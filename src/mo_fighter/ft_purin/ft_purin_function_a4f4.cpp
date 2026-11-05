#pragma force_active on
struct Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
extern "C" {
Entry* fn_124_B060(void*, int);
Entry* fn_124_AF78(void*, int);
Entry* fn_124_AE90(void*, int);
Entry* fn_124_ADA8(void*, int);
Entry* fn_124_ACC0(void*, int);
Entry* fn_124_ABD8(void*, int);
Entry* fn_124_AAF0(void*, int);
Entry* fn_124_AA08(void*, int);
void fn_124_B028(Entry*, void*);
void fn_124_AF40(Entry*, void*);
void fn_124_AE58(Entry*, void*);
void fn_124_AD70(Entry*, void*);
void fn_124_AC88(Entry*, void*);
void fn_124_ABA0(Entry*, void*);
void fn_124_AAB8(Entry*, void*);
void fn_124_A9D0(Entry*, void*);
}
extern "C" void fn_124_A4F4(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_124_B060(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_124_B028(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_124_AF78(object + 0x1cc, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_124_AF40(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_124_AE90(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_124_AE58(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_124_ADA8(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_124_AD70(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_124_ACC0(object + 0xf0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_124_AC88(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_124_ABD8(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_124_ABA0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_124_AAF0(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_124_AAB8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_124_AA08(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_124_A9D0(entry, event);
    }
}
