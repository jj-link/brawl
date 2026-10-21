#pragma force_active on
namespace {
struct ZeldaElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_104_D990(void* object, void* argument);
short* fn_104_DC48(short* destination, const short* source);
int fn_104_DA70(void* object, short* operation, void* argument);
}

extern "C" void fn_104_D9E0(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 4) {
        bool enabled = reinterpret_cast<ZeldaElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_104_D990(element, argument);
        }
    }
    short next;
    fn_104_DC48(&next, operation);
    fn_104_DA70(composite + 4, &next, argument);
}
