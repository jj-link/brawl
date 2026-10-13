// Execute unwind actions in reverse construction order. The compiler's
// exception_terminate region enforces termination if a cleanup throws.
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long u32;
typedef long s32;
typedef void (*Destructor)(void*, int);
typedef void (*CleanupCall)(void*);

struct FloatingRegister {
    double value;
    float paired[2];
};
struct StackFrame {
    StackFrame* caller;
    u32 return_address;
};
struct UnwindContext {
    FloatingRegister floating[32];
    u32 general[32];
    u32 condition;
    StackFrame* frame;
    u8* action_frame;
    u32 exception_state[3];
    void* exception_object;
    Destructor destroy_exception;
};
struct ExceptionInfo {
    u16* exception_table;
};
struct UnwindIterator {
    u16* exception_table;
    u32 function_start;
    u8* action;
    u32 code_base;
    u32 data_base;
    u32 toc;
    StackFrame* frame;
    void* action_frame;
    void* saved_frame;
};
struct ActionPrefix {
    u8 kind;
    u8 flags;
    s16 offset;
};
struct ObjectAction {
    ActionPrefix header;
    Destructor destroy;
};
struct ConditionalObjectAction {
    ActionPrefix header;
    s16 object_offset;
    u16 padding;
    Destructor destroy;
};
struct ArrayAction {
    ActionPrefix header;
    u16 count;
    u16 stride;
    Destructor destroy;
};
struct BaseAction {
    ActionPrefix header;
    s32 adjustment;
    Destructor destroy;
};
struct ConditionalBaseAction {
    ActionPrefix header;
    s16 pointer_offset;
    u16 padding;
    s32 adjustment;
    Destructor destroy;
};
struct ArrayBaseAction {
    ActionPrefix header;
    s32 adjustment;
    s32 count;
    s32 stride;
    Destructor destroy;
};
struct CallAction {
    ActionPrefix header;
    CleanupCall call;
};
struct ConditionalCallAction {
    ActionPrefix header;
    s16 pointer_offset;
    u16 padding;
    CleanupCall call;
};
struct ExceptionCleanup {
    void* object;
    u32 unused;
    Destructor destroy;
};

extern "C" u32 fn_803F1EC4(UnwindContext*, ExceptionInfo*);
extern "C" void fn_803F1B64(u32, UnwindIterator*);
extern "C" void fn_803F07D4(void);

static inline void* action_pointer(UnwindContext* context, const s16* offset,
                                   u8 flags, int bit) {
    if (bit == 7 ? flags >> 7 : (flags >> bit) & 1) {
        return (void*)context->general[*offset];
    }
    return *(void**)(context->action_frame + *offset);
}
static inline s8 action_byte(UnwindContext* context, const s16* offset, u8 flags) {
    if (flags >> 7) {
        return (s8)context->general[*offset];
    }
    return *(s8*)(context->action_frame + *offset);
}
static inline s16 action_short(UnwindContext* context, const s16* offset, u8 flags) {
    if (flags >> 7) {
        return (s16)context->general[*offset];
    }
    return *(s16*)(context->action_frame + *offset);
}

extern "C" void fn_803F243C(UnwindContext* context, UnwindIterator* iterator,
                            u8* stop) {
    u8* action;
    u8 kind;
    for (;;) {
        action = iterator->action;
        if (action != 0) goto dispatch;
        fn_803F1B64(fn_803F1EC4(context, (ExceptionInfo*)iterator), iterator);
        {
#pragma exception_terminate
            if (iterator->exception_table == 0) {
                fn_803F07D4();
            }
            context->action_frame = ((*iterator->exception_table >> 4) & 1)
                ? (u8*)context->general[31] : (u8*)context->frame;
            continue;
dispatch:
        kind = *action;
        switch (kind & 0x7f) {
        case 1:
            iterator->action = (u8*)iterator->exception_table + *(u16*)(action + 2);
            break;
        case 2: {
            ObjectAction* record = (ObjectAction*)action;
            record->destroy(context->action_frame + record->header.offset, -1);
            iterator->action += 8;
            break;
        }
        case 3: {
            ConditionalObjectAction* record = (ConditionalObjectAction*)action;
            if (action_byte(context, &record->header.offset, record->header.flags)) {
                record->destroy(context->action_frame + record->object_offset, -1);
            }
            iterator->action += 12;
            break;
        }
        case 4: {
            ObjectAction* record = (ObjectAction*)action;
            record->destroy(action_pointer(context, &record->header.offset,
                                          record->header.flags, 7), -1);
            iterator->action += 8;
            break;
        }
        case 5: {
            ArrayAction* record = (ArrayAction*)action;
            int stride;
            int count;
            count = record->count;
            stride = record->stride;
            u8* element = context->action_frame + record->header.offset;
            element += stride * count;
            while (count > 0) {
                element -= stride;
                record->destroy(element, -1);
                --count;
            }
            iterator->action += 12;
            break;
        }
        case 6: {
            BaseAction* record = (BaseAction*)action;
            u8* object = (u8*)action_pointer(context, &record->header.offset,
                                           record->header.flags, 7);
            record->destroy(object + record->adjustment, 0);
            iterator->action += 12;
            break;
        }
        case 7: {
            BaseAction* record = (BaseAction*)action;
            u8* object = (u8*)action_pointer(context, &record->header.offset,
                                           record->header.flags, 7);
            record->destroy(object + record->adjustment, -1);
            iterator->action += 12;
            break;
        }
        case 8: {
            ConditionalBaseAction* record = (ConditionalBaseAction*)action;
            u8* object = (u8*)action_pointer(context, &record->pointer_offset,
                                           record->header.flags, 6);
            if (action_short(context, &record->header.offset, record->header.flags)) {
                record->destroy(object + record->adjustment, 0);
            }
            iterator->action += 16;
            break;
        }
        case 9: {
            ArrayBaseAction* record = (ArrayBaseAction*)action;
            int stride;
            int count;
            u8* element;
            element = (u8*)action_pointer(context, &record->header.offset,
                                         record->header.flags, 7);
            count = record->count;
            stride = record->stride;
            element += record->adjustment;
            element += stride * count;
            while (count > 0) {
                element -= stride;
                record->destroy(element, -1);
                --count;
            }
            iterator->action += 20;
            break;
        }
        case 10: {
            CallAction* record = (CallAction*)action;
            record->call(action_pointer(context, &record->header.offset,
                                        record->header.flags, 7));
            iterator->action += 8;
            break;
        }
        case 11: {
            ConditionalCallAction* record = (ConditionalCallAction*)action;
            void* object = action_pointer(context, &record->pointer_offset,
                                          record->header.flags, 6);
            if (action_byte(context, &record->header.offset, record->header.flags)) {
                record->call(object);
            }
            iterator->action += 12;
            break;
        }
        case 12:
            if (stop == action) return;
            iterator->action = action + 12;
            break;
        case 16:
            if (stop == action) return;
            iterator->action = action + 16;
            break;
        case 13: {
            ActionPrefix* record = (ActionPrefix*)action;
            ExceptionCleanup* cleanup = (ExceptionCleanup*)(context->action_frame + record->offset);
            if (cleanup->destroy) {
                if (context->exception_object == cleanup->object) {
                    context->destroy_exception = cleanup->destroy;
                } else {
                    cleanup->destroy(cleanup->object, -1);
                }
            }
            iterator->action += 4;
            break;
        }
        case 15:
            if (stop == action) return;
            iterator->action = (u8*)(*(u16*)(action + 2) * 4 + (u32)action + 12);
            break;
        default:
            fn_803F07D4();
            break;
        }
        if (kind & 0x80) {
            action = 0;
            iterator->action = action;
        }
        }
    }
}
