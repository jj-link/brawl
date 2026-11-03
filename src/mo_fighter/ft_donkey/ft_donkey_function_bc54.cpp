#pragma force_active on
struct Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
extern "C" {
Entry* fn_92_C7C0(void*, int);
Entry* fn_92_C6D8(void*, int);
Entry* fn_92_C5F0(void*, int);
Entry* fn_92_C508(void*, int);
Entry* fn_92_C420(void*, int);
Entry* fn_92_C338(void*, int);
Entry* fn_92_C250(void*, int);
Entry* fn_92_C168(void*, int);
void fn_92_C788(Entry*, void*);
void fn_92_C6A0(Entry*, void*);
void fn_92_C5B8(Entry*, void*);
void fn_92_C4D0(Entry*, void*);
void fn_92_C3E8(Entry*, void*);
void fn_92_C300(Entry*, void*);
void fn_92_C218(Entry*, void*);
void fn_92_C130(Entry*, void*);
}
extern "C" void fn_92_BC54(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_92_C7C0(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_92_C788(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_92_C6D8(object + 0x1cc, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_92_C6A0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_92_C5F0(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_92_C5B8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_92_C508(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_92_C4D0(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_92_C420(object + 0xf0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_92_C3E8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_92_C338(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_92_C300(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_92_C250(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_92_C218(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_92_C168(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_92_C130(entry, event);
    }
}
