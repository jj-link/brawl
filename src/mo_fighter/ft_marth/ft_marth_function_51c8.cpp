#pragma force_active on
extern "C" {
extern void* __dt__16soHeapModuleImplFv(void*, short);
extern void __dl__FPv(void*);

void* fn_106_51C8(void* self, short flag)
{
    if (self != 0) {
        __dt__16soHeapModuleImplFv(self, -1);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
