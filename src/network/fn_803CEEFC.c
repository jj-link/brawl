#include <string.h>
#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct {
    char pad[0x1b40];
    int state;
    int pad1;
    int error;
} State;

typedef struct {
    int kind;
    int index;
} Request;

typedef struct {
    void *arg;
    char name[0x40];
    u8 end;
    u8 mode;
    u8 a;
    u8 b;
    char pad[0x8c];
    char work[0xb8];
    Request request;
    char pad2[0x40];
    void *buffer;
    u8 flag;
} Entry;

extern int fn_803CD270(void);
extern void fn_803CD318(int);
extern State *fn_803CD324(void);
extern void fn_803CD32C(void);
extern Entry *fn_803CD3B4(int);
extern void fn_8020B898(void *, Request *);
extern int fn_8020C34C(void *, void (*)(void), void *);
extern int fn_8020BD30(const char *, void *, unsigned char, void *, int,
                       void (*)(void), void *);
extern int fn_8020A7F8(const char *, unsigned char, unsigned char,
                       void (*)(void), void *);
extern void fn_803CEC14(void);
extern void fn_803CE640(void);
extern void fn_803CE924(void);
extern const char *lbl_8059FEB0[2];
extern const unsigned char lbl_805A49E8[8];
extern const unsigned char lbl_805A5150[4];

void fn_803CEEFC(int index, unsigned char mode, void *arg) {
    void *p;
    int irq;
    Entry *entry;
    Entry *e;
    Request *req;
    int inner_irq;
    int mode_irq;
    int error_irq;
    int result_irq;
    int default_irq;
    void *create_work;
    void *work;
    const char *name;
    int result;

    if (fn_803CD270())
        p = (char *)fn_803CD3B4(index) + 0x48;
    else
        p = 0;

    irq = OSDisableInterrupts();
    fn_803CD318(1);
    fn_803CD324()->state = 6;
    OSRestoreInterrupts(irq);

    entry = fn_803CD3B4(index);
    name = lbl_8059FEB0[index];
    entry->arg = arg;
    strncpy(entry->name, name, 0x40);
    entry->end = 0;
    entry->mode = mode;
    entry->a = lbl_805A49E8[index];
    entry->b = lbl_805A5150[index];

    work = (char *)fn_803CD3B4(index) + 0xd4;
    e = fn_803CD3B4(index);
    req = &e->request;
    e->request.kind = 11;
    req->index = index;
    fn_8020B898(work, req);

    if (entry->flag) {
        result = fn_8020C34C(p, fn_803CEC14, work);
        switch (result) {
        case 0:
            break;
        case -128:
        case -64:
        case -8:
        case -4:
        case -1:
        default:
            switch (fn_803CD324()->state) {
            case 0:
            case 6:
                inner_irq = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 2;
                fn_803CD324()->error = result;
                OSRestoreInterrupts(inner_irq);
                break;
            }
            break;
        }
    } else {
        memset(entry->buffer, 0, 0x2000);
        result = fn_8020BD30(name, p, mode, entry->buffer, 0x2000,
                             fn_803CE640, work);
        switch (result) {
        case 0:
            break;
        case -12:
            if (mode == 1) {
                switch (fn_803CD324()->state) {
                case 0:
                case 6:
                    mode_irq = OSDisableInterrupts();
                    fn_803CD318(0);
                    fn_803CD324()->state = 2;
                    fn_803CD324()->error = result;
                    OSRestoreInterrupts(mode_irq);
                    break;
                }
            } else {
                create_work = (char *)fn_803CD3B4(index) + 0xd4;
                e = fn_803CD3B4(index);
                req = &e->request;
                e->request.kind = 10;
                req->index = index;
                fn_8020B898(create_work, req);
                result = fn_8020A7F8(name, entry->a, entry->b,
                                     fn_803CE924, create_work);
                if (result != 0) {
                    switch (fn_803CD324()->state) {
                    case 0:
                    case 6:
                        error_irq = OSDisableInterrupts();
                        fn_803CD318(0);
                        fn_803CD324()->state = 2;
                        fn_803CD324()->error = result;
                        OSRestoreInterrupts(error_irq);
                        break;
                    }
                }
            }
            break;
        case -10:
        case -3:
        case -1:
            switch (fn_803CD324()->state) {
            case 0:
            case 6:
                result_irq = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 2;
                fn_803CD324()->error = result;
                OSRestoreInterrupts(result_irq);
                break;
            }
            break;
        case -128:
        case -64:
        case -11:
        case -9:
        case -5:
        case -4:
        case -2:
        default:
            switch (fn_803CD324()->state) {
            case 0:
            case 6:
                default_irq = OSDisableInterrupts();
                fn_803CD318(0);
                fn_803CD324()->state = 5;
                fn_803CD324()->error = result;
                OSRestoreInterrupts(default_irq);
                break;
            }
            break;
        }
    }

    fn_803CD32C();
}
