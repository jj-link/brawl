#pragma force_active on

#pragma opt_common_subs off
typedef enum _va_arg_type
{
  arg_ARGPOINTER,
  arg_WORD,
  arg_DOUBLEWORD,
  arg_ARGREAL
} _va_arg_type;
typedef struct __va_list_struct
{
  char gpr;
  char fpr;
  char *input_arg_area;
  char *reg_save_area;
} va_list[1];
void *__va_arg(va_list argp, int type);
typedef signed long intptr_t;
typedef unsigned long uintptr_t;
typedef intptr_t ptrdiff_t;
typedef unsigned long size_t;
typedef unsigned short wchar_t;
typedef unsigned long long u64;
typedef signed long long s64;
typedef unsigned long u32;
typedef signed long s32;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
typedef signed char s8;
typedef float f32;
typedef double f64;
typedef int UNKWORD;
typedef void UNKTYPE;
enum 
{
  FALSE,
  TRUE
};
typedef int BOOL;
typedef void (*funcptr_t)(void);
typedef struct Table
{
  s32 *entries;
  s32 pad;
  s32 mask;
} Table;
extern s32 fn_80281AE8(const char *, const char *);
s32 fn_8027DF20(Table *self, const char *name)
{
  int hash = 0;
  s32 key;
  s32 slot;
  const char *start = name;
  u32 *entries;
  u32 entry;
  while (((s8) (key = *((const u8 *) name))) != 0)
  {
    s32 character = (s8) key;
    hash = (hash << 5) - hash;
    hash = hash + character;
    name++;
  }

  key = ((u32) hash) & 0x7fffffffU;
  slot = key & self->mask;
  while (((entries = (u32 *) self->entries, entry = entries[slot], entry + 0x10000)) != 0xffffU)
  {
    if ((((u32) key) == entry) && (fn_80281AE8(start, (const char *) entries[(slot + self->mask) + 1]) == 0))
    {
      return slot;
    }
    slot = (slot + 1) & self->mask;
  }

  return self->mask + 1;
}
