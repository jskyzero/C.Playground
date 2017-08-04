C标准函数库简介

# C library

[TOC]

## C90



## assert.h C Diagnostics Library 

```C
void assert (int expression);
```

## ctype.h Character handling functions 

```c
int isdigit ( int c );
int islower ( int c );
int toupper ( int c );
```

## errno.h C Errors 

[**errno**](http://www.cplusplus.com/reference/cerrno/errno/) Last error number (macro )

## float.h Characteristics of floating-point types 

FLT_MAX DBL_MAX LDBL_MAX 

FLT_EPSILON DBL_EPSILON LDBL_EPSILON

## iso646.h

| macro  | operator |
| ------ | -------- |
| and    | &&       |
| and_eq | &=       |
| bitand | &        |
| bitor  | \|       |
| compl  | ~        |
| not    | !        |
| not_eq | !=       |
| or     | \|\|     |
| or_eq  | \|=      |
| xor    | ^        |
| xor_eq | ^=       |

| FLT_MAX   DBL_MAX  LDBL_MAX            | `1E+37` or greater `1E+37` or greater  `1E+37` or greater | MAXimum | Maximum finite representable floating-point number. |
| -------------------------------------- | ---------------------------------------- | ------- | ---------------------------------------- |
| FLT_EPSILON  DBL_EPSILON  LDBL_EPSILON | `1E-5` or smaller `1E-9` or smaller                                  `1E-9` or smaller |         | Difference between 1 and the least value greater than 1 that is representable. |

## limits.h

CHAR_BIT INT_MAX LLONG_MIN

## locale.h

[**struct lconv**](http://www.cplusplus.com/reference/clocale/lconv/) [**setlocale**](http://www.cplusplus.com/reference/clocale/setlocale/) [**localeconv**](http://www.cplusplus.com/reference/clocale/localeconv/) 

## math.h

cos, acos , cosh

log, log10

pow sqrt

ceil floor

abs

## setjmp.h

```c
/* longjmp example */
#include <stdio.h>      /* printf */
#include <setjmp.h>     /* jmp_buf, setjmp, longjmp */



main()
{
  jmp_buf env;
  int val;

  val=setjmp(env);

  printf ("val is %d\n",val);

  if (!val) longjmp(env, 1);

  return 0;
}
```

## signal.h

`Some running environments use *signals* to inform running processes of certain events.`

```c
/* signal example */
#include <stdio.h>      /* printf */
#include <signal.h>     /* signal, raise, sig_atomic_t */



sig_atomic_t signaled = 0;

void my_handler (int param)
{
  signaled = 1;
}

int main ()
{
  void (*prev_handler)(int);

  prev_handler = signal (SIGINT, my_handler);

  /* ... */
  raise(SIGINT);
  /* ... */
  
  printf ("signaled is %d.\n",signaled);
  

  return 0;
}
```

## stdarg.h

- [**va_start**](http://www.cplusplus.com/reference/cstdarg/va_start/)

  Initialize a variable argument list (macro )


- [**va_arg**](http://www.cplusplus.com/reference/cstdarg/va_arg/)

  Retrieve next argument (macro )


- [**va_end**](http://www.cplusplus.com/reference/cstdarg/va_end/)

  End using variable argument list (macro )


- [**va_copy **](http://www.cplusplus.com/reference/cstdarg/va_copy/)

  Copy variable argument list (macro )

## stddef.h

- [**ptrdiff_t**](http://www.cplusplus.com/reference/cstddef/ptrdiff_t/)

  Result of pointer subtraction (type )


- [**size_t**](http://www.cplusplus.com/reference/cstddef/size_t/)

  Unsigned integral type (type )

## stdio.h

## stdlib.h

## string.h

## time.h

#### Time manipulation

- [**clock**](http://www.cplusplus.com/reference/ctime/clock/)

  Clock program (function )


- [**difftime**](http://www.cplusplus.com/reference/ctime/difftime/)

  Return difference between two times (function )


- [**mktime**](http://www.cplusplus.com/reference/ctime/mktime/)

  Convert tm structure to time_t (function )


- [**time**](http://www.cplusplus.com/reference/ctime/time/)

  Get current time (function )

#### Conversion

- [**asctime**](http://www.cplusplus.com/reference/ctime/asctime/)

  Convert tm structure to string (function )


- [**ctime**](http://www.cplusplus.com/reference/ctime/ctime/)

  Convert time_t value to string (function )


- [**gmtime**](http://www.cplusplus.com/reference/ctime/gmtime/)

  Convert time_t to tm as UTC time (function )


- [**localtime**](http://www.cplusplus.com/reference/ctime/localtime/)

  Convert time_t to tm as local time (function )


- [**strftime**](http://www.cplusplus.com/reference/ctime/strftime/)

  Format time as string (function )

## Reference

[cplusplus.com](http://www.cplusplus.com/reference/clibrary/)

