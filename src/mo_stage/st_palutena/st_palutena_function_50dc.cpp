#pragma force_active on
struct PalutenaField {
    unsigned int pad[2];
    unsigned int low : 2;
    unsigned int field : 2;
};

extern "C" void fn_67_50DC(PalutenaField* p, unsigned int value)
{
    p->field = value;
}
