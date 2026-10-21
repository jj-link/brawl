#pragma force_active on
namespace {
struct RobotTraversalIndex {
    short value;
};

struct RobotTraversalEntry {
    unsigned char prefix[5];
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool disabled;

    bool isEnabled() const { return enabled; }
};
}

extern "C" {
void fn_120_C4DC(RobotTraversalEntry*, void*);
RobotTraversalIndex* fn_120_CC1C(RobotTraversalIndex*, const RobotTraversalIndex*);
int fn_120_C5BC(void*, const RobotTraversalIndex*, void*);
}

extern "C" void fn_120_C52C(void* object, const RobotTraversalIndex* index, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    RobotTraversalEntry* entry = reinterpret_cast<RobotTraversalEntry*>(composite + 0xC);

    if ((index->value & 1) != 0 && entry->isEnabled() == true && entry->disabled == false)
        fn_120_C4DC(entry, argument);

    RobotTraversalIndex operation;
    fn_120_CC1C(&operation, index);
    fn_120_C5BC(composite + 4, &operation, argument);
}
