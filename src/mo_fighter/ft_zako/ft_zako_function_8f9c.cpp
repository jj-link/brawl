#pragma force_active on
namespace {
struct ZakoIndex {
    short value;
};

struct ZakoEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;
    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_126_8F4C(void*, void*);
void fn_126_968C(ZakoIndex*, const ZakoIndex*);
int fn_126_902C(void*, const ZakoIndex*, void*);
}

extern "C" void fn_126_8F9C(void* object, const ZakoIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    ZakoEntry* entry = reinterpret_cast<ZakoEntry*>(composite + 0xC);
    if ((index->value & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_126_8F4C(entry, argument);

    ZakoIndex operation;
    fn_126_968C(&operation, index);
    fn_126_902C(composite + 4, &operation, argument);
}
