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
int stricmp(const char *, const char *);
char *itoa(int value, char *str, int base);
void *memcpy(void *, const void *, size_t);
void *memset(void *, int, size_t);
void *memfill(const void *, int, size_t);
void *__memfill(const void *, int, size_t);
void *memmove(void *, const void *, size_t);
void *memchr(const void *, int, size_t);
void *__memrchr(const void *, int, size_t);
int memcmp(const void *, const void *, size_t);
char *strcpy(char *, const char *);
char *strncpy(char *, const char *, size_t);
char *strcat(char *, const char *);
char *strncat(char *, const char *, size_t);
int strcmp(const char *, const char *);
int strncmp(const char *, const char *, size_t);
char *strchr(const char *, int);
char *strstr(const char *, const char *);
size_t strlen(const char *);
extern int fn_803A685C(int, int *);
extern void *fn_803A6740(int, int);
extern void *fn_803A66DC(void);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern void fn_803A6828(int, void *, int);
extern int fn_803A6944(int, int);
void *fn_803A8068(char *arg0)
{
  int handle;
  char *new_var[2];
  long result;
  int size;
  void *ret = 0;
  if (fn_803A685C(0, &handle) == 0)
  {
    if (arg0 == 0)
    {
      result = -28;
    }
    else
    {
      result = strlen(arg0);
      size = result;
      size = (size + 32) & (~31);
      new_var[1] = fn_803A6740(12, size);
      new_var[0] = *((char **) (((char *) fn_803A66DC()) + 16));
      if (new_var[1] == 0)
      {
        result = -49;
      }
      else
      {
        strcpy(new_var[1], arg0);
        result = fn_80212D40(handle, 17, new_var[1], result + 1, new_var[0], 1120);
        if (result >= 0)
        {
          int delta = ((int) (new_var[0] + 16)) - (*((int *) new_var[0]));
          int *reloc = (int *) (new_var[0] + 832);
          while ((*reloc) != 0)
          {
            *reloc += delta;
            reloc++;
          }

          ret = new_var[0];
          *((int *) (new_var[0] + 4)) += delta;
          *((int *) new_var[0]) += delta;
          *((int *) (new_var[0] + 12)) += delta;
        }
        fn_803A6828(12, new_var[1], size);
      }
    }
    fn_803A6944(0, result);
  }
  return ret;
}
