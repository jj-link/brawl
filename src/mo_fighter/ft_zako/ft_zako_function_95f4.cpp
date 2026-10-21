#pragma force_active on
namespace {
struct ZakoElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_126_95A4(unsigned char* element, void* arg);
void fn_126_968C(short* destination, const short* source);
void fn_126_9684(unsigned char* object, const short* source, void* arg);
}

extern "C" void fn_126_95F4(unsigned char* object, const short* source, void* arg) {
    unsigned char* element = object + 0xC;
    if (source[0] & 4) {
        bool enabled = reinterpret_cast<ZakoElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_126_95A4(element, arg);
        }
    }
    short tmp[2];
    fn_126_968C(tmp, source);
    fn_126_9684(object + 4, tmp, arg);
}
