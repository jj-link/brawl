#pragma force_active on
namespace {
struct IceClimberTraversalIndex {
    short value;
};
struct IceClimberElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_105_120D8(void*, void*);
void fn_105_12C6C(IceClimberTraversalIndex*, const IceClimberTraversalIndex*);
void fn_105_124AC(void*, const IceClimberTraversalIndex*, void*);
}

extern "C" void fn_105_1241C(void* object, const IceClimberTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<IceClimberElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_105_120D8(element, argument);
        }
    }
    IceClimberTraversalIndex next;
    fn_105_12C6C(&next, operation);
    fn_105_124AC(composite + 4, &next, argument);
}
