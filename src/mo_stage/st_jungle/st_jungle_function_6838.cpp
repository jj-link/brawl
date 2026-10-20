#pragma force_active on
struct UnkStruct {
    unsigned int pad[2];
    unsigned int f0 : 8;
    unsigned int f1 : 4;
    unsigned int f2 : 20;
};

extern "C" void fn_51_6838(UnkStruct *arg0, unsigned int arg1)
{
    arg0->f1 = arg1;
}
