// Advance through the runtime's unwind action records and caller frames.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

struct StackFrame {
    struct StackFrame* caller;
    u32 return_address;
};

struct UnwindIterator {
    u16* exception_table;
    u32 function_start;
    u8* action;
    u32 code_base;
    u32 data_base;
    u32 toc;
    struct StackFrame* frame;
    void* action_frame;
    void* saved_frame;
};

extern void fn_803F1B64(u32, struct UnwindIterator*);
extern void fn_803F07D4(void);

u8 fn_803F1D14(struct UnwindIterator* iterator) {
    struct StackFrame* frame;
    u8 kind;
    u16 header;

    for (;;) {
        if (iterator->action == 0 || (*iterator->action & 0x80)) {
            frame = iterator->frame->caller;
            header = *iterator->exception_table;
            if (header >> 11) {
                iterator->saved_frame = *(void**)((u8*)frame - (((header >> 6) & 31) * 8) - 4);
            }
            fn_803F1B64(frame->return_address, iterator);
            if (iterator->exception_table == 0) {
                fn_803F07D4();
            }
            iterator->frame = frame;
            if ((*iterator->exception_table >> 4) & 1) {
                frame = iterator->saved_frame;
            }
            iterator->action_frame = frame;
            if (iterator->action == 0) {
                continue;
            }
        } else {
            switch (*iterator->action) {
            case 2: iterator->action += 8; break;
            case 3: iterator->action += 12; break;
            case 4: iterator->action += 8; break;
            case 5: iterator->action += 12; break;
            case 6:
            case 7: iterator->action += 12; break;
            case 8: iterator->action += 16; break;
            case 9: iterator->action += 20; break;
            case 10: iterator->action += 8; break;
            case 11: iterator->action += 12; break;
            case 12: iterator->action += 12; break;
            case 16: iterator->action += 16; break;
            case 13: iterator->action += 4; break;
            case 15:
                iterator->action += *(u16*)(iterator->action + 2) * 4 + 12;
                break;
            default: fn_803F07D4(); break;
            }
        }
        kind = *iterator->action & 0x7f;
        if (kind == 1) {
            iterator->action = (u8*)iterator->exception_table + *(u16*)(iterator->action + 2);
            kind = *iterator->action & 0x7f;
        }
        return kind;
    }
}
