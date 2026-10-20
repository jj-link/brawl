#pragma force_active on
struct FtGanonElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_109_BEC0(void*, void*);
void fn_109_BFA8(short*, const short*);
void fn_109_BFA0(void*, const short*, void*);
}

extern "C" void fn_109_BF10(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation[0] & 4) {
        bool enabled = reinterpret_cast<FtGanonElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_109_BEC0(element, argument);
        }
    }
    short next;
    fn_109_BFA8(&next, operation);
    fn_109_BFA0(composite + 4, &next, argument);
}
