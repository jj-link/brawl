#pragma force_active on

typedef unsigned char u8;
typedef unsigned int u32;

struct Cam {
    u8 pad[0x45];
    u8 flags;
};

struct Subj {
    u32 pad[2];
    u32 flags;
};

struct Input {
    u8 flags;
};

extern "C" Cam* getInstance__16CameraControllerFv();
extern "C" Subj* getSubjectByPlayerNo__13cmSubjectListFUl(u32);

inline int getAction(u8 flags) {
    int action;
    if (flags & 0x10) {
        action = 1;
    } else if (flags & 4) {
        action = 2;
    } else {
        action = 0;
        if (flags & 8) {
            action = 3;
        }
    }
    return action;
}

inline Subj* getSubject(int player) {
    Cam* cam = getInstance__16CameraControllerFv();
    int mask = 1 << player;
    if (cam->flags & mask) {
        return 0;
    }

    Subj* subject = getSubjectByPlayerNo__13cmSubjectListFUl((u8)player);
    int valid = 0;
    if (subject && ((subject->flags >> 16) & 1)) {
        valid = 1;
    }
    if (valid) {
        return subject;
    }
    return 0;
}

extern "C" void fn_800A888C(void*, bool* state, int* player, const Input* input) {
    int action = getAction(input->flags);

    if (*state && action) {
        *state = 0;
        return;
    }

    switch (action) {
    case 0:
        break;

    case 1:
        *player = -1;
        break;

    case 2:
        if (*player < -1) {
            *player = -1;
        }
        do {
            ++*player;
            if (*player >= 7) {
                *player = -1;
                return;
            }
        } while (!getSubject(*player));
        break;

    case 3:
        if (*player < 0) {
            *player = 7;
        }
        do {
            --*player;
            if (*player < 0) {
                *player = -1;
                return;
            }
        } while (!getSubject(*player));
        break;
    }
}
