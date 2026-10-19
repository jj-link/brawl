#pragma force_active on
extern "C" void fn_41_49F40(void* self, short p2);
extern "C" void fn_41_49E40(void* self, short p2);

void operator delete(void* p);

extern "C" void* fn_41_49FA0(void* self, short p2) {
    if (self != 0) {
        fn_41_49F40((char*)self + 0x68, -1);
        fn_41_49E40((char*)self + 4, -1);
        if (p2 > 0) {
            operator delete(self);
        }
    }
    return self;
}
