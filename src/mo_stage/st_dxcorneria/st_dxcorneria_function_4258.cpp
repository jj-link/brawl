#pragma force_active on
struct grMadein;

extern "C" grMadein* fn_82_4258(grMadein* object, int deleteFlag);
extern "C" void __dt__8grMadeinFv(grMadein*, int);
extern "C" void __dl__FPv(void*);

extern "C" grMadein* fn_82_4258(grMadein* object, int deleteFlag)
{
    if (object) {
        __dt__8grMadeinFv(object, 0);
        if (deleteFlag > 0) {
            __dl__FPv(object);
        }
    }
    return object;
}
