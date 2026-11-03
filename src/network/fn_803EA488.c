#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct Config {
    int a, b;
    u16 c, d;
    int e, f;
} Config;
typedef struct Input {
    int value;
    Config *config;
    u8 letter, flags;
} Input;
typedef struct Entry {
    u8 pad0[0x38];
    int a, b;
    u8 pad40[0x1f34];
    int state;
    u8 pad1f78[4];
    void *ptr;
    int error;
    u8 pad1f84[8];
    u16 flags;
    u8 letter;
    u8 pad1f8f;
    u8 object[0x1c];
    u16 mode;
    u8 pad1fae[0xe];
    int value;
    u8 pad1fc0[8];
} Entry;
typedef struct Global {
    u8 pad[0x30];
    int count, mounted;
    u8 pad38[8];
    int error;
    u8 pad44[0x20];
    u8 critical[0x3c];
    Entry entries[26];
} Global;
extern Global lbl_805644C0;
extern void PF_enterCritical(void *);
extern void PF_exitCritical(void *);
extern int fn_803ED8BC(int, int);
extern void fn_803D634C(void *, int, int);
extern void fn_803EBA40(void *);
extern int fn_803D6DA8(void *);
extern void fn_803DA2E0(void *, int, int, u16, u16);
extern void fn_803DA2F4(void *, int);
extern void fn_803DA304(void *, int);
extern int fn_803D6D64(void *);
extern void fn_803D6D7C(void *);
extern void fn_803D6D98(void *);
extern int fn_803E94E8(void *);

int fn_803EA488(Input *arg, int arg1, int arg2)
{
    int i;
    Entry *entry;
    int result;
    if (arg->config->e == 0) arg->config->e = 1;
    if (arg->config->f == 0) arg->config->f = 1;
    arg->flags = 0;
    arg->letter = 0;
    PF_enterCritical(lbl_805644C0.critical);
    if (arg1 != 0 && fn_803ED8BC(arg1, arg2) != 0) {
        PF_exitCritical(lbl_805644C0.critical);
        lbl_805644C0.error = 17;
        return 17;
    }
    for (i = 0; i < 26; i++) {
        entry = &lbl_805644C0.entries[i];
        if (!(entry->flags & 1)) break;
    }
    if (i < 0 || i >= 26 || lbl_805644C0.count < 0 || lbl_805644C0.count >= 26) {
        PF_exitCritical(lbl_805644C0.critical);
        lbl_805644C0.error = 4;
        return 4;
    }
    entry->a = -1;
    entry->b = -1;
    fn_803D634C(entry, 0, 0x1fc8);
    entry->value = arg->value;
    entry->letter = (short)i + 0x41;
    fn_803EBA40(entry->object);
    entry->state = 1;
    entry->ptr = entry->pad1f78;
    {
    int temp = fn_803D6DA8(entry);
    if (temp != 0) {
        result = temp;
    } else {
        Config *config = arg->config;
        fn_803DA2E0(entry, config->a, config->b, config->c, config->d);
        fn_803DA2F4(entry, arg->config->e);
        fn_803DA304(entry, arg->config->f);
        result = 0;
    }
    }
    if (result != 0) {
        PF_exitCritical(lbl_805644C0.critical);
        lbl_805644C0.error = result;
        return result;
    }
    entry->flags |= 1;
    arg->flags |= 1;
    entry->letter = i + 0x41;
    arg->letter = i + 0x41;
    lbl_805644C0.count++;
    if (fn_803D6D64(entry)) {
        arg->flags |= 0x10;
        if (!(entry->flags & 8)) {
            int temp = fn_803E94E8(entry);
            if (temp != 0) {
                result = temp;
                goto checked;
            }
            entry->mode &= 0xfff8;
            fn_803D6D98(entry);
            lbl_805644C0.mounted++;
        }
        fn_803D6D7C(entry);
        result = 0;
checked:
        if (result != 0) {
            lbl_805644C0.error = result;
            entry->error = result;
            PF_exitCritical(lbl_805644C0.critical);
            return 0;
        }
        arg->flags |= 2;
    }
    PF_exitCritical(lbl_805644C0.critical);
    return 0;
}