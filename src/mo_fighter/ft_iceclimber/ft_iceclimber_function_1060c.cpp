#pragma force_active on
struct Entry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char flags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
extern "C" {
Entry* fn_105_12BBC(void*, int);
Entry* fn_105_127E0(void*, int);
Entry* fn_105_12404(void*, int);
Entry* fn_105_12028(void*, int);
Entry* fn_105_11C4C(void*, int);
Entry* fn_105_11888(void*, int);
Entry* fn_105_114BC(void*, int);
Entry* fn_105_110EC(void*, int);
void fn_105_12890(Entry*, void*);
void fn_105_124B4(Entry*, void*);
void fn_105_120D8(Entry*, void*);
void fn_105_11CFC(Entry*, void*);
void fn_105_11938(Entry*, void*);
void fn_105_1156C(Entry*, void*);
void fn_105_1119C(Entry*, void*);
void fn_105_10DC0(Entry*, void*);
}
extern "C" void fn_105_1060C(unsigned char* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_105_12BBC(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_105_12890(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_105_127E0(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_105_124B4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_105_12404(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_105_120D8(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_105_12028(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_105_11CFC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_105_11C4C(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_105_11938(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_105_11888(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_105_1156C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_105_114BC(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_105_1119C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        Entry* entry = fn_105_110EC(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_105_10DC0(entry, event);
    }
}