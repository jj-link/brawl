
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
typedef struct FILE
{
  u8 dummy;
} FILE;
int fclose(FILE *);
int fflush(FILE *);
long int ftell(FILE *);
int vprintf(const char *, va_list);
int sprintf(char *, const char *, ...);
int snprintf(char *, size_t, const char *, ...);
int vsprintf(char *, const char *, va_list);
int vsnprintf(char *, size_t, const char *, va_list);
int sscanf(const char *, const char *, ...);
int fwide(FILE *, int);
#pragma force_active on
extern char lbl_80490940[];
extern char lbl_804942B8[];
typedef struct 
{
  u8 pad[0x3c];
  int err;
  u8 pad2[0x60];
  u8 *text;
  u8 pad3[0x68];
  int major;
  int minor;
  int status;
  int offset;
  u8 pad4[4];
  int failed;
} Obj;
typedef struct 
{
  u8 pad[8];
  u16 *map;
} CTypeTab;
int fn_803815CC(Obj *obj)
{
  int major;
  u16 **new_var2;
  int minor;
  int status;
  int offset;
  CTypeTab *tab;
  unsigned int c;
  int new_var;
  new_var = 0x38;
  if ((((sscanf((char *) obj->text, lbl_80490940, &major, &minor, &status, &offset) != 3) || (major < 1)) || (status < 100)) || (status >= 600))
  {
    obj->failed = 1;
    obj->err = 7;
    return 0;
  }
  tab = *((CTypeTab **) (lbl_804942B8 + new_var));
  new_var2 = &tab->map;
  for (; (((s8) (c = obj->text[offset])) != 0) && (((((s8) c) < 0) || (((s8) c) >= 0x100)) ? (0) : ((*new_var2)[(s8) c] & 0x100)); offset++)
  {
    ;
  }

  obj->major = major;
  obj->minor = minor;
  obj->status = status;
  obj->offset = offset;
  return 1;
}
