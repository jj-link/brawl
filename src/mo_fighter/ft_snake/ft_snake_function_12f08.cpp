#pragma force_active on
namespace {
typedef unsigned char Byte;
struct SnakeEventEntry {
    Byte prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
SnakeEventEntry* fn_122_13A74(void*, int);
SnakeEventEntry* fn_122_1398C(void*, int);
SnakeEventEntry* fn_122_138A4(void*, int);
SnakeEventEntry* fn_122_137BC(void*, int);
SnakeEventEntry* fn_122_136D4(void*, int);
SnakeEventEntry* fn_122_135EC(void*, int);
SnakeEventEntry* fn_122_13504(void*, int);
SnakeEventEntry* fn_122_1341C(void*, int);
void fn_122_13A3C(SnakeEventEntry*, void*);
void fn_122_13954(SnakeEventEntry*, void*);
void fn_122_1386C(SnakeEventEntry*, void*);
void fn_122_13784(SnakeEventEntry*, void*);
void fn_122_1369C(SnakeEventEntry*, void*);
void fn_122_135B4(SnakeEventEntry*, void*);
void fn_122_134CC(SnakeEventEntry*, void*);
void fn_122_133E4(SnakeEventEntry*, void*);
}

// Dispatch enabled, unsuspended entries from each embedded singleton event array.
extern "C" void fn_122_12F08(Byte* object, void* event) {
    for (int i = 0; i < 1; ++i) {
        SnakeEventEntry* entry = fn_122_13A74(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_122_13A3C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        SnakeEventEntry* entry = fn_122_1398C(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_122_13954(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        SnakeEventEntry* entry = fn_122_138A4(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_122_1386C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        SnakeEventEntry* entry = fn_122_137BC(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_122_13784(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        SnakeEventEntry* entry = fn_122_136D4(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_122_1369C(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        SnakeEventEntry* entry = fn_122_135EC(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_122_135B4(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        SnakeEventEntry* entry = fn_122_13504(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_122_134CC(entry, event);
    }
    for (int i = 0; i < 1; ++i) {
        SnakeEventEntry* entry = fn_122_1341C(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_122_133E4(entry, event);
    }
}
