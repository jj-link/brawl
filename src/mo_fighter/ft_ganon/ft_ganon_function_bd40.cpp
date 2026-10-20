#pragma force_active on
namespace {
struct FtGanonElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_109_BCF0(void*, void*);
void fn_109_BFA8(short*, const short*);
int fn_109_BDD0(void*, const short*, void*);
}

extern "C" void fn_109_BD40(void* object, const short* source, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*source & 4) {
        bool enabled = reinterpret_cast<FtGanonElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_109_BCF0(element, argument);
        }
    }
    short local;
    fn_109_BFA8(&local, source);
    fn_109_BDD0(composite + 4, &local, argument);
}
