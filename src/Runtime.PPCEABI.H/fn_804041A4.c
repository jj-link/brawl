typedef unsigned long u32;
typedef unsigned long long u64;

struct TRKMessageBuffer;
struct TRKExceptionStatus {
    u32 words[3];
    unsigned char flags;
    unsigned char detected;
    unsigned short reserved;
};
struct TRKRegisterProgram { u32 words[10]; };

extern struct TRKExceptionStatus gTRKExceptionStatus_804947AC;
extern struct {
    unsigned char default_registers[0x1a8];
    u32 extended_registers[97];
} gTRKCPUState;
extern unsigned char gTRKRestoreFlags[];
extern unsigned char lbl_8059BEB4[];
extern const struct TRKRegisterProgram lbl_804204F0;
extern const struct TRKRegisterProgram lbl_80420518;
extern const struct TRKRegisterProgram lbl_80420540;
extern void TRK_flush_cache(void* address, u32 length);
extern int fn_8040163C(struct TRKMessageBuffer* buffer, u64 value);
extern int fn_804013F0(struct TRKMessageBuffer* buffer, u64* value);
extern int fn_804014D8(struct TRKMessageBuffer* buffer, const u32* values, int count);
extern int fn_80401268(struct TRKMessageBuffer* buffer, u32* values, int count);
extern u32 fn_80403770(void);
extern void fn_80403778(u32 value);
extern void fn_80403B04(u64* value);
extern void fn_80403B28(u64* value);

/* These templates are executable register-access programs in the original
   debugger. Patch their register fields, synchronize caches, and invoke them
   with the debugger's shared scratch area. */
static inline void TRKExecuteRegisterProgram(struct TRKRegisterProgram* program,
                                             void* value) {
    TRK_flush_cache(program, sizeof(*program));
    ((void (*)(void*, void*))program)(value, lbl_8059BEB4);
}

static inline u64 TRKLowWord(u64 value) {
    return value & 0xffffffff;
}

int fn_804041A4(u32 first, u32 last, struct TRKMessageBuffer* buffer,
                u32* transferred, int read) {
    struct TRKRegisterProgram read_control, write_control, clear_control;
    struct TRKRegisterProgram read_register, write_register;
    u32 register_field;
    struct TRKRegisterProgram* read_program;
    struct TRKRegisterProgram* write_program;
    struct TRKExceptionStatus saved;
    struct { u32 high, low; } value;
    u32 control;
    struct TRKExceptionStatus* status;
    u32 instruction;
    u32 index = first;
    int result;

    if (last > 31) return 0x701;
    status = &gTRKExceptionStatus_804947AC;
    saved = *status;
    status->detected = 0;
    read_control = lbl_804204F0;
    read_control.words[0] = 0x7c98e2a6;
    read_control.words[1] = 0x90830000;
    read_control.words[9] = 0x4e800020;
    TRKExecuteRegisterProgram(&read_control, &control);
    control |= 0xa0000000;
    write_control = lbl_804204F0;
    write_control.words[0] = 0x80830000;
    write_control.words[1] = 0x7c98e3a6;
    write_control.words[9] = 0x4e800020;
    TRKExecuteRegisterProgram(&write_control, &control);
    control = 0;
    clear_control = lbl_804204F0;
    clear_control.words[0] = 0x80830000;
    clear_control.words[1] = 0x7c90e3a6;
    clear_control.words[9] = 0x4e800020;
    TRKExecuteRegisterProgram(&clear_control, &control);
    *transferred = 0;
    register_field = index << 21;
    read_program = &read_register;
    write_program = &write_register;
    result = 0;
    while (index <= last && result == 0) {
        if (read) {
            read_register = lbl_80420518;
            if (read) instruction = register_field | 0xf0030000;
            else instruction = register_field | 0xe0030000;
            read_register.words[0] = instruction;
            read_register.words[9] = 0x4e800020;
            TRK_flush_cache(read_program, sizeof(read_register));
            ((void (*)(void*, void*))&read_register)(&value, lbl_8059BEB4);
            result = fn_8040163C(buffer, *(u64*)&value);
        } else {
            fn_804013F0(buffer, (u64*)&value);
            write_register = lbl_80420518;
            if (read) instruction = register_field | 0xf0030000;
            else instruction = register_field | 0xe0030000;
            write_register.words[0] = instruction;
            write_register.words[9] = 0x4e800020;
            TRK_flush_cache(write_program, sizeof(write_register));
            ((void (*)(void*, void*))&write_register)(&value, lbl_8059BEB4);
            result = 0;
        }
        register_field += 1UL << 21;
        ++index;
        *transferred += 8;
    }
    if (status->detected != 0U) {
        *transferred = 0;
        result = 0x702;
    }
    gTRKExceptionStatus_804947AC = saved;
    return result;
}

int fn_804045DC(u32 first, u32 last, struct TRKMessageBuffer* buffer,
                u32* transferred, int read) {
    struct TRKExceptionStatus saved;
    struct TRKExceptionStatus* status;
    int count;
    u32* registers;
    int result = first;

    if (last > 96) return 0x701;
    status = &gTRKExceptionStatus_804947AC;
    saved = *status;
    status->detected = 0;
    *transferred = 0;
    if (first <= last) {
        count = last - first + 1;
        registers = &gTRKCPUState.extended_registers[first];
        *transferred += count * sizeof(u32);
        if (read) result = fn_804014D8(buffer, registers, count);
        else {
            if (registers <= &gTRKCPUState.extended_registers[17] &&
                registers + count - 1 >= &gTRKCPUState.extended_registers[16])
                gTRKRestoreFlags[0] = 1;
            if (registers <= &gTRKCPUState.extended_registers[52] &&
                registers + count - 1 >= &gTRKCPUState.extended_registers[52])
                gTRKRestoreFlags[1] = 1;
            result = fn_80401268(buffer, registers, count);
        }
    }
    if (status->detected != 0U) {
        *transferred = 0;
        result = 0x702;
    }
    gTRKExceptionStatus_804947AC = saved;
    return result;
}

int fn_8040474C(u32 first, u32 last, struct TRKMessageBuffer* buffer,
                u32* transferred, int read) {
    struct TRKRegisterProgram read_register, write_register;
    struct TRKRegisterProgram read_control, write_control;
    u32 register_field;
    struct TRKRegisterProgram *read_program, *read_control_program;
    struct TRKRegisterProgram *write_program, *write_control_program;
    struct TRKExceptionStatus saved;
    u64 value;
    struct TRKExceptionStatus* status;
    u32 index, instruction;
    int result;

    if (last > 33) return 0x701;
    status = &gTRKExceptionStatus_804947AC;
    saved = *status;
    status->detected = 0;
    fn_80403778(fn_80403770() | 0x2000);
    *transferred = 0;
    index = first;
    register_field = first << 21;
    read_program = &read_register;
    read_control_program = &read_control;
    write_program = &write_register;
    write_control_program = &write_control;
    result = 0;
    while (index <= last && result == 0) {
        if (read) {
            read_register = lbl_80420540;
            if (index < 32) {
                if (read) instruction = register_field | 0xd8030000;
                else instruction = register_field | 0xc8030000;
                read_register.words[0] = instruction;
                read_register.words[9] = 0x4e800020;
                TRK_flush_cache(read_program, sizeof(read_register));
                ((void (*)(void*, void*))&read_register)(&value, lbl_8059BEB4);
            } else if (index == 32) {
                if (read) fn_80403B04(&value);
                else fn_80403B28(&value);
                value = TRKLowWord(value);
            } else if (index == 33) {
                if (!read) *(u32*)&value = ((u32*)&value)[1];
                read_control = lbl_804204F0;
                if (read) {
                    read_control.words[0] = 0x7c9efaa6;
                    read_control.words[1] = 0x90830000;
                } else {
                    read_control.words[0] = 0x80830000;
                    read_control.words[1] = 0x7c9efba6;
                }
                read_control.words[9] = 0x4e800020;
                TRK_flush_cache(read_control_program, sizeof(read_control));
                ((void (*)(void*, void*))&read_control)(&value, lbl_8059BEB4);
                if (read) value = TRKLowWord(*(u32*)&value);
            }
            result = fn_8040163C(buffer, value);
        } else {
            u32 write_result;
            fn_804013F0(buffer, &value);
            write_register = lbl_80420540;
            write_result = 0;
            if (index < 32) {
                if (read) instruction = register_field | 0xd8030000;
                else instruction = register_field | 0xc8030000;
                write_register.words[0] = instruction;
                write_register.words[9] = 0x4e800020;
                TRK_flush_cache(write_program, sizeof(write_register));
                ((void (*)(void*, void*))&write_register)(&value, lbl_8059BEB4);
                write_result = 0;
            } else if (index == 32) {
                if (read) fn_80403B04(&value);
                else fn_80403B28(&value);
                value = TRKLowWord(value);
            } else if (index == 33) {
                if (!read) *(u32*)&value = ((u32*)&value)[1];
                write_control = lbl_804204F0;
                if (read) {
                    write_control.words[0] = 0x7c9efaa6;
                    write_control.words[1] = 0x90830000;
                } else {
                    write_control.words[0] = 0x80830000;
                    write_control.words[1] = 0x7c9efba6;
                }
                write_control.words[9] = 0x4e800020;
                TRK_flush_cache(write_control_program, sizeof(write_control));
                ((void (*)(void*, void*))&write_control)(&value, lbl_8059BEB4);
                write_result = 0;
                if (read) value = TRKLowWord(*(u32*)&value);
            }
            result = write_result;
        }
        register_field += 1UL << 21;
        ++index;
        *transferred += 8;
    }
    if (status->detected != 0U) {
        *transferred = 0;
        result = 0x702;
    }
    gTRKExceptionStatus_804947AC = saved;
    return result;
}
