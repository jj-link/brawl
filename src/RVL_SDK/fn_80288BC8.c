#pragma force_active on
#pragma use_lmw_stmw on

typedef unsigned int u32;

extern void fn_8028965C(void *, void *);
extern u32 fn_8028D8AC(u32, int);
extern int fn_8028980C(void *);
extern void fn_80289708(void *, int);
extern int fn_80289814(void *);
extern void fn_80288B84(void *, int, int, int);
extern u32 fn_8028981C(u32);
extern int fn_8028D8A4(int, int);
extern void fn_8028D8B4(void *, int);
extern void fn_8028D8A0(void);
extern void fn_802883C8(void *, void *, int);
extern void fn_8028A9E8(int, int);

#define DECLARE_HANDLER(handler, length) \
    extern void handler(u32, void *, void *, void *, int); \
    extern int length(u32)

DECLARE_HANDLER(fn_80289824, fn_80289844);
DECLARE_HANDLER(fn_80289850, fn_80289BFC);
DECLARE_HANDLER(fn_80289C04, fn_80289D0C);
DECLARE_HANDLER(fn_80289D14, fn_8028A040);
DECLARE_HANDLER(fn_8028A048, fn_8028A52C);
DECLARE_HANDLER(fn_8028A534, fn_8028A6F0);
DECLARE_HANDLER(fn_8028A6F8, fn_8028A7A0);
DECLARE_HANDLER(fn_8028A7A8, fn_8028A860);
DECLARE_HANDLER(fn_8028A868, fn_8028A914);
DECLARE_HANDLER(fn_8028A91C, fn_8028AA08);
DECLARE_HANDLER(fn_8028AA10, fn_8028ABD8);
DECLARE_HANDLER(fn_8028ABE0, fn_8028AD20);
DECLARE_HANDLER(fn_8028AD28, fn_8028AE34);
DECLARE_HANDLER(fn_8028B5E0, fn_8028B66C);
DECLARE_HANDLER(fn_8028B674, fn_8028BCC8);
DECLARE_HANDLER(fn_8028BCD0, fn_8028C678);
DECLARE_HANDLER(fn_8028C680, fn_8028CFA4);
DECLARE_HANDLER(fn_8028CFAC, fn_8028D184);
DECLARE_HANDLER(fn_8028D18C, fn_8028D46C);
DECLARE_HANDLER(fn_8028D474, fn_8028D5C8);
DECLARE_HANDLER(fn_8028D5D0, fn_8028D898);

extern int fn_8028AE3C(u32, void *, void *, void *, void *, int);
extern int fn_8028B0E8(u32);
extern int fn_8028B0F0(u32, void *, void *, void *, void *, int);
extern int fn_8028B328(u32);
extern int fn_8028B330(u32, void *, void *, void *, void *, int);
extern int fn_8028B5D8(u32);

#define ADVANCE(length, amount) \
    { \
        int n; \
        old = p; \
        p += amount; \
        n = length(old) * 8; \
        fn_8028D8B4(st.f4, fn_8028D8A4(fn_80289814(st.f4), n)); \
        fn_8028D8B4(st.f100, fn_8028D8A4(fn_80289814(st.f100), n)); \
    }

#define HANDLE(value, handler, length, amount) \
    case value: \
        handler(p, st.copy, st.mat1, st.mat2, context); \
        ADVANCE(length, amount); \
        break

#define HANDLE_RESULT(value, handler, length, amount) \
    case value: \
        result = handler(p, st.copy, st.mat1, st.mat2, st.tmp, context); \
        ADVANCE(length, amount); \
        if (result) goto pass; else goto fail; \
        break

void fn_80288BC8(u32 p, int size, void *input, int context)
{
    struct {
        char tmp[0x20];
        char mat2[0x40];
        char mat1[0x40];
        char copy[0x30];
        int e0;
        char e4[0x10];
        char f4[0xc];
        char f100[0xc];
    } st __attribute__((aligned(16)));
    u32 end, old;
    int result;

    fn_8028965C(st.copy, input);
    end = fn_8028D8AC(p, size);
    fn_80289708(st.mat1, fn_8028980C(&st.e0));
    fn_80289708(st.mat2, fn_8028980C(st.e4));
    fn_80288B84(st.copy, context, fn_80289814(st.f4), 8);

    while (p < end) {
again:
        switch (fn_8028981C(p)) {
        case 0:
            p = (p + 15) & ~15;
            goto again;
        HANDLE(1, fn_80289824, fn_80289844, 12);
        HANDLE(2, fn_80289850, fn_80289BFC, 144);
        HANDLE(3, fn_80289C04, fn_80289D0C, 48);
        HANDLE(4, fn_80289D14, fn_8028A040, 112);
        HANDLE(5, fn_8028A048, fn_8028A52C, 2);
        HANDLE(6, fn_8028A534, fn_8028A6F0, 8);
        HANDLE(7, fn_8028A6F8, fn_8028A7A0, 4);
        HANDLE(8, fn_8028A7A8, fn_8028A860, 12);
        HANDLE(9, fn_8028A868, fn_8028A914, 12);
        HANDLE(10, fn_8028A91C, fn_8028AA08, 8);
        HANDLE(11, fn_8028AA10, fn_8028ABD8, 16);
        HANDLE(12, fn_8028ABE0, fn_8028AD20, 4);
        HANDLE(13, fn_8028AD28, fn_8028AE34, 4);
        HANDLE_RESULT(14, fn_8028AE3C, fn_8028B0E8, 16);
        HANDLE_RESULT(16, fn_8028B0F0, fn_8028B328, 20);
        HANDLE_RESULT(15, fn_8028B330, fn_8028B5D8, 20);
        HANDLE(17, fn_8028B5E0, fn_8028B66C, 12);
        HANDLE(18, fn_8028B674, fn_8028BCC8, 20);
        HANDLE(19, fn_8028BCD0, fn_8028C678, 80);
        HANDLE(20, fn_8028C680, fn_8028CFA4, 64);
        HANDLE(23, fn_8028CFAC, fn_8028D184, 32);
        HANDLE(24, fn_8028D18C, fn_8028D46C, 32);
        HANDLE(25, fn_8028D474, fn_8028D5C8, 16);
        HANDLE(26, fn_8028D5D0, fn_8028D898, 32);
        }
        continue;
fail:
        fn_802883C8(st.tmp, st.copy, context);
        continue;
pass:
        fn_8028A9E8(1, context);
    }
    fn_8028D8A0();
}
