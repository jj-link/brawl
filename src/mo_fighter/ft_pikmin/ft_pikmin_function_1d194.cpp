#pragma force_active on
extern "C" {
void fn_113_1D144(void*, void*);
short* fn_113_1D4E4(short* destination, const short* source);
int fn_113_1D224(void* object, const short* operation, void* argument);
}

namespace {
struct PikminElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" void fn_113_1D194(void* object, const short* source, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*source & 8) {
        bool enabled = reinterpret_cast<PikminElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_113_1D144(element, argument);
        }
    }
    short next;
    fn_113_1D4E4(&next, source);
    fn_113_1D224(composite + 4, &next, argument);
}
