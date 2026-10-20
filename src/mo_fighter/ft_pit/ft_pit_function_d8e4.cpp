#pragma force_active on
namespace {
struct PitTraversalIndex {
    short value;
};
struct PitElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_112_D894(void*, void*);
void fn_112_DA64(PitTraversalIndex*, const PitTraversalIndex*);
void fn_112_D974(void*, const PitTraversalIndex*, void*);
}

extern "C" void fn_112_D8E4(void* object, const PitTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 8) {
        bool enabled = reinterpret_cast<PitElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_112_D894(element, argument);
        }
    }
    PitTraversalIndex next;
    fn_112_DA64(&next, operation);
    fn_112_D974(composite + 4, &next, argument);
}
