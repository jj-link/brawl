#pragma force_active on
namespace {
struct LinkElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_93_E694(void*, void*);
void* fn_93_E94C(void* destination, const void* source);
void fn_93_E774(void*, void*, void*);
}

extern "C" void fn_93_E6E4(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 4) {
        bool enabled = reinterpret_cast<LinkElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_93_E694(element, argument);
        }
    }
    short next[4];
    fn_93_E94C(next, operation);
    fn_93_E774(composite + 4, next, argument);
}
