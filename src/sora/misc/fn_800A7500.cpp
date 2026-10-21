#pragma force_active on
extern "C" void fn_800A7528(unsigned char* obj);
extern "C" void fn_800A85AC(unsigned char* obj);

extern "C" void fn_800A7500(unsigned char* obj)
{
    switch (*(int*)(obj + 0xc)) {
    case 0:
        fn_800A7528(obj);
        break;
    case 1:
        fn_800A85AC(obj);
        break;
    }
}
