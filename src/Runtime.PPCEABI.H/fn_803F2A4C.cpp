typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned long u32;

struct FloatingRegister { double value; float paired[2]; };
struct StackFrame { StackFrame* caller; u32 return_address; };
struct ExceptionInfo {
    u16* exception_table;
    u32 function_start;
    u8* action;
    u32 code_base;
    u32 data_base;
    u32 toc;
};
struct UnwindIterator {
    ExceptionInfo info;
    StackFrame* frame;
    u8* action_frame;
    u8* saved_frame;
};
struct ExceptionRecord {
    void* object;
    const char* type;
    void (*destroy)(void*, int);
    void* caught;
    void* pointer_storage;
    u8* action;
};
struct UnwindContext {
    FloatingRegister floating[32];
    u32 general[32];
    u32 condition;
    StackFrame* frame;
    u8* action_frame;
    u8* saved_frame;
    u32 program_counter;
    const char* thrown_type;
    void* exception_object;
    void (*destroy_exception)(void*, int);
    ExceptionRecord* rethrow_record;
};

extern "C" void fn_803F1B64(u32, ExceptionInfo*);
extern "C" void fn_803F07D4(void);
extern "C" u32 fn_803F1D14(UnwindIterator*);
extern "C" int fn_803F07E0(const char*, const char*, int*);
extern "C" void fn_803F243C(UnwindContext*, ExceptionInfo*, u8*);
extern "C" void fn_803F2948(UnwindContext*, u32 toc, u32 continuation);

static inline u32 InitializeIterator(UnwindIterator* iterator,
                                    const ExceptionInfo* info,
                                    UnwindContext* context) {
    iterator->info = *info;
    u8* action = iterator->info.action;
    iterator->frame = context->frame;
    iterator->action_frame = context->action_frame;
    iterator->saved_frame = (u8*)context->general[31];
    return action == 0 ? 0 : *action & 0x7f;
}

static inline void InitializeRecord(ExceptionRecord* record,
                                    UnwindContext* context) {
    record->object = context->exception_object;
    record->type = context->thrown_type;
    record->destroy = context->destroy_exception;
}

static inline void SetCaughtObject(ExceptionRecord* record,
                                   UnwindContext* context, const int* adjustment) {
    if (*context->thrown_type == '*') {
        record->caught = &record->pointer_storage;
        record->pointer_storage = (u8*)*(void**)context->exception_object + *adjustment;
    } else {
        record->caught = (u8*)context->exception_object + *adjustment;
    }
}

extern "C" void fn_803F2A4C(UnwindContext* context) {
    ExceptionInfo info;
    UnwindIterator iterator;
    int catch_adjustment;
    int specification_adjustment;
    const char* thrown;
    u8* specification;
    int i;
    u8* failure_action;
    u8* type;
    u32 kind;
    u8* action;
    ExceptionRecord* record;

    fn_803F1B64(context->program_counter, &info);
    if (info.exception_table == 0) fn_803F07D4();
    context->action_frame = ((*info.exception_table >> 4) & 1) ?
        (u8*)context->general[31] : (u8*)context->frame;
    if (context->thrown_type == 0) {
        u32 kind = InitializeIterator(&iterator, &info, context);
        for (;;) {
            switch ((u8)kind) {
            default: fn_803F07D4(); break;
            case 13: break;
            case 0: case 2: case 3: case 4: case 5: case 6: case 7:
            case 8: case 9: case 10: case 11: case 12: case 15: case 16:
                kind = fn_803F1D14(&iterator);
                continue;
            }
            break;
        }
        record = (ExceptionRecord*)(iterator.action_frame + *(s16*)(iterator.info.action + 2));
        context->thrown_type = record->type;
        context->exception_object = record->object;
        context->destroy_exception = 0;
        context->rethrow_record = record;
    } else {
        context->rethrow_record = 0;
    }
    kind = InitializeIterator(&iterator, &info, context);
    for (;;) {
        switch ((u8)kind) {
        case 16:
            if (!(s8)fn_803F07E0(context->thrown_type,
                    *(const char**)(iterator.info.action + 4), &catch_adjustment)) {
                break;
            } else goto found;
        case 12:
            if (!(s8)fn_803F07E0(context->thrown_type,
                    *(const char**)(iterator.info.action + 4), &catch_adjustment)) {
                break;
            } else goto found;
        case 15: {
            specification = iterator.info.action;
            thrown = context->thrown_type;
            int matched;
            type = specification;
            for (i = 0; i < *(u16*)(specification + 2); type += 4, ++i) {
                if ((s8)fn_803F07E0(thrown, *(const char**)(type + 12), &specification_adjustment)) {
                    matched = 1;
                    goto specification_checked;
                }
            }
            matched = 0;
specification_checked:
            if (!matched) {
                failure_action = iterator.info.action;
                // A throw during exception-specification failure handling terminates.
#pragma exception_terminate
                {
                    fn_803F243C(context, &info, failure_action);
                    record = (ExceptionRecord*)(context->action_frame + *(int*)(failure_action + 8));
                    InitializeRecord(record, context);
                    record->action = failure_action;
                    fn_803F2948(context, info.toc, info.function_start + *(u32*)(failure_action + 4));
                }
            }
            break;
        }
        case 0: case 2: case 3: case 4: case 5: case 6: case 7:
        case 8: case 9: case 10: case 11: case 13:
            break;
        default:
            fn_803F07D4();
            goto found;
        }
        kind = fn_803F1D14(&iterator);
    }
found:
    if ((u8)kind == 16) {
        action = iterator.info.action;
        fn_803F243C(context, &info, action);
        record = (ExceptionRecord*)(context->action_frame + *(int*)(action + 12));
        InitializeRecord(record, context);
        SetCaughtObject(record, context, &catch_adjustment);
        fn_803F2948(context, info.toc, info.function_start + *(u32*)(action + 8));
    } else {
        action = iterator.info.action;
        fn_803F243C(context, &info, action);
        record = (ExceptionRecord*)(context->action_frame + *(s16*)(action + 10));
        InitializeRecord(record, context);
        SetCaughtObject(record, context, &catch_adjustment);
        fn_803F2948(context, info.toc, info.function_start + *(u16*)(action + 8));
    }
}
