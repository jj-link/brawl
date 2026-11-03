#pragma force_active on
typedef unsigned char Byte;
struct PitTraversalEntry {
    Byte prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
extern "C" {
PitTraversalEntry* fn_112_D9B4(void*, int);
void fn_112_D97C(PitTraversalEntry*, void*);
PitTraversalEntry* fn_112_D8CC(void*, int);
void fn_112_D894(PitTraversalEntry*, void*);
PitTraversalEntry* fn_112_D7E4(void*, int);
void fn_112_D7AC(PitTraversalEntry*, void*);
PitTraversalEntry* fn_112_D6FC(void*, int);
void fn_112_D6C4(PitTraversalEntry*, void*);
PitTraversalEntry* fn_112_D614(void*, int);
void fn_112_D5DC(PitTraversalEntry*, void*);
PitTraversalEntry* fn_112_D52C(void*, int);
void fn_27_35AC04(PitTraversalEntry*, void*);
PitTraversalEntry* fn_112_D47C(void*, int);
void fn_112_D444(PitTraversalEntry*, void*);
PitTraversalEntry* fn_112_D394(void*, int);
void fn_112_D35C(PitTraversalEntry*, void*);
}
extern "C" void fn_112_CE80(Byte* object, void* argument) {
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = fn_112_D9B4(object + 0x208, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_112_D97C(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = fn_112_D8CC(object + 0x1CC, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_112_D894(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = fn_112_D7E4(object + 0x180, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_112_D7AC(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = fn_112_D6FC(object + 0x138, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_112_D6C4(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = fn_112_D614(object + 0xF0, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_112_D5DC(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = fn_112_D52C(object + 0x98, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_27_35AC04(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = fn_112_D47C(object + 0x64, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_112_D444(entry, argument);
    }
    for (int i = 0; i < 1; ++i) {
        PitTraversalEntry* entry = fn_112_D394(object + 0x8, i);
        if (entry->isEnabled() == true && entry->disabled == false)
            fn_112_D35C(entry, argument);
    }
}
