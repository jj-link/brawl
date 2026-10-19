#pragma force_active on
extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void* fn_27_1AB96C(void*, unsigned char);

struct Obj {
    char pad[0x24];
    char sub[1];
};

extern "C" void* fn_117_75B4(Obj* object, int arg) {
    fn_27_711E4(object, (short)arg, object->sub);
    fn_27_1AB96C(object->sub, 0);
    return object;
}
