#pragma force_active on
struct soLinkEventArgs { int type; };
struct soModuleAccesser;
struct StageObject;
extern "C" void fn_27_1DB0F0(void*, soLinkEventArgs*, soModuleAccesser*, StageObject*, int);
extern "C" void fn_27_3C98BC(void* self, soLinkEventArgs* args, soModuleAccesser* accesser, StageObject* object, int value) {
    switch (args->type) {
    case 0x838:
        return;
    default:
        break;
    }
    fn_27_1DB0F0(self, args, accesser, object, value);
}