#pragma force_active on
extern "C" void fn_27_19A91C(void* object, int arg1, int arg2);
extern "C" void fn_27_10158(void* destination, void* arg1, int arg2, void* object, int arg4);

extern "C" void* fn_111_781C(void* object, void* arg1, int arg2) {
    fn_27_19A91C(object, 2, 0);
    fn_27_10158(static_cast<unsigned char*>(object) + 0x7C, arg1, arg2, object, 1);
    return object;
}
