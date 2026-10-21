#pragma force_active on
namespace {
struct ZeldaElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_104_DB60(void*, void*);
short* fn_104_DC48(short* destination, const short* source);
void fn_104_DC40(void* object, const short* operation, void* argument);
}

extern "C" void fn_104_DBB0(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 4) {
        bool enabled = reinterpret_cast<ZeldaElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_104_DB60(element, argument);
        }
    }
    short local;
    fn_104_DC48(&local, operation);
    fn_104_DC40(composite + 4, &local, argument);
}
