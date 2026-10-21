#pragma force_active on
namespace {
struct ToonlinkElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_121_E778(void*, void*);
void fn_121_E948(short*, const short*);
void fn_121_E858(void*, const short*, void*);
}

extern "C" void fn_121_E7C8(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 8) {
        bool enabled = reinterpret_cast<ToonlinkElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_121_E778(element, argument);
        }
    }
    short next;
    fn_121_E948(&next, operation);
    fn_121_E858(composite + 4, &next, argument);
}
