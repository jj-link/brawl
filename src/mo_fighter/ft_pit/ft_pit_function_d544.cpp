#pragma force_active on
struct PitEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};

extern "C" {
void fn_27_35AC04(void* object, void* argument);
void fn_112_DA64(short* destination, const short* source);
int fn_112_D5D4(void* object, const short* source, void* argument);
}

extern "C" void fn_112_D544(void* object, const short* source, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    PitEntry* entry = reinterpret_cast<PitEntry*>(composite + 0xC);
    if ((*source & 1) != 0 && entry->isEnabled() == true && entry->disabled == false) {
        fn_27_35AC04(entry, argument);
    }

    short converted;
    fn_112_DA64(&converted, source);
    fn_112_D5D4(composite + 4, &converted, argument);
}
