#include <so/so_module_accesser.h>
#include <so/so_enable.h>
#include <so/kinetic/so_kinetic_module_impl.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_113_20D1C(s8*, void*, void*);
extern "C" void fn_113_20ED0(s8*, void*, void*);
extern "C" void fn_113_2114C(s8*, void*, void*);
extern "C" void fn_113_21334(s8*, void*, void*);
extern "C" void fn_113_2172C(s8*, void*, void*);
extern "C" void fn_113_219E8(s8*, void*, void*);
extern "C" void fn_113_21B84(s8*, void*, void*);
extern "C" void fn_113_21DA8(s8*, void*, void*);
extern "C" void fn_113_21F58(s8*, void*, void*);
extern "C" void fn_113_220DC(s8*, void*, void*);

struct PikminProcessEntry {
    virtual void slot0();
    virtual void update(soModuleAccesser*);
    unsigned char reserved;
    soEnable enabled;
    unsigned char suspended;
};

struct State {
    s8 a;
    s8 b;
};

extern "C" void fn_113_20B38(PikminProcessEntry* entry, soModuleAccesser* accesser) {
    if (!entry->enabled.isEnable() || entry->suspended == 1) {
        return;
    }
    switch (accesser->getKineticModule().getKineticType()) {
            case 0x21: {
                State state;
                state.a = 0;
                state.b = 0;
                fn_113_20D1C(&state.b, entry, accesser);
                break;
            }
            case 0x25: {
                State state;
                state.a = 0;
                state.b = 0;
                fn_113_20ED0(&state.b, entry, accesser);
                break;
            }
            case 0x22: {
                State state;
                state.a = 0;
                state.b = 0;
                fn_113_2114C(&state.b, entry, accesser);
                break;
            }
            case 0x23: {
                State state;
                state.a = 0;
                state.b = 0;
                fn_113_21334(&state.b, entry, accesser);
                break;
            }
            case 0x27:
            case 0x28:
            case 0x29: {
                State state;
                state.a = 0;
                state.b = 0;
                fn_113_2172C(&state.b, entry, accesser);
                break;
            }
            case 0x2A:
            case 0x30: {
                State state;
                state.a = 0;
                state.b = 0;
                fn_113_219E8(&state.b, entry, accesser);
                break;
            }
            case 0x2D: {
                State state;
                state.a = 0;
                state.b = 0;
                fn_113_21B84(&state.b, entry, accesser);
                break;
            }
            case 0x32: {
                State state;
                state.a = 0;
                state.b = 0;
                fn_113_21DA8(&state.b, entry, accesser);
                break;
            }
            case 0x35: {
                State state;
                state.a = 0;
                state.b = 0;
                fn_113_21F58(&state.b, entry, accesser);
                break;
            }
            case 0x2C: {
                State state;
                state.a = 0;
                state.b = 0;
                fn_113_220DC(&state.b, entry, accesser);
                break;
            }
            default:
                entry->update(accesser);
                break;
    }
}