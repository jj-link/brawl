#pragma force_active on
typedef short s16;

struct FtSnakeFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_122_13784(void* object, void* argument);
void fn_122_13B24(s16* destination, const s16* source);
void fn_122_13864(void* object, s16* source, void* argument);
}

extern "C" void fn_122_137D4(void* object, const s16* source, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    s16 local[4];
    if (source[0] & 2) {
        bool enabled = reinterpret_cast<FtSnakeFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_122_13784(element, argument);
        }
    }
    fn_122_13B24(local, source);
    fn_122_13864(composite + 4, local, argument);
}
