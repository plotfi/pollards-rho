
/****************************************\
 *                 rho.c                *
 *               Puyan Lotfi            *
 *                gtg945h               *
 *        Math 3012: Ravi Montenegro    *
\****************************************/

#include <limits.h> /* for strtoll()                        */
#include <math.h>   /* include math libs                    */
#include <stdio.h>  /* include standard io                  */
#include <stdlib.h>
#include <unistd.h> /* for sleep()                          */
                    /* preprocesor directives               */
/*#define STEPS 0        count the number of steps            */
#define NO 0  /* this is here for fun                 */
#define YES 1 /* this is here for fun                 */
/*#define DEBUG 0        set to 1 for debug mode              */
/* function prototypes                  */
long long f(long long x, long long c, long long n);
long long gcd(long long a, long long n);
long long rho(long long n, long long c, long long x_0);

static long long steps = 0;

/* main()                               */

int main(int argc, char **argv) /* argv and argc              */
{                               /* local variables for main()           */
  long long retRho;

#ifdef PRMPT

  printf("The proper format is: \n\n"
         "%s n c x_0\n"
         "or\n"
         "%s n (c=1 and x_0=2 will be defaults).\n\n"
         "If you did not follow this format\n"
         "please enter ^C (Ctrl-C) and run again.\n"
         "If not, please wait 6 seconds... \n\n",
         argv[0], argv[0]);

  sleep(6);

#endif

  if (argc > 4) {
    fprintf(stderr, "Too many parameters.\n");
    return 1;
  } else if (4 == argc) {

    retRho = rho(strtoll(argv[1], (char **)NULL, 10),
                 strtoll(argv[2], (char **)NULL, 10),
                 strtoll(argv[3], (char **)NULL, 10));

    if (-1 < retRho) {
      printf("Entered n was: %lld.\n", strtoll(argv[1], (char **)NULL, 10));
      printf("The factor is: %lld.\n", retRho);
    }
  } else if (2 == argc) {
    retRho = rho(strtoll(argv[1], (char **)NULL, 10), 1, 2);

    if (-1 < retRho) {
      printf("Entered n was: %lld.\n", strtoll(argv[1], (char **)NULL, 10));
      printf("The factor is: %lld.\n", retRho);
    }
  } else if (2 < argc && argc < 4) {
    fprintf(stderr, "Not enough parameters.\n");
    return 1;
  } else {
    fprintf(stderr, "Please enter the proper number"
                    " of parameters.\n");
    return 1;
  }

  return 1;
}
/* rho()                                */
long long rho(long long n_, long long c_,
              long long x_0_) { /* local variables for rho()            */
  int done = NO;                /* not needed, but good practice        */
  long long n;                  /* number to be factored, out n         */
  long long c;                  /* this is c, which is usually set to 1 */
  long long x0;                 /* initial x, ususally set to 2         */
  long long xi;                 /* current x_i                          */
  long long x2i;                /* current x_2i                         */
  long long rho;                /* could be a factor, returned by gcd() */
                                /* end of local variables               */
  n = n_;                       /* set the local n to n_ passed in      */
  c = c_;                       /* set the local c to c_ passed in      */
  x0 = x_0_;                    /* set the local x0 to x_0_ passed in   */
  xi = f(x0, c, n);             /* setting x_1                          */
  x2i = f(f(x0, c, n), c, n);   /* setting x_2                   */
  rho = gcd(abs(x2i - xi), n);  /* getting the initial gcd    */

#ifdef STEPS
  steps = 1;
#endif

  /* begin iteration                      */
  while (!done) /* done never gets set, return main     */
  {
    if (1 < rho) /* greater than 1, so it is a factor    */
    {
#ifdef STEPS
      printf("Number of Steps: %lld\n", steps);
#endif
      return rho;        /* exit success            */
    } else if (0 == rho) /* tray again, may be prime       */
    {
      fprintf(stderr, "Failed, try a different c or x_0\n");
      return -1;         /* exit failure, try a different c or x */
    } else if (1 == rho) /* the value is 1, repeat part 3   */
    {
      xi = f(xi, c, n);            /* setting the new x_i         */
      x2i = f(f(x2i, c, n), c, n); /* setting the new x_2i*/
      rho = gcd(abs(xi - x2i), n); /* getting the gcd   */

#ifdef STEPS
      steps++;
#endif
    } else
      return -1;
    /* for |x_2i - x_i|  */
  } /* and n             */
  return -1;
}
/* f()                                   */
long long f(long long x, long long c, long long n) {
  return (x * x + c) % n; /* this is our f(x)                */
}
/* gcd()                                 */
long long gcd(long long a, long long n) {
  long long r;

  if (n > a) {
    r = a;
    a = n;
    n = r;
  } /*  just good coding practice  */

  while (n != 0) { /* Euclid's algorithm: essentially  */
    r = a % n;     /* you mod the previous mod by      */
    a = n;         /* by it's mod                      */
    n = r;         /* and repeat                       */

#ifdef DEBUG
    printf("gcd(): n is %lld\n", n);
#endif
  }

  return a; /* return gcd                       */
}
