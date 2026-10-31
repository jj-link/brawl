#pragma force_active on
extern "C" {

void fn_95_1032C(void* fighter);

void fn_95_12134(int a, void* obj, int id)
{
    if (id == 0x113 || (unsigned)(id - 0x119) <= 3) {
        fn_95_1032C(obj);
    }
}

}