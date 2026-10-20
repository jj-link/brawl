#pragma force_active on
namespace {
struct PitEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_112_D35C(void* entry, void* argument);
void fn_112_DA64(short* destination, const short* source);
int fn_112_D43C(void* object, const short* value, void* argument);
}

extern "C" void fn_112_D3AC(void* object, const short* source, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    PitEntry* entry = reinterpret_cast<PitEntry*>(composite + 0xC);
    if ((source[0] & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_112_D35C(entry, argument);

    short value;
    fn_112_DA64(&value, source);
    fn_112_D43C(composite + 4, &value, argument);
}
