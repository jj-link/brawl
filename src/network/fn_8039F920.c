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
typedef struct 
{
  char pad0[8];
  int offset;
  char padC[0x44];
  int field50;
  int field54;
  int field58;
  int field5C;
  int field60;
  int field64;
} State;
extern int lbl_805A1170;
extern int lbl_805A1190;
extern int lbl_8059FDC8;
extern int lbl_8059FDCC;
extern void *fn_80397748(void *, unsigned char, unsigned long);
extern int fn_80397640(void *);
extern void fn_80397DE0(int, int, ...);
extern int fn_8039DB88(int);
extern int fn_8039DBD0(int);
extern int fn_80398BD8(int, int, int);
int fn_8039F920(State *p)
{
  int buf = lbl_805A1170;
  int size = 0;
  int str = 0;
  int *new_var;
  int result;
  new_var = &buf;
  fn_80397748((void *) buf, 0, 0x400);
  str = fn_8039DB88(p->field60);
  if (str != 0)
  {
    fn_80397DE0(*new_var, lbl_8059FDC8, str);
    p->field50 = p->offset + 0x22;
    p->field54 = fn_80397640((void *) str) + 1;
    size = fn_80397640((void *) (*new_var));
    buf += size;
  }
  str = fn_8039DBD0(p->field64);
  if (str != 0)
  {
    fn_80397DE0(*new_var, lbl_8059FDCC, str);
    p->field58 = (size + p->offset) + 0x1B;
    p->field5C = fn_80397640((void *) str) + 1;
    size = size + fn_80397640((void *) (*new_var));
  }
  if (size == 0)
  {
    return 0;
  }
  result = fn_80398BD8(lbl_805A1170, size, lbl_805A1190);
  if (result == 0)
  {
    p->offset += size;
  }
  return result;
}
