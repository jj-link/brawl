#pragma force_active on
namespace {
struct FtPokeIndex {
    short value;
};
struct FtPokeFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_116_1A0DC(void*, void*);
FtPokeIndex* fn_116_1A34C(FtPokeIndex*, const FtPokeIndex*);
int fn_116_1A1A4(void*, const FtPokeIndex*, void*);
}

extern "C" void fn_116_1A114(void* object, const FtPokeIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<FtPokeFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_116_1A0DC(element, argument);
        }
    }
    FtPokeIndex next;
    fn_116_1A34C(&next, operation);
    fn_116_1A1A4(composite + 4, &next, argument);
}
