#pragma force_active on
extern "C" {
struct MarioCommonData { unsigned char data[0x40]; };
struct MarioCommonObject { void* vtable; };
extern MarioCommonData lbl_91_data_9FE8;
MarioCommonObject* fn_91_194CC(MarioCommonObject* object) {
    object->vtable = &lbl_91_data_9FE8;
    return object;
}
}