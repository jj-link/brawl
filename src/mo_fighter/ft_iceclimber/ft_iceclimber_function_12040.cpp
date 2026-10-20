#pragma force_active on
typedef signed short s16;

extern "C" void fn_105_11CFC(void*, void*);
extern "C" s16* fn_105_12C6C(s16*, const s16*);
extern "C" int fn_105_120D0(void*, const s16*, void*);

extern "C" void fn_105_12040(void* object, const s16* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (*operation & 2) {
        unsigned char enabled = (element[5] >> 7) & 1;
        unsigned int normalized = enabled ? 1 : 0;
        if (normalized == 1 && element[6] == 0) {
            fn_105_11CFC(element, argument);
        }
    }

    s16 next;
    fn_105_12C6C(&next, operation);
    fn_105_120D0(composite + 4, &next, argument);
}
