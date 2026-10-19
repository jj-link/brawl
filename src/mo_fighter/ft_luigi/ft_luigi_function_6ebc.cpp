#pragma force_active on
typedef unsigned char u8;

struct Obj {
    char pad[0x24];
};

extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void fn_27_1AB96C(void*, u8);

extern "C" Obj* fn_99_6EBC(Obj* object, short event) {
    fn_27_711E4(object, event, &object[1]);
    fn_27_1AB96C(&object[1], 0);
    return object;
}
