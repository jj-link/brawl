#pragma force_active on
extern "C" void __dt__27soCollisionAttackModuleImplFv(void*, short);
extern "C" void* fn_27_1A12AC(void*, short);
extern "C" void* fn_27_CB998(void*, short);
extern "C" void* fn_27_CD1F0(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_106_4948(void* self, short del) {
    if (self) {
        __dt__27soCollisionAttackModuleImplFv((char*)self + 0x61C, -1);
        fn_27_1A12AC((char*)self + 0x540, -1);
        fn_27_CB998((char*)self + 0x2DC, -1);
        fn_27_CD1F0(self, -1);
        if (del > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
