#pragma force_active on
struct Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
extern "C" {
Entry* fn_91_DA08(void*, int);
Entry* fn_91_D920(void*, int);
Entry* fn_91_D838(void*, int);
Entry* fn_91_D750(void*, int);
Entry* fn_91_D668(void*, int);
Entry* fn_91_D580(void*, int);
Entry* fn_91_D498(void*, int);
Entry* fn_91_D3B0(void*, int);
void fn_91_D9D0(Entry*, void*);
void fn_91_D8E8(Entry*, void*);
void fn_91_D800(Entry*, void*);
void fn_91_D718(Entry*, void*);
void fn_91_D630(Entry*, void*);
void fn_91_D548(Entry*, void*);
void fn_91_D460(Entry*, void*);
void fn_91_D378(Entry*, void*);
}
extern "C" void fn_91_CE9C(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_91_DA08(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_91_D9D0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_91_D920(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_91_D8E8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_91_D838(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_91_D800(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_91_D750(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_91_D718(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_91_D668(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_91_D630(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_91_D580(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_91_D548(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_91_D498(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_91_D460(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_91_D3B0(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_91_D378(entry, event);
    }
}
