#pragma force_active on
namespace {
struct PikminEntryValue {
    short value;
};
struct PikminElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_113_1D22C(void* element, void* accesser);
short* fn_113_1D4E4(short* destination, const PikminEntryValue* source);
int fn_113_1D30C(void* target, const short* source, void* accesser);
}

extern "C" void fn_113_1D27C(void* object, const PikminEntryValue* entry, void* accesser) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (entry->value & 4) {
        bool enabled = reinterpret_cast<PikminElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_113_1D22C(element, accesser);
        }
    }
    short next;
    fn_113_1D4E4(&next, entry);
    fn_113_1D30C(composite + 4, &next, accesser);
}
