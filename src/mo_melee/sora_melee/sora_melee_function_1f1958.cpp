#pragma force_active on
typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;

struct AiInput {
    u8 pad00[0x34];
    AiInput* partner;
    u8 pad38[4];
    u16 flags;
    u8 pad3E[0x52];
    u8 command[8];
    s8 mode;
};

struct AiEntry {
    u8 data[0x1C4];
};

struct AiConfig {
    u8 pad00[0x1D];
    s8 mode;
};

struct AiManager {
    u8 pad00[0x4C];
    AiInput* inputs[7];
    u8 pad68[0x1C];
    s8 states[7];
    u8 pad8B[7];
    s8 inputModes[7];
    s8 commandModes[7];
    u8 padA0[0x58];
    AiEntry* entries;
    u8 padFC[0x40];
    AiConfig* config;
};

extern "C" {
extern AiManager* g_aiMgr;

void fn_27_207DC0(AiEntry*, int, int, AiInput*, int);
void fn_27_1F3844(AiInput*, int);
void fn_27_21DB30(void*, s8, int, bool);
void fn_27_1FAD54(AiInput*);
void setEnableRumble__7IpHumanFb(AiInput*, bool);

void fn_27_1F1958(AiManager* self, int index, s8 state,
                  AiInput* input, int arg)
{
    if (self->inputs && index >= 0 && index < 7) {
        self->states[index] = state;

        if (input) {
            self->inputs[index] = input;
            fn_27_207DC0(&self->entries[index], index, arg, input, 0);

            if (self->inputModes[index] >= 0) {
                fn_27_1F3844(self->inputs[index], self->inputModes[index]);
            }

            if (self->commandModes[index] >= 0) {
                fn_27_21DB30(self->inputs[index]->command,
                              self->commandModes[index], 0,
                              (self->inputs[index]->flags >> 15) & 1);
            }
        }

        if (self->inputs[index]) {
            if (state && state != self->states[index] && !input) {
                fn_27_1FAD54(self->inputs[index]);
            }

            AiInput* partner = self->inputs[index]->partner;
            if (partner) {
                if (!state) {
                    fn_27_21DB30(partner->command,
                                  g_aiMgr->config->mode, 0,
                                  (partner->flags >> 15) & 1);
                } else {
                    fn_27_21DB30(partner->command,
                                  self->inputs[index]->mode, 0,
                                  (partner->flags >> 15) & 1);
                }
                fn_27_1F3844(partner, 0);
            }

            setEnableRumble__7IpHumanFb(self->inputs[index], !state);
        }
    }
}
}
