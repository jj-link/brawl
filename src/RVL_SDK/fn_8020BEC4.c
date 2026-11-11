#include <revolution/OS/OSInterrupt.h>
#include <stdio.h>
#pragma force_active on

typedef struct Obj Obj;
typedef struct Inner {
    int file;
    int handle;
    char path[0x40];
    char path2[0x40];
    unsigned char mode;
    unsigned char state;
    unsigned char status;
} Inner;
struct Obj {
    int field0;
    int (*cb)(int, Obj *);
    Inner *inner;
    char pad0c[0xc];
    int a18, a1c, a20, a24, a28, a2c;
    char pad30[0x4c];
    int command;
    int a80, a84;
    char pad88[4];
    int id;
    char pad90[0x28];
    int flag;
};
void fn_8020BEC4(int, void *);
extern int fn_8020CAEC(int);
extern void fn_8020C874(char *, const char *);
extern int fn_802146B8(void *, void *, void *, void *, void *, void *, void *, void (*)(int, void *), void *);
extern int fn_80214E80(void *, int, void (*)(int, void *), void *);
extern int fn_80213FC8(const char *, int, int, int, int, void (*)(int, void *), void *);
extern int fn_80214CC4(void *, int, int, int, int, void (*)(int, void *), void *);
extern int fn_80215178(int, int, int, void (*)(int, void *), void *);
extern int fn_8021523C(int, int, int, void (*)(int, void *), void *);
extern int fn_802150CC(int, int, int, void (*)(int, void *), void *);
extern int lbl_805A0BA0;
extern char lbl_8047C090[];
extern char lbl_8047C09C[];
extern char lbl_8059EB38[8];
extern char lbl_8059EB40[6];

void fn_8020BEC4(int arg0, void *arg1) {
    Inner *inner;
    Obj *obj = arg1;
    if (arg0 >= 0 || (arg0 == -0x69 && obj->command == 0)) {
        int result = -0x75;
        inner = obj->inner;
        if (obj->command == 0)
            inner->state = 1;
        if (obj->command == 2) {
            inner->handle = arg0;
            inner->state = 2;
        }
        if (obj->command == 2 && obj->flag != 0)
            obj->command += 2;
        else
            obj->command += 1;

        if (obj->command == 1) {
            result = fn_802146B8(inner->path, &obj->a18, &obj->a1c, &obj->a20, &obj->a24, &obj->a28, &obj->a2c, fn_8020BEC4, obj);
        } else if (obj->command == 2) {
            result = fn_80214E80(inner->path, 1, fn_8020BEC4, obj);
        } else if (obj->command == 3) {
            char buf[0x40];
            int id;
            BOOL enabled = OSDisableInterrupts();
            id = lbl_805A0BA0++;
            OSRestoreInterrupts(enabled);
            obj->id = id;
            sprintf(buf, lbl_8059EB38, lbl_8047C090, id);
            result = fn_80213FC8(buf, 0, 3, 0, 0, fn_8020BEC4, obj);
        } else if (obj->command == 4) {
            char name[0x10];
            fn_8020C874(name, inner->path);
            if (obj->flag == 0) {
                inner->state = 3;
                sprintf(inner->path2, lbl_8047C09C, lbl_8047C090, obj->id, name);
            } else {
                sprintf(inner->path2, lbl_8059EB40, lbl_8047C090, name);
            }
            result = fn_80214CC4(inner->path2, obj->a20, obj->a24, obj->a28, obj->a2c, fn_8020BEC4, obj);
        } else if (obj->command == 5) {
            inner->state = 4;
            if (inner->mode == 2)
                result = fn_80214E80(inner->path2, 2, fn_8020BEC4, obj);
            else if (inner->mode == 3)
                result = fn_80214E80(inner->path2, 3, fn_8020BEC4, obj);
            else
                result = -0x75;
        } else if (obj->command == 6) {
            inner->file = arg0;
            inner->state = 5;
            obj->command = 7;
            result = fn_80215178(inner->handle, obj->a80, obj->a84, fn_8020BEC4, obj);
        } else if (obj->command == 7) {
            result = fn_80215178(inner->handle, obj->a80, obj->a84, fn_8020BEC4, obj);
        } else if (obj->command == 8) {
            if (arg0 > 0) {
                obj->command = 6;
                result = fn_8021523C(inner->file, obj->a80, arg0, fn_8020BEC4, obj);
            } else if (arg0 == 0) {
                result = fn_802150CC(inner->file, 0, 0, fn_8020BEC4, obj);
            }
        } else if (obj->command == 9) {
            if (arg0 == 0) {
                if (obj->flag == 0)
                    inner->status = 3;
                else
                    inner->status = 5;
                obj->cb(fn_8020CAEC(0), obj);
                return;
            }
            obj->cb(fn_8020CAEC(arg0), obj);
            return;
        }
        if (result != 0)
            obj->cb(fn_8020CAEC(result), obj);
    } else {
        obj->cb(fn_8020CAEC(arg0), obj);
    }
}
