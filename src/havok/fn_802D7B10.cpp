#pragma force_active on
typedef unsigned short u16;
struct Manager;
struct Root { char pad0[8]; Manager* manager; char padC[0x1AC]; int count; };
struct Input { char pad0[0x10]; int offset; char pad14[4]; unsigned char type; };
struct Context { u16 flag; char pad2[2]; int value; Root* root1; Root* root2; int pad14; void* owner; };
extern "C" void fn_802F4458(Manager*, Context*);
extern "C" void fn_802E4140(Root*, Context*);
extern "C" void fn_802D7B10(void* owner, Input* a, Input* b, int value) {
    Root* root1;
    Root* root2;
    if ((int)a->type == 1) root1 = (Root*)((char*)a + a->offset);
    else root1 = 0;
    if ((int)b->type == 1) root2 = (Root*)((char*)b + b->offset);
    else root2 = 0;
    Manager* manager = root1->manager;
    Context context;
    context.flag = 0xFFFF;
    context.value = value;
    context.root1 = root1;
    context.root2 = root2;
    context.owner = owner;
    fn_802F4458(manager, &context);
    if (root1->count != 0) fn_802E4140(root1, &context);
    if (root2->count != 0) fn_802E4140(root2, &context);
}