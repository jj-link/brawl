#pragma force_active on
void operator delete(void*);
extern "C" void* __dt__17soModelModuleImplFv(void*, short);
extern "C" void* fn_94_69AC(void* self, short arg2);
extern "C" void* fn_27_19A83C(void* member, short deleteFlag);

extern "C" void* fn_94_6934(void* self, short deleting) {
    if (self != 0) {
        __dt__17soModelModuleImplFv(static_cast<char*>(self) + 0x1f4, -1);
        fn_94_69AC(static_cast<char*>(self) + 0x1ac, -1);
        fn_27_19A83C(self, -1);
        if (deleting > 0) {
            operator delete(self);
        }
    }
    return self;
}
