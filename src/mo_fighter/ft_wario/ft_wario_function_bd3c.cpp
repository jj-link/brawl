#pragma force_active on
namespace {
struct WarioTraversalIndex {
    short value;
};
}

extern "C" {
void fn_110_BF78(WarioTraversalIndex*, const short*);
void fn_110_C6C4(WarioTraversalIndex*, const WarioTraversalIndex*);
void fn_110_C62C(void*, const WarioTraversalIndex*, void*);
void fn_110_C544(void*, const WarioTraversalIndex*, void*);
void fn_110_C45C(void*, const WarioTraversalIndex*, void*);
void fn_110_C374(void*, const WarioTraversalIndex*, void*);
void fn_110_C28C(void*, const WarioTraversalIndex*, void*);
void fn_110_C1A4(void*, const WarioTraversalIndex*, void*);
void fn_110_C0BC(void*, const WarioTraversalIndex*, void*);
void fn_110_BFD4(void*, const WarioTraversalIndex*, void*);
}

extern "C" void fn_110_BD3C(void* object, void* argument, const short* index) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    WarioTraversalIndex operation;
    short value = *index;
    WarioTraversalIndex second, fourth, sixth, eighth;
    WarioTraversalIndex seventh, fifth, third, first;

    fn_110_BF78(&operation, &value);
    fn_110_C6C4(&first, &operation);
    fn_110_C62C(composite + 0x208, &first, argument);
    fn_110_C6C4(&second, &operation);
    fn_110_C544(composite + 0x1CC, &second, argument);
    fn_110_C6C4(&third, &operation);
    fn_110_C45C(composite + 0x180, &third, argument);
    fn_110_C6C4(&fourth, &operation);
    fn_110_C374(composite + 0x138, &fourth, argument);
    fn_110_C6C4(&fifth, &operation);
    fn_110_C28C(composite + 0xF0, &fifth, argument);
    fn_110_C6C4(&sixth, &operation);
    fn_110_C1A4(composite + 0x98, &sixth, argument);
    fn_110_C6C4(&seventh, &operation);
    fn_110_C0BC(composite + 0x64, &seventh, argument);
    fn_110_C6C4(&eighth, &operation);
    fn_110_BFD4(composite + 8, &eighth, argument);
}
