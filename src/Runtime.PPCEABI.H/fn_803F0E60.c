// Adjust an object pointer and copy the remaining member-call descriptor.
typedef unsigned long u32;
struct MemberCall {
    u32 object_delta;
    u32 vtable_offset;
    u32 function;
};

struct MemberCall* fn_803F0E60(void* object, const struct MemberCall* member, struct MemberCall* adjusted) {
    adjusted->object_delta = member->object_delta + (u32)object;
    adjusted->vtable_offset = member->vtable_offset;
    adjusted->function = member->function;
    return adjusted;
}
