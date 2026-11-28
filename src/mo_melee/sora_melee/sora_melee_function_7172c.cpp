#include <ac/ac_anim_cmd_impl.h>
#pragma force_active on

namespace melee {
struct Commands {
    const acAnimCmdConv* first;
    const acAnimCmdConv* main;
    const acAnimCmdConv* last;
    Commands() {}
    Commands(const acAnimCmdConv* a, const acAnimCmdConv* b, const acAnimCmdConv* c)
        : first(a), main(b), last(c) {}
};

struct Context {
    char padding[0x24];
    float currentFrame;
};
struct Object { Context* context; };
extern "C" void fn_27_71948(Commands*, const Object*, int);
extern "C" void fn_27_7022C(Context*, const Commands*, int, float);
extern "C" char lbl_27_data_8390[];

class soNullable {
public:
    virtual void isNull();
    virtual void fn_27_716A8();
    virtual Object* fn_27_713E0(int);
    virtual void fn_27_714B0();
    virtual int fn_27_71614();
};
struct List {
    void* primary;
    char* secondary;
    unsigned bits;
    char storage[0x50];
};
class Object_vptr_0 {
public:
    virtual void slot0(short*, List*);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
};
struct Class_1B60_base { char pad[0x48]; };
class Class_1B60 : public Class_1B60_base {
public:
    virtual void fn_27_1E8DC();
    virtual void fn_27_1E374();
};
struct ListView {
    virtual void slot0();
    virtual Object** at(int);
};
struct Owner { char pad[0x20]; soNullable* source; };

extern "C" void fn_27_7172C(Owner* self, const short* id, int index, long commandIndex, unsigned option, float frame) {
    short key = *id;
    Commands empty(0, 0, 0);
    int i;
    Object* object;
    int count;
    unsigned long frameMode;
    long mode;
    int selectedCount;
    int j;
    Object* selectedObject;
    frameMode = option;
    mode = commandIndex;

    if (key == -1) {
        count = self->source->fn_27_71614();
        for (i = 0; i < count; ++i) {
            object = self->source->fn_27_713E0(i);
            if (mode < 0) {
                fn_27_7022C(object->context, &empty, index, frame);
            } else if (frameMode == 1UL) {
                Commands commands;
                fn_27_71948(&commands, object, mode);
                Context* target = object->context;
                fn_27_7022C(target, &commands, index, target->currentFrame);
            } else {
                Commands commands;
                fn_27_71948(&commands, object, mode);
                fn_27_7022C(object->context, &commands, index, frame);
            }
        }
    } else {
        short selected = key;
        List list;
        list.primary = lbl_27_data_8390;
        list.secondary = lbl_27_data_8390 + 0x48;
        list.bits &= 0x1FFF;
        reinterpret_cast<Object_vptr_0*>(reinterpret_cast<char*>(self->source) + 0xC)->slot0(&selected, &list);
        selectedCount = static_cast<int>((list.bits << 12) & 0xFE000000) >> 26;
        for (j = 0; j < selectedCount; ++j) {
            selectedObject = *reinterpret_cast<ListView*>(&list)->at(j);
            if (mode < 0) {
                fn_27_7022C(selectedObject->context, &empty, index, frame);
            } else if (frameMode == 1UL) {
                Commands commands;
                fn_27_71948(&commands, selectedObject, mode);
                Context* target = selectedObject->context;
                fn_27_7022C(target, &commands, index, target->currentFrame);
            } else {
                Commands commands;
                fn_27_71948(&commands, selectedObject, mode);
                fn_27_7022C(selectedObject->context, &commands, index, frame);
            }
        }
    }
}
}
