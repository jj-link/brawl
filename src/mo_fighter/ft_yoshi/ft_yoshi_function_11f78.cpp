#pragma force_active on
extern "C" {
void fn_95_FF04(void* object);
void fn_95_100C4(void* object);

void fn_95_11F78(void* unused, void* object) {
    fn_95_FF04(object);
    fn_95_100C4(object);
}
}
