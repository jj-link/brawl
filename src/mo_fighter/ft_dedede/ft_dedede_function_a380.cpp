#pragma force_active on
extern "C" void fn_27_1A8014(void*, short, void*, signed char);

extern "C" void fn_117_A380(void* object, short manage_id, int unit_id) {
    fn_27_1A8014(object, manage_id, object, (signed char)unit_id);
}
