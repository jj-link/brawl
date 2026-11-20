#pragma force_active on

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
struct Item
{
  char pad[0x14];
  int value;
};
struct Obj
{
  int unk0;
  int unk4;
  int count;
  int countC;
  int pad10;
  int pad14;
  int unk18;
  int flags[149];
  struct Item *items1[12];
  struct Item *items2[86];
  struct Item *unk3F8;
};
extern void fn_80278C34(void *);
extern const int lbl_8040E738[24];
extern const int lbl_8040E798[0x25][4];
inline static int find738(struct Obj *self, int id)
{
  const int *e = lbl_8040E738;
  int k;
  for (k = 0; k < self->countC; k++)
  {
    if ((id == e[0]) && (e[1] == 2))
      return k;
    e += 2;
  }

  return -1;
}

inline static int find798(int key)
{
  const int *e = &lbl_8040E798[0][0];
  int j;
  for (j = 0; j < 0x4a; j++)
  {
    if ((e[0] == 5) && (e[1] == key))
      return j;
    e += 2;
  }

  return -1;
}

inline struct Item *inline_fn(struct Item **arg0, int arg1)
{
  return arg0[arg1];
}

inline struct Item *inline_fn2(struct Obj *arg0)
{
  return arg0->unk3F8;
}

void fn_80277F90(struct Obj *self)
{
  struct Item *item;
  int i;
  int idx;
  for (i = 0; i < self->count; i++)
  {
    if (self->flags[i] != 0)
    {
      idx = find738(self, i);
      item = inline_fn(self->items1, idx);
      fn_80278C34(item);
      item->value = 1;
      self->flags[i] = 0;
    }
  }

  if (self->flags[self->count] != 0)
  {
    item = inline_fn2(self);
    fn_80278C34(item);
    item->value = 1;
    self->flags[self->count - (-1)] = 0;
  }
  if (self->flags[self->count + 1] != 0)
  {
    if (self->unk0 == 1)
    {
      if (self->unk18 == 0)
      {
        idx = find798(0x14);
        item = inline_fn(self->items2, idx);
        fn_80278C34(item);
        item->value = 1;
        self->flags[self->count] = 0;
      }
    }
    else
    {
      idx = find798(3);
      item = inline_fn(self->items2, idx);
      fn_80278C34(item);
      item->value = 1;
      self->flags[self->count] = 0;
    }
  }
}
