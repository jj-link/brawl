#pragma force_active on
namespace {
struct FighterElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_113_FACC(void*, void*);
void fn_113_FD84(short*, const short*);
void fn_113_FBAC(void*, const short*, void*);
}

extern "C" void fn_113_FB1C(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation[0] & 4) {
        bool enabled = reinterpret_cast<FighterElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_113_FACC(element, argument);
        }
    }
    short next;
    fn_113_FD84(&next, operation);
    fn_113_FBAC(composite + 4, &next, argument);
}
