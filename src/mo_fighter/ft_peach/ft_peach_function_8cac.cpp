#pragma force_active on
extern "C" void fn_27_19A91C(void* object, int arg, int value);
extern "C" void fn_27_10158(void* member, void* arg, int value, void* object, int flag);

extern "C" void* fn_103_8CAC(void* object, void* arg, int value) {
    fn_27_19A91C(object, 2, 0);
    fn_27_10158(static_cast<unsigned char*>(object) + 0x7C, arg, value, object, 1);
    return object;
}
