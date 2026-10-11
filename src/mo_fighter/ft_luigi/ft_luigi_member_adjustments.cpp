class soModuleAccesser;
class BaseItem;

extern "C" void fn_27_13C428(void*, BaseItem*, int, int, void*);
extern "C" void fn_27_13BDCC(void*, BaseItem*, int, void*);
extern "C" void fn_27_13BB54(void*, BaseItem*, int);
extern "C" void fn_27_13B998(void*, int);
extern "C" void fn_27_13B96C(void*);
extern "C" void fn_27_13B5AC(void*, BaseItem*, int, bool*);
extern "C" bool fn_27_13ACC4(void*, BaseItem*, void*, void*);
extern "C" void fn_27_13A89C(void*, BaseItem*, void*, int, int, int);
extern "C" void fn_27_13A4A0(void*, int, BaseItem*, void*, int, int);
extern "C" void fn_27_13A418(void*, BaseItem*, int*);
extern "C" void fn_27_1362E4(void*, void*, soModuleAccesser*);
extern "C" void fn_27_13604C(void*, void*, void*, soModuleAccesser*);
extern "C" void fn_27_13DD00(void*, unsigned long, float);
extern "C" void fn_27_13C7D0(void*);
extern "C" void fn_27_13CAF8(void*);
extern "C" void fn_27_13C724(void*, float);
extern "C" void fn_27_136528(void*, soModuleAccesser*, float, float);

extern "C" void fn_99_BB48(void* object, BaseItem* item, int kind,
                          int active, void* context) {
    fn_27_13C428(static_cast<unsigned char*>(object) - 0xd0,
                 item, kind, active, context);
}

extern "C" void fn_99_BB50(void* object, BaseItem* item, int kind, void* context) {
    fn_27_13BDCC(static_cast<unsigned char*>(object) - 0xd0, item, kind, context);
}

extern "C" void fn_99_BB58(void* object, BaseItem* item, int kind) {
    fn_27_13BB54(static_cast<unsigned char*>(object) - 0xd0, item, kind);
}

extern "C" void fn_99_BB60(void* object, int kind) {
    fn_27_13B998(static_cast<unsigned char*>(object) - 0xd0, kind);
}

extern "C" void fn_99_BB68(void* object) {
    fn_27_13B96C(static_cast<unsigned char*>(object) - 0xd0);
}

extern "C" void fn_99_BB70(void* object, BaseItem* item, int kind, bool* result) {
    fn_27_13B5AC(static_cast<unsigned char*>(object) - 0xd0, item, kind, result);
}

extern "C" bool fn_99_BB78(void* object, BaseItem* item, void* first, void* second) {
    return fn_27_13ACC4(static_cast<unsigned char*>(object) - 0xd0,
                        item, first, second);
}

extern "C" void fn_99_BB80(void* object, BaseItem* item, void* context,
                          int first, int second, int third) {
    fn_27_13A89C(static_cast<unsigned char*>(object) - 0xd0,
                 item, context, first, second, third);
}

extern "C" void fn_99_BB88(void* object, int kind, BaseItem* item,
                          void* context, int first, int second) {
    fn_27_13A4A0(static_cast<unsigned char*>(object) - 0xd0,
                 kind, item, context, first, second);
}

extern "C" void fn_99_BB90(void* object, BaseItem* item, int* kind) {
    fn_27_13A418(static_cast<unsigned char*>(object) - 0xd0, item, kind);
}

extern "C" void fn_99_BB98(void* object, void* info, soModuleAccesser* accesser) {
    fn_27_1362E4(static_cast<unsigned char*>(object) - 0xe8, info, accesser);
}

extern "C" void fn_99_BBA0(void* object, void* info, void* context,
                          soModuleAccesser* accesser) {
    fn_27_13604C(static_cast<unsigned char*>(object) - 0xe8, info, context, accesser);
}

extern "C" void fn_99_BBA8(void* object, unsigned long kind, float value) {
    fn_27_13DD00(static_cast<unsigned char*>(object) - 0xf4, kind, value);
}

extern "C" void fn_99_BBB0(void* object) {
    fn_27_13C7D0(static_cast<unsigned char*>(object) - 0xf4);
}

extern "C" void fn_99_BBB8(void* object) {
    fn_27_13CAF8(static_cast<unsigned char*>(object) - 0xf4);
}

extern "C" void fn_99_BBC0(void* object, float value) {
    fn_27_13C724(static_cast<unsigned char*>(object) - 0xf4, value);
}

extern "C" void fn_99_BBC8(void* object, soModuleAccesser* accesser,
                          float first, float second) {
    fn_27_136528(static_cast<unsigned char*>(object) - 0x100, accesser, first, second);
}
