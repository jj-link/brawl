struct soLinkEventArgs;
class soModuleAccesser;
class StageObject;

extern "C" void fn_27_1DB0F0(void*, soLinkEventArgs*, soModuleAccesser*, StageObject*, int);

// Recover the complete object from its link-event observer interface.
extern "C" void fn_99_10C5C(void* object, soLinkEventArgs* event,
                             soModuleAccesser* accesser, StageObject* target, int argument) {
    fn_27_1DB0F0(static_cast<unsigned char*>(object) - 0x54,
                event, accesser, target, argument);
}
