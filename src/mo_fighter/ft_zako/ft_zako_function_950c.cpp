#pragma force_active on
namespace {
struct FtZakoElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_126_94BC(void*, void*);
void fn_126_968C(short*, const short*);
int fn_126_959C(void*, const short*, void*);
}

extern "C" void fn_126_950C(void* object, const short* source, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*source & 0x8) {
        bool enabled = reinterpret_cast<FtZakoElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_126_94BC(element, argument);
        }
    }
    short local;
    fn_126_968C(&local, source);
    fn_126_959C(composite + 4, &local, argument);
}
