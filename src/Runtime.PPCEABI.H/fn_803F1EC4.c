// Recover the caller's saved register values while advancing an unwind context.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct FloatingRegister {
    double value;
    float paired[2];
};

struct StackFrame {
    struct StackFrame* caller;
    u32 return_address;
};

struct UnwindContext {
    struct FloatingRegister floating[32];
    u32 general[32];
    u32 condition;
    struct StackFrame* frame;
};

struct ExceptionInfo {
    u16* exception_table;
};

u32 fn_803F1EC4(struct UnwindContext* context, struct ExceptionInfo* info) {
    struct StackFrame* caller;
    u8* saved;
    int count;
    int paired;
    int destination;
    int source;

    caller = context->frame->caller;
    paired = (*info->exception_table >> 1) & 1;
    count = (*info->exception_table >> 6) & 31;
    if (paired) {
        saved = (u8*)caller - count * 16;
    } else {
        saved = (u8*)caller - count * 8;
    }
    if (paired) {
        for (destination = 32 - count, source = 0; destination < 32; destination++, source++) {
            context->floating[destination].paired[0] = ((struct FloatingRegister*)saved)[source].paired[0];
            context->floating[destination].paired[1] = ((struct FloatingRegister*)saved)[source].paired[1];
            context->floating[destination].value = ((struct FloatingRegister*)saved)[source].value;
        }
    } else {
        for (destination = 32 - count, source = 0; destination < 32; destination++, source++) {
            context->floating[destination].value = ((double*)saved)[source];
        }
    }
    count = *info->exception_table >> 11;
    saved -= count * 4;
    for (destination = 32 - count, source = 0; destination < 32; destination++, source++) {
        context->general[destination] = ((u32*)saved)[source];
    }
    context->frame = caller;
    return caller->return_address;
}
