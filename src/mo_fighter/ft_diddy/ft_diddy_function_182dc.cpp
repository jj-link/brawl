#pragma force_active on
typedef short s16;

extern "C" void fn_115_1828C(void* state, void* arg);
extern "C" void fn_115_186D4(s16* destination, const s16* source);
extern "C" void fn_115_1836C(void* object, s16* buffer, void* arg);

struct Flags {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char rest : 7;
    unsigned char tail;
};

extern "C" void fn_115_182DC(unsigned char* self, const s16* source, void* arg) {
    Flags* sub = reinterpret_cast<Flags*>(self + 0xC);
    s16 buffer[4];

    if (source[0] & 1) {
        bool enabled = sub->enabled;
        if (enabled == true && sub->tail == 0) {
            fn_115_1828C(sub, arg);
        }
    }

    fn_115_186D4(buffer, source);
    fn_115_1836C(self + 4, buffer, arg);
}
