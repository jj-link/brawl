#include <revolution/DVD/dvd.h>
#include <types.h>
#pragma force_active on

extern DVDCommandBlock DummyCommandBlock_804E4260;
extern DVDCommandBlock* executing_805A0990;
extern int lbl_805A0630;
extern int lbl_805A0970;
extern unsigned int lbl_805A0984;

extern void fn_801F9688(void);
extern void fn_801F99B0(DVDCommandBlock* block);
extern void fn_801FB6CC(void);
extern void fn_801FDDF0(int arg);
extern void fn_801FDDFC(void* func);
extern void fn_801F8EA0(void);

void fn_801F8B8C(void) {
    lbl_805A0970 = 1;
    switch (lbl_805A0984) {
    case 4:
    case 5:
    case 13:
    case 15:
    case 33:
    case 34:
    case 37:
    case 41:
    case 42:
        fn_801FB6CC();
        {
            DVDCommandBlock* block = executing_805A0990;
            executing_805A0990 = &DummyCommandBlock_804E4260;
            if (block->callback != NULL) {
                block->callback(DVD_RESULT_COVER_CLOSED, block);
            }
            fn_801F9688();
        }
        return;
    case 32:
        lbl_805A0970 = 0;
        /* fallthrough */
    case 35:
    case 36:
    case 38:
        executing_805A0990->state = 1;
        fn_801F99B0(executing_805A0990);
        return;
    case 1:
    case 2:
        if (lbl_805A0630 != 0) {
            return;
        }
        /* fallthrough */
    default:
        lbl_805A0970 = 0;
        fn_801FDDF0(1);
        fn_801FDDFC(fn_801F8EA0);
        return;
    }
}