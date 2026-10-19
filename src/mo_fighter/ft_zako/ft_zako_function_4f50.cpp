#pragma force_active on
extern "C" {
void* __dt__16soHeapModuleImplFv(void*, short);
void __dl__FPv(void*);

void* fn_126_4F50(void* p1, short p2)
{
    if (p1 != 0) {
        __dt__16soHeapModuleImplFv(p1, -1);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
}
