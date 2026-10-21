#pragma force_active on
typedef struct Entry {
    char pad[8];
    char *first;
    char *second;
} Entry;

typedef struct Owner {
    char pad[0x30];
    char list[1];
} Owner;

typedef struct Context {
    char pad[0x0C];
    Owner *owner;
} Context;

extern void fn_803974FC(void);
extern Context **fn_80397570(void);
extern Entry *fn_803904B8(void *);
extern int fn_80392730(const char *);
extern int fn_803936B0(int, const char *, int);
extern void fn_803900A0(Entry *);
extern char lbl_8059FC78[3];
extern char lbl_8059FC6C[3];

int fn_80393BFC(int arg0)
{
    Owner *owner;
    Entry *entry;
    int result;

    fn_803974FC();
    owner = (*fn_80397570())->owner;
    entry = fn_803904B8(owner->list);

    while (entry != 0) {
        result = fn_803936B0(arg0, entry->first,
                            fn_80392730(entry->first));
        if (result != 0) {
            return result;
        }

        result = fn_803936B0(arg0, lbl_8059FC78, 2);
        if (result != 0) {
            return result;
        }

        result = fn_803936B0(arg0, entry->second,
                            fn_80392730(entry->second));
        if (result != 0) {
            return result;
        }

        result = fn_803936B0(arg0, lbl_8059FC6C, 2);
        if (result != 0) {
            return result;
        }

        fn_803900A0(entry);
        entry = fn_803904B8(owner->list);
    }

    return 0;
}
