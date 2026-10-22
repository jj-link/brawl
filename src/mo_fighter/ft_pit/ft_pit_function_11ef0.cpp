#pragma force_active on
namespace {
typedef unsigned char Byte;
struct PitTraversalEntry {
    Byte prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void* fn_112_1250C(void*, int);
void* fn_112_12424(void*, int);
void* fn_112_1233C(void*, int);
void* fn_112_12254(void*, int);
void fn_112_124D4(void*, void*);
void fn_112_123EC(void*, void*);
void fn_112_12304(void*, void*);
void fn_112_1221C(void*, void*);
}

// Dispatch enabled, unsuspended entries from each embedded singleton event array.
extern "C" void fn_112_11EF0(Byte* object, void* argument) {
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = static_cast<PitTraversalEntry*>(fn_112_1250C(object + 0xF0, i));
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_112_124D4(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = static_cast<PitTraversalEntry*>(fn_112_12424(object + 0xAC, i));
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_112_123EC(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = static_cast<PitTraversalEntry*>(fn_112_1233C(object + 0x5C, i));
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_112_12304(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = static_cast<PitTraversalEntry*>(fn_112_12254(object + 0x8, i));
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_112_1221C(entry, argument);
    }
}
