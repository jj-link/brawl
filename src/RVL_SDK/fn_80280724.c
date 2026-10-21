#pragma force_active on
typedef struct Node Node;
struct Node {
    void (*unk0)(void);
    Node *unk4;
    void *unk8;
    unsigned int unkC;
};

extern void fn_8028059C(void);
extern Node lbl_80532460;
extern Node *lbl_805A0ED0;
extern char lbl_805A0ED8;

void fn_80280724(void) {
    lbl_80532460.unk0 = fn_8028059C;
    lbl_80532460.unk8 = &lbl_805A0ED8;
    lbl_80532460.unk4 = lbl_805A0ED0;
    lbl_805A0ED0 = &lbl_80532460;
}

__declspec(section ".ctors") extern void* const fn_80280724_ctor = (void*)fn_80280724;
