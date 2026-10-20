#pragma force_active on
typedef short s16;

struct PitElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_112_D7AC(void*, void*);
void fn_112_DA64(s16*, const s16*);
void fn_112_D88C(void*, s16*, void*);
}

extern "C" void fn_112_D7FC(unsigned char* object, const s16* index, void* argument) {
    unsigned char* element = object + 0xC;
    if (index[0] & 4) {
        bool enabled = reinterpret_cast<PitElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_112_D7AC(element, argument);
        }
    }
    s16 next;
    fn_112_DA64(&next, index);
    fn_112_D88C(object + 4, &next, argument);
}
