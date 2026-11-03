#pragma force_active on
namespace {
struct ZakoIndex {
    short value;
};
}

extern "C" {
void fn_126_8F40(ZakoIndex*, const short*);
void fn_126_968C(ZakoIndex*, const ZakoIndex*);
void fn_126_95F4(void*, const ZakoIndex*, void*);
void fn_126_950C(void*, const ZakoIndex*, void*);
void fn_126_9424(void*, const ZakoIndex*, void*);
void fn_126_933C(void*, const ZakoIndex*, void*);
void fn_126_9254(void*, const ZakoIndex*, void*);
void fn_126_916C(void*, const ZakoIndex*, void*);
void fn_126_9084(void*, const ZakoIndex*, void*);
void fn_126_8F9C(void*, const ZakoIndex*, void*);
}

extern "C" void fn_126_8D04(void* object, void* argument, const short* index) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    ZakoIndex operation;
    short value = *index;
    ZakoIndex second, fourth, sixth, eighth;
    ZakoIndex seventh, fifth, third, first;

    fn_126_8F40(&operation, &value);
    fn_126_968C(&first, &operation);
    fn_126_95F4(composite + 0x208, &first, argument);
    fn_126_968C(&second, &operation);
    fn_126_950C(composite + 0x1CC, &second, argument);
    fn_126_968C(&third, &operation);
    fn_126_9424(composite + 0x180, &third, argument);
    fn_126_968C(&fourth, &operation);
    fn_126_933C(composite + 0x138, &fourth, argument);
    fn_126_968C(&fifth, &operation);
    fn_126_9254(composite + 0xF0, &fifth, argument);
    fn_126_968C(&sixth, &operation);
    fn_126_916C(composite + 0x98, &sixth, argument);
    fn_126_968C(&seventh, &operation);
    fn_126_9084(composite + 0x64, &seventh, argument);
    fn_126_968C(&eighth, &operation);
    fn_126_8F9C(composite + 8, &eighth, argument);
}
