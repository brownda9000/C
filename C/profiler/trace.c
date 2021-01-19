#include <stdio.h>
#include <locale.h>
#include <time.h>
 
static FILE *fp_trace;
 
void __attribute__ ((constructor))
trace_begin (void)
{
 fp_trace = fopen("trace.out", "w");
}
 
void __attribute__ ((destructor))
trace_end (void)
{
 if(fp_trace != NULL) {
 fclose(fp_trace);
 }
}
 
void __cyg_profile_func_enter (void *func,  void *caller)
{
    char buf[100];
    time_t t;
    struct tm *timeptr,result;

    t = time(NULL);
    timeptr = localtime(&t);
    strftime(buf,sizeof(buf), "%a %m/%d/%Y %r", timeptr);

 strptime(buf, "%a %m/%d/%Y %r",&result) ;
 if(fp_trace != NULL) {
 fprintf(fp_trace, "e %p %p %lu\n", func, caller, time(NULL) );
 }
}
 
void __cyg_profile_func_exit (void *func, void *caller)
{
 if(fp_trace != NULL) {
 fprintf(fp_trace, "x %p %p %lu\n", func, caller, time(NULL));
 }
}