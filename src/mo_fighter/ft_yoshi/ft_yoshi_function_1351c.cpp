#pragma force_active on
extern "C" void fn_95_1032C(void*);

extern "C" void fn_95_1351C(void* r3, void* obj, int id)
{
    if (id == 0x113 || (unsigned int)(id - 0x119) <= 3) {
        fn_95_1032C(obj);
    }
}
