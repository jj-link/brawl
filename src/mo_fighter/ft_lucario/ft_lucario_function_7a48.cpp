#pragma force_active on
extern "C" void fn_27_711E4(void* a, short b, void* c);
extern "C" void* fn_27_1AB96C(void* o, unsigned char c);

struct Obj {
    unsigned char pad[0x24];
    unsigned char sub;
};

extern "C" void* fn_118_7A48(Obj* object, short event) {
    fn_27_711E4(object, event, &object->sub);
    fn_27_1AB96C(&object->sub, 0);
    return object;
}
