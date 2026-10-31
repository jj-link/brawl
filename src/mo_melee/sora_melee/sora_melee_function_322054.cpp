#pragma force_active on
struct soLinkEventArgs;
struct soModuleAccesser;
struct StageObject;
extern "C" void fn_27_1DB0F0(void*, soLinkEventArgs*, soModuleAccesser*, StageObject*, int);

extern "C" void fn_27_322054(void* self, soLinkEventArgs* args, soModuleAccesser* accesser, StageObject* object, int value)
{
    switch (*reinterpret_cast<int*>(args)) {
    case 0x838:
        return;
    default:
        break;
    }
    fn_27_1DB0F0(self, args, accesser, object, value);
}
