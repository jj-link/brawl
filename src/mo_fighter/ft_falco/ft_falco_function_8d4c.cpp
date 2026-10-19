#pragma force_active on
struct Object {
    unsigned char pad[0x24];
};

extern "C" void fn_27_711E4(void*, short, void*);
extern "C" void* fn_27_1AB96C(void*, unsigned char);

extern "C" Object* fn_108_8D4C(Object* obj, short event) {
    fn_27_711E4(obj, event, obj->pad + 0x24);
    fn_27_1AB96C(obj->pad + 0x24, 0);
    return obj;
}
