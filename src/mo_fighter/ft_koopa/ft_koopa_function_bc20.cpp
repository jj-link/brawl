#pragma force_active on
namespace {
struct KoopaElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_102_BBD0(void*, void*);
short* fn_102_BE88(short*, const short*);
int fn_102_BCB0(void*, const short*, void*);
}

extern "C" void fn_102_BC20(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (*operation & 4) {
        bool enabled = reinterpret_cast<KoopaElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_102_BBD0(element, argument);
        }
    }
    short next;
    fn_102_BE88(&next, operation);
    fn_102_BCB0(composite + 4, &next, argument);
}
