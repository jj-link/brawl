#pragma force_active on
#pragma fp_contract off

struct Target {
    char padding00[0x3e];
    unsigned char playerMask;
    char padding3f;
    unsigned int flags;
    char padding44[0x8];
};

struct TargetManager {
    char padding00[0x34c];
    Target* targets;
    unsigned short count;
};

extern "C" {
extern const float lbl_27_rodata_2B80[];
float randf__Fv();
}

extern "C" Target* fn_27_1EF3AC(TargetManager* manager, Target* current, int player) {
    unsigned int flags;
    const float* const constants = lbl_27_rodata_2B80;
    unsigned short count = manager->count;
    Target* target = manager->targets;
    float score = constants[2];
    int playerBit = 1 << player;

    for (int i = 0; i < count; ++i, ++target) {
        flags = target->flags;
        if ((flags & 2) && target != current) {
            if (flags & 0x1000) {
                if (player < 0)
                    score += constants[20];
            } else {
                bool applies;
                if ((flags & 0x800) &&
                    (player < 0 || player >= 8 || (target->playerMask & playerBit)))
                    applies = true;
                else
                    applies = false;
                if (applies)
                    score += constants[9];
                else
                    score += constants[21];
            }
        }
    }

    score *= randf__Fv();
    target = manager->targets;
    int last = manager->count - 1;
    for (int i = 0; i < last; ++i, ++target) {
        unsigned int flags = target->flags;
        if ((flags & 2) && target != current) {
            if (flags & 0x1000) {
                if (player < 0)
                    score -= constants[20];
            } else {
                bool applies;
                if ((flags & 0x800) &&
                    (player < 0 || player >= 8 || (target->playerMask & playerBit)))
                    applies = true;
                else
                    applies = false;
                if (applies)
                    score -= constants[9];
                else
                    score -= constants[21];
            }
            if (score <= constants[2])
                break;
        }
    }
    return target;
}
