#pragma force_active on

extern int lbl_805A0FA8;
extern char lbl_8048B760[];
extern char lbl_8048CB18[];
extern int lbl_8059F0E8;

int fn_80389934(int, int);
int fn_8038993C(int);
void fn_80389838(int, int);
int fn_80388794(int, void *, int);
unsigned int fn_8033652C(int);
void fn_803886C8(int, void *, int);
void fn_80335638(int, ...);
void fn_80389944(int, int, void *, int);

int fn_8034B494(int arg0, int item)
{
    int maximum = 0x7FFFFF;
    int saved_arg = arg0;
    int logged = 0;
    int result;
    int callback_result;
    int limit;
    int i;

    for (i = 0; i < fn_8038993C(*(int *)(lbl_805A0FA8 + 0xF8)); i++) {
        item = fn_80389934(*(int *)(lbl_805A0FA8 + 0xF8), i);

        if (*(unsigned char *)(lbl_805A0FA8 + 0x16) == 0) {
            char *entry;
            char *obj;
            int found;

            result = fn_80388794(item, &lbl_8059F0E8, 0);
            found = 0;
            obj = (char *)lbl_805A0FA8;
            entry = obj + 4;

            for (limit = 1;
                 limit <= *(unsigned char *)(obj + 0x0D);
                 limit++, entry += 4) {
                if (result == *(int *)(entry + 0x108)) {
                    fn_80389838(*(int *)(obj + 0xF8), item);
                    i--;
                    found = 1;
                    break;
                }
            }

            if (found) {
                continue;
            }
        }

        {
            int (*callback)(int, int);

            callback = *(int (**)(int, int))(lbl_805A0FA8 + 0x490);
            if (callback != 0) {
                callback_result = callback(i, *(int *)(lbl_805A0FA8 + 0x494));

                if (callback_result > 0) {
                    if (callback_result > maximum) {
                        callback_result = maximum;
                    }
                    fn_803886C8(item, lbl_8048B760,
                                (callback_result << 8) | fn_8033652C(0x100));
                } else {
                    fn_80389838(*(int *)(lbl_805A0FA8 + 0xF8), item);
                    fn_80335638(0x400, lbl_8048CB18, i, callback_result);
                    logged = 1;
                    i--;
                }
            } else {
                fn_803886C8(item, lbl_8048B760, fn_8033652C(0x80));
            }
        }

    }

    if (saved_arg != 0 &&
        fn_8038993C(*(int *)(lbl_805A0FA8 + 0xF8)) != 0) {
        fn_80389944(*(int *)(lbl_805A0FA8 + 0xF8), 0, lbl_8048B760, 0);
    }

    if (logged != 0 &&
        fn_8038993C(*(int *)(lbl_805A0FA8 + 0xF8)) == 0) {
        return 0;
    }

    return 1;
}
