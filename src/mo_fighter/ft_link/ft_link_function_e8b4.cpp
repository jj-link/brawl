#pragma force_active on
namespace {
struct LinkElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_93_E864(void* element, void* argument);
short* fn_93_E94C(short* destination, const short* source);
int fn_93_E944(void* object, const short* source, void* argument);
}

extern "C" void fn_93_E8B4(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 4) {
        bool enabled = reinterpret_cast<LinkElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_93_E864(element, argument);
        }
    }
    short next;
    fn_93_E94C(&next, operation);
    fn_93_E944(composite + 4, &next, argument);
}
