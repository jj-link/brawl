#include <types.h>
#include <new>
#include <gf/gf_task.h>
#include <ac/ac_cmd_interpreter.h>
#include <so/so_array.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" char lbl_27_data_15028[];
extern "C" u8 lbl_27_data_15038[];
extern "C" u8 lbl_27_data_15218[];
extern "C" u8 lbl_27_data_150C8[];
extern "C" u8 __vt__26soAnimCmdInterpreterEffect[];
extern "C" const f32 lbl_27_rodata_CC0;
extern "C" const f32 lbl_27_rodata_CC4;
extern "C" void fn_27_9FC8C(void*, void*);

struct Entry : acCmdInterpreterStackData {
    Entry() : acCmdInterpreterStackData(Invalid, 0, false, 0, lbl_27_rodata_CC0) {}
};

struct StackVector {
    void* vt0;
    void* vt4;
    u32 flags : 8;
    u32 flags2 : 8;
    u32 remaining : 16;
    Entry entries[8];
};

struct ByteVector {
    void* vt0;
    void* vt4;
    s32 top : 2;
    s32 last : 2;
    s32 size : 2;
    u32 full : 1;
    struct Elem {
        s8 value;
        Elem() : value(-1) {}
    };
    Elem entries[1];
    ByteVector() : vt0(lbl_27_data_150C8), vt4(lbl_27_data_150C8 + 0x48),
        top(0), last(0), size(1), full(0) {}
};

struct Layout {
    u8 task[0x40];
    StackVector stack;
    ByteVector bytes;
    void* screen;
    acCmdInterpreter interpreter;
    void* effectScreen;
};

inline void resetBytes(s8* begin, s8* end) {
    s8* p = begin;
    do {
        *p = -1;
        ++p;
    } while (p < end);
}

extern "C" Layout* fn_27_A068C(Layout* self) {
    new (self) gfTask(lbl_27_data_15028, gfTask::Category_Effect, 11, 13, true);
    *(void**)(self->task + 0x3c) = lbl_27_data_15038;
    self->stack.vt0 = lbl_27_data_15218;
    self->stack.vt4 = lbl_27_data_15218 + 0x48;
    self->stack.flags = 0;
    self->stack.flags2 = 0;
    new (&self->stack) StackVector;

    new (&self->bytes) ByteVector;

    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&self->bytes.vt4, 1, 1);
    fn_27_9FC8C(&self->screen, &self->bytes);

    u8 reset = 0;
    acCmdInterpreter* interpreter = &self->interpreter;
    new (interpreter) acCmdInterpreter(
        (soArrayVector<acCmdInterpreterStackData, 8>*)&self->stack,
        1, 0, &reset, lbl_27_rodata_CC4);
    *(void**)((u8*)interpreter + 0x34) = &self->screen;
    *(void**)interpreter = __vt__26soAnimCmdInterpreterEffect;
    return self;
}
