#pragma force_active on
namespace {
struct FtDonkeyElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_92_C5B8(void*, void*);
void fn_92_C870(short*, const short*);
void fn_92_C698(void*, const short*, void*);
}

extern "C" void fn_92_C608(unsigned char* object, const short* source, void* argument) {
    unsigned char* element = object + 0xC;
    if (source[0] & 4) {
        bool enabled = reinterpret_cast<FtDonkeyElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_92_C5B8(element, argument);
        }
    }
    short converted[4];
    fn_92_C870(converted, source);
    fn_92_C698(object + 4, converted, argument);
}
