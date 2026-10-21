#pragma force_active on
namespace {
struct RobotTraversalIndex {
    short value;
};

struct RobotElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_120_C964(void*, void*);
void fn_120_CC1C(RobotTraversalIndex*, const RobotTraversalIndex*);
void fn_120_CA44(void*, const RobotTraversalIndex*, void*);
}

extern "C" void fn_120_C9B4(void* object, const RobotTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<RobotElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_120_C964(element, argument);
        }
    }
    RobotTraversalIndex next;
    fn_120_CC1C(&next, operation);
    fn_120_CA44(composite + 4, &next, argument);
}
