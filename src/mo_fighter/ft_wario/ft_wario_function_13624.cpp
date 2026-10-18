#pragma force_active on
namespace {
struct WarioTraversalIndex {
    short value;
};
}

extern "C" {
void fn_110_137C4(WarioTraversalIndex*, const short*);
void fn_110_13A28(WarioTraversalIndex*, const WarioTraversalIndex*);
void fn_110_13998(void*, const WarioTraversalIndex*, void*);
void fn_110_138E8(void*, const WarioTraversalIndex*, void*);
void fn_110_13838(void*, const WarioTraversalIndex*, void*);
}

extern "C" void fn_110_13624(void* object, void* argument, const short* index) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    WarioTraversalIndex operation;
    short value = *index;
    WarioTraversalIndex second;
    WarioTraversalIndex third;
    WarioTraversalIndex first;

    fn_110_137C4(&operation, &value);
    fn_110_13A28(&first, &operation);
    fn_110_13998(composite + 0x68, &first, argument);
    fn_110_13A28(&second, &operation);
    fn_110_138E8(composite + 0x48, &second, argument);
    fn_110_13A28(&third, &operation);
    fn_110_13838(composite + 0x8, &third, argument);
}
