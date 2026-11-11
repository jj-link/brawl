
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
#pragma force_active on
extern int fn_803A685C(int, int *);
extern int fn_803A66E8(void);
extern void *fn_803A6740(int, int);
extern void fn_803A6828(int, void *, int);
extern int fn_803A6944(int, int);
extern int fn_80213090(int, int, int, int, void *);
typedef struct 
{
  int socket;
  int flags;
  int hasAddress;
  unsigned char address[28];
} SendParameters;
typedef struct 
{
  void *buffer;
  int length;
  SendParameters *parameters;
  int parametersLength;
  unsigned char padding[16];
  SendParameters data;
} SendRequest;
void fn_803A7DC4(int context, int socket, const void *buffer, int length, int flags, const unsigned char *address)
{
  int handle;
  int result;
  int direct;
  SendParameters *parameters;
  int accessible;
  int *new_var;
  void *message;
  SendRequest *request;
  if (fn_803A685C(context, &handle) == 0)
  {
    if ((address != 0) && ((address[0] > 8U) || (address[0] < 8U)))
    {
      result = -28;
    }
    else
      if ((length < 0) || ((length > 0) && (buffer == 0)))
    {
      result = -28;
    }
    else
    {
      direct = 1;
      if (length != 0)
      {
        int aligned;
        result = 0;
        aligned = 0;
        new_var = &result;
        if (((((unsigned int) buffer) & 31) == 0) && ((length % 32) == 0))
        {
          aligned = 1;
        }
        if (aligned != 0)
        {
          accessible = 1;
          if (fn_803A66E8() != 0)
          {
            unsigned int physical = ((unsigned int) buffer) & 0x1FFFFFFF;
            int inRange = 0;
            if ((physical >= 0x10000000U) && (physical < 0x18000000U))
            {
              inRange = 1;
            }
            if (inRange == 0)
            {
              accessible = 0;
            }
          }
          if (accessible != 0)
          {
            result = 1;
          }
        }
        if ((*new_var) == 0)
        {
          direct = 0;
        }
      }
      request = fn_803A6740(12, 96);
      if (direct == 0)
      {
        message = fn_803A6740(14, (length + 31) & (~31));
      }
      else
      {
        message = (void *) buffer;
      }
      if ((request == 0) || (message == 0))
      {
        result = -49;
      }
      else
      {
        request->data.socket = socket;
        parameters = &request->data;
        request->data.flags = flags;
        if (address == 0)
        {
          parameters->hasAddress = 0;
        }
        else
        {
          parameters->hasAddress = 1;
          memcpy(parameters->address, address, address[0]);
        }
        if (direct == 0)
        {
          memcpy(message, buffer, length);
        }
        request->buffer = message;
        request->length = length;
        request->parameters = parameters;
        request->parametersLength = 40;
        result = fn_80213090(handle, 13, 2, 0, request);
      }
      if (direct == 0)
      {
        fn_803A6828(14, message, (length + 31) & (~31));
      }
      fn_803A6828(12, request, 96);
    }
    fn_803A6944(context, *new_var);
  }
}
