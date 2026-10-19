#pragma force_active on
extern "C" void fn_41_69BF0(void*, short);
extern "C" void fn_41_695E0(void*, short);

extern "C" void* fn_41_6964C(void* self, short doDelete) {
    if (self != 0) {
        fn_41_69BF0((char*)self + 0x158, -1);
        fn_41_695E0((char*)self + 4, -1);
        if (doDelete > 0) {
            operator delete(self);
        }
    }
    return self;
}
