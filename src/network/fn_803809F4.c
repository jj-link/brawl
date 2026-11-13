
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
int abs(int);
int mbtowc(wchar_t *, const char *, size_t);
size_t mbstowcs(wchar_t *, const char *, size_t);
size_t wcstombs(char *, const wchar_t *, size_t);
int rand(void);
double atof(const char *);
int atoi(const char *str);
#pragma force_active on
extern char lbl_8059FA98[8];
extern char lbl_804908D0[0x70];
extern char lbl_8059FAA0[3];
extern char lbl_8059FAA4[2];
extern char *fn_8035D654(const char *);
typedef struct 
{
  char pad[0x14];
  char *url;
  char *host;
  char pad1[4];
  unsigned short port;
  char pad2[2];
  char *path;
  int secure;
} Request;
int fn_803809F4(Request *arg0)
{
  char *new_var2[2];
  char c;
  char **new_var;
  int len;
  if (arg0 == 0)
  {
    return 0;
  }
  new_var2[0] = arg0->url;
  if (new_var2[0] == 0)
  {
    return 0;
  }
  if (strncmp(new_var2[0], lbl_8059FA98, 7) == 0)
  {
    new_var2[1] = new_var2[0] + 7;
    arg0->secure = 0;
  }
  else
    if (strncmp(new_var2[0], lbl_804908D0, 8) == 0)
  {
    new_var2[1] = new_var2[0] + 8;
    arg0->secure = 1;
  }
  else
    if (arg0 || len)
  {
    return 0;
  }
  else
  {
    return 0;
  }
  len = strcspn(new_var2[1], lbl_8059FAA0);
  c = new_var2[1][len];
  new_var2[1][len] = 0;
  arg0->host = fn_8035D654(new_var2[1]);
  if ((*(new_var = &arg0->host)) == 0)
  {
    return 0;
  }
  new_var2[1][len] = c;
  new_var2[1] += len;
  if ((*new_var2[1]) == ':')
  {
    new_var2[1]++;
    arg0->port = atoi(new_var2[1]);
    if (arg0->port == 0)
    {
      return 0;
    }
    do
    {
      new_var2[1]++;
    }
    while (((*new_var2[1]) != 0) && ((*new_var2[1]) != '/'));
  }
  else
    if (arg0->secure == 1)
  {
    arg0->port = 443;
  }
  else
  {
    arg0->port = 80;
  }
  if ((*new_var2[1]) == 0)
  {
    new_var2[1] = lbl_8059FAA4;
  }
  arg0->path = fn_8035D654(new_var2[1]);
  while ((new_var2[1] = strchr(new_var2[0] = arg0->path, ' ')) != 0)
  {
    *new_var2[1] = '+';
  }

  return new_var2[0] != 0;
}
