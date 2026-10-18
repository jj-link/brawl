#pragma force_active on
extern "C" {
void fn_27_19A91C(void*, int, int);
void fn_27_10158(void*, void*, int, void*, int);

void* fn_98_8FF0(void* object, void* arg, int value) {
    fn_27_19A91C(object, 2, 0);
    fn_27_10158(static_cast<char*>(object) + 0x7C, arg, value, object, 1);
    return object;
}
}
