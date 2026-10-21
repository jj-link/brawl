#pragma force_active on
namespace {
struct PokeIndex {
    short value;
};
struct PokeFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_116_D8B4(void* element, void* argument);
void fn_116_D99C(PokeIndex* destination, const PokeIndex* source);
void fn_116_D994(void* object, const PokeIndex* index, void* argument);
}

extern "C" void fn_116_D904(void* object, const PokeIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<PokeFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_116_D8B4(element, argument);
        }
    }
    PokeIndex next;
    fn_116_D99C(&next, operation);
    fn_116_D994(composite + 4, &next, argument);
}
