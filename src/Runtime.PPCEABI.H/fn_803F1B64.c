// Resolve a code address to its exception table and active unwind action.
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

struct ExceptionIndex {
    u32 start;
    u32 size_flags;
    u32 table;
};

struct FragmentInfo {
    struct ExceptionIndex* first;
    struct ExceptionIndex* last;
    union {
        u32 address;
        u8* pointer;
    } code_base;
    u32 unknown_c;
    u8* data_base;
    u32 unknown_14;
    u32 toc;
    int active;
};

struct WideActionRange {
    u32 start;
    u16 length;
    u16 action;
};

struct ShortActionRange {
    u16 start;
    u16 end;
    u16 action;
};

extern int fn_803F1ADC(u32, void*);

void fn_803F1B64(u32 address, struct UnwindIterator* iterator) {
    struct FragmentInfo fragment;
    struct ExceptionIndex* entries;
    struct ExceptionIndex* entry;
    int low, mid, high;
    u32 key;
    u8* table;

    iterator->exception_table = 0;
    iterator->action = 0;
    if (fn_803F1ADC(address, &fragment) == 0) return;
    iterator->code_base = fragment.code_base.address;
    iterator->data_base = (u32)fragment.data_base;
    iterator->toc = fragment.toc;
    entries = fragment.first;
    low = 0;
    key = (u8*)address - fragment.code_base.pointer;
    high = fragment.last - entries;
    for (;;) {
        if (low > high) return;
        mid = (low + high) / 2;
        entry = &entries[mid];
        if (key < entry->start) {
            high = mid - 1;
            continue;
        } else if (key > entry->start + (entry->size_flags & 0x7fffffff)) {
            low = mid + 1;
            continue;
        } else {
            iterator->function_start = fragment.code_base.address + entry->start;
            if (entry->size_flags >> 31) {
                table = (u8*)&entry->table;
            } else {
                table = (u8*)(fragment.data_base + entry->table);
            }
            iterator->exception_table = (u16*)table;
            key -= entry->start;
            if ((*(u16*)table >> 3) & 1) {
                u32 start;
                struct WideActionRange* range = (struct WideActionRange*)(table + 4);
                while ((start = range->start) != 0) {
                    u32 end = start + (range->length << 2);
                    if (start <= key && end >= key) {
                        iterator->action = table + range->action;
                        break;
                    }
                    range++;
                }
            } else {
                u32 start;
                struct ShortActionRange* range = (struct ShortActionRange*)(table + 2);
                while ((start = range->start) != 0) {
                    if (start <= key && range->end >= key) {
                        iterator->action = table + range->action;
                        break;
                    }
                    range++;
                }
            }
            return;
        }
    }
}
