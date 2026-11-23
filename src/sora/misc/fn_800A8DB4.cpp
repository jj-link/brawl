#pragma force_active on

struct Vec {
    float x, y;
};

struct Obj;
struct Input;
struct Output {
    unsigned char flags;
    char pad[3];
    Vec a, b;
    Output(Obj*, Input*, int);
};

struct Obj {
    char pad[0x60];
    int state;

    int getState() const {
        return state;
    }
};

struct Input {
    char pad[4];
    unsigned int buttons;
    char pad2[4];
    unsigned int pressed;
    char pad3[0x2c];
    int type;
};

struct Mapping {
    unsigned char mode;
    unsigned char flag;
    unsigned short pad;
    unsigned int masks[4];
};

extern "C" const Mapping lbl_804078F8[];
extern "C" const Mapping lbl_8040795C[];
extern "C" const float lbl_805A205C;

extern "C" void fn_800A8EF8(Obj*, Input*, Vec*);
extern "C" void fn_800A92C4(Obj*, Input*, Vec*);
extern "C" void fn_800A944C(Obj*, Input*, Vec*);

inline void impl(Output* out, Obj* obj, Input* input, int mode) {
    const Mapping* p = lbl_804078F8;
    if (mode)
        p = lbl_8040795C;

    for (int i = 0; i < 5; ++i, ++p) {
        unsigned int mask = p->masks[input->type];
        if (p->mode) {
            if (mask == (mask & input->buttons) && (input->pressed & mask))
                out->flags |= p->flag;
        } else if (mask && mask == (mask & input->buttons)) {
            out->flags |= p->flag;
        }
    }

    if (!mode) {
        fn_800A8EF8(obj, input, &out->a);
        fn_800A92C4(obj, input, &out->b);
    } else {
        fn_800A944C(obj, input, &out->b);
    }
}

inline Output::Output(Obj* obj, Input* input, int mode) {
    flags = 0;
    a.y = lbl_805A205C;
    a.x = lbl_805A205C;
    b.y = lbl_805A205C;
    b.x = lbl_805A205C;
    if (obj->getState() > 0)
        return;
    impl(this, obj, input, mode);
}

extern "C" Output fn_800A8DB4(Obj* obj, Input* input, int mode) {
    return Output(obj, input, mode);
}