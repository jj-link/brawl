#pragma force_active on
typedef signed short s16;
typedef signed int s32;

namespace {
struct ElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_113_F9E4(void* object, void* arg);
void fn_113_FD84(s16* destination, const s16* source);
s32 fn_113_FAC4(void* object, const s16* operation, void* arg);
}

extern "C" void fn_113_FA34(void* object, const s16* operation, void* arg) {
    unsigned char* element = static_cast<unsigned char*>(object) + 0xC;
    if (*operation & 2) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_113_F9E4(element, arg);
        }
    }
    s16 next;
    fn_113_FD84(&next, operation);
    fn_113_FAC4(static_cast<unsigned char*>(object) + 4, &next, arg);
}
