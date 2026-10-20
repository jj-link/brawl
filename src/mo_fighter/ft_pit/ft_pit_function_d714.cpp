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
void fn_112_D6C4(void*, void*);
void fn_112_DA64(short*, const short*);
void fn_112_D7A4(void*, short*, void*);
}

extern "C" void fn_112_D714(void* object, const PitTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 2) {
        bool enabled = reinterpret_cast<PitElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_112_D6C4(element, argument);
        }
    }
    short next;
    fn_112_DA64(&next, &operation->value);
    fn_112_D7A4(composite + 4, &next, argument);
}
