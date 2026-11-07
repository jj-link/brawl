#pragma force_active on
struct Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};

extern "C" {
Entry* fn_126_95DC(void*, int);
Entry* fn_126_94F4(void*, int);
Entry* fn_126_940C(void*, int);
Entry* fn_126_9324(void*, int);
Entry* fn_126_923C(void*, int);
Entry* fn_126_9154(void*, int);
Entry* fn_126_906C(void*, int);
Entry* fn_126_8F84(void*, int);

void fn_126_95A4(Entry*, void*);
void fn_126_94BC(Entry*, void*);
void fn_126_93D4(Entry*, void*);
void fn_126_92EC(Entry*, void*);
void fn_126_9204(Entry*, void*);
void fn_126_911C(Entry*, void*);
void fn_126_9034(Entry*, void*);
void fn_126_8F4C(Entry*, void*);
}

extern "C" void fn_126_8A70(unsigned char* object, void* argument) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_126_95DC(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_126_95A4(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_126_94F4(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_126_94BC(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_126_940C(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_126_93D4(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_126_9324(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_126_92EC(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_126_923C(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_126_9204(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_126_9154(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_126_911C(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_126_906C(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_126_9034(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_126_8F84(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_126_8F4C(entry, argument);
    }
}
