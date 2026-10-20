#pragma force_active on
namespace {
struct DededeEventMask {
    short value;
};
struct DededeElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_117_DDC4(void*, void*);
void fn_117_DF94(DededeEventMask*, const DededeEventMask*);
void fn_117_DEA4(void*, const DededeEventMask*, void*);
}

extern "C" void fn_117_DE14(void* object, const DededeEventMask* mask, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (mask->value & 8) {
        bool enabled = reinterpret_cast<DededeElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_117_DDC4(element, argument);
        }
    }
    DededeEventMask next;
    fn_117_DF94(&next, mask);
    fn_117_DEA4(composite + 4, &next, argument);
}
