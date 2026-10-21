#pragma force_active on
typedef short s16;

namespace {
struct FtZakoElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" void fn_126_93D4(unsigned char* element, void* argument);
extern "C" void fn_126_968C(s16* destination, const s16* source);
extern "C" void fn_126_94B4(unsigned char* object, const s16* operation, void* argument);

extern "C" void fn_126_9424(unsigned char* object, const s16* operation, void* argument) {
    unsigned char* element = object + 0xC;
    s16 local;
    if (operation[0] & 4) {
        bool enabled = reinterpret_cast<FtZakoElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_126_93D4(element, argument);
        }
    }
    fn_126_968C(&local, operation);
    fn_126_94B4(object + 4, &local, argument);
}
