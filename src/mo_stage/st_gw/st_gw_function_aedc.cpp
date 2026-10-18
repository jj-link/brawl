#pragma force_active on
struct Fn63AEDCFields
{
    unsigned int : 4;
    unsigned int field : 2;
    unsigned int : 26;
};

extern "C" void fn_63_AEDC(Fn63AEDCFields *p, unsigned int value)
{
    p[2].field = value;
}
