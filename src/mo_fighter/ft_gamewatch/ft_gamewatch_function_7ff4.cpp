#pragma force_active on
void operator delete(void*);

extern "C" {
void* fn_27_13C90(void*, short);
void* fn_27_21038(void*, short);
void* fn_107_46D0(void*, short);
void* fn_107_80A8(void*, short);
void* fn_107_8114(void*, short);
void* fn_107_8170(void*, short);
void* fn_107_81CC(void*, short);
void* fn_107_8228(void*, short);
}

extern "C" void* fn_107_7FF4(void* object, short deleting) {
    if (object != 0) {
        unsigned char* p = static_cast<unsigned char*>(object);
        fn_27_13C90(p + 0x224, -1);
        fn_107_80A8(p + 0x1E8, -1);
        fn_27_21038(p + 0x1D8, -1);
        fn_107_8114(p + 0x1B8, -1);
        fn_107_8170(p + 0x198, -1);
        fn_107_46D0(p + 0x160, -1);
        fn_107_81CC(p + 0xC4, -1);
        fn_107_8228(object, -1);
        if (deleting > 0) {
            operator delete(object);
        }
    }
    return object;
}
