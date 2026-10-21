#pragma force_active on
namespace {
struct SamusElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_94_E728(void* element, void* argument);
short* fn_94_EAC8(short* destination, const short* source);
void fn_94_E808(void* object, const short* operation, void* argument);
}

extern "C" void fn_94_E778(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 2) {
        bool enabled = reinterpret_cast<SamusElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_94_E728(element, argument);
        }
    }
    short next;
    fn_94_EAC8(&next, operation);
    fn_94_E808(composite + 4, &next, argument);
}
