#pragma force_active on
namespace {
typedef unsigned char Byte;
struct ZeldaTraversalIndex { short value; };
}

extern "C" {
void fn_104_D4FC(ZeldaTraversalIndex*, const short*);
void fn_104_DC48(ZeldaTraversalIndex*, const ZeldaTraversalIndex*);
void fn_104_DBB0(void*, const ZeldaTraversalIndex*, void*);
void fn_104_DAC8(void*, const ZeldaTraversalIndex*, void*);
void fn_104_D9E0(void*, const ZeldaTraversalIndex*, void*);
void fn_104_D8F8(void*, const ZeldaTraversalIndex*, void*);
void fn_104_D810(void*, const ZeldaTraversalIndex*, void*);
void fn_104_D728(void*, const ZeldaTraversalIndex*, void*);
void fn_104_D640(void*, const ZeldaTraversalIndex*, void*);
void fn_104_D558(void*, const ZeldaTraversalIndex*, void*);
}

extern "C" void fn_104_D2C0(Byte* object, void* argument, const short* index) {
    ZeldaTraversalIndex operation;
    short value = *index;
    ZeldaTraversalIndex second, fourth, sixth, eighth;
    ZeldaTraversalIndex seventh, fifth, third, first;
    fn_104_D4FC(&operation, &value);
    fn_104_DC48(&first, &operation);
    fn_104_DBB0(object + 0x208, &first, argument);
    fn_104_DC48(&second, &operation);
    fn_104_DAC8(object + 0x1CC, &second, argument);
    fn_104_DC48(&third, &operation);
    fn_104_D9E0(object + 0x180, &third, argument);
    fn_104_DC48(&fourth, &operation);
    fn_104_D8F8(object + 0x138, &fourth, argument);
    fn_104_DC48(&fifth, &operation);
    fn_104_D810(object + 0xF0, &fifth, argument);
    fn_104_DC48(&sixth, &operation);
    fn_104_D728(object + 0x98, &sixth, argument);
    fn_104_DC48(&seventh, &operation);
    fn_104_D640(object + 0x64, &seventh, argument);
    fn_104_DC48(&eighth, &operation);
    fn_104_D558(object + 8, &eighth, argument);
}
