#include<stdio.h>
#include<math.h>
#include<ctype.h>
int main()
{
    char first_name[10];
    char last_name[10];
    char gender;
    int birth_year ;
    int birth_month;
    int birth_day;
    char weekday[10];
    int c_score =50;
    int music_score =99;
    int medicine_score = 78;

   

    double mean=(c_score+music_score+medicine_score)/3.0;
    double sd = sqrt(((pow(c_score-mean,2)
    +pow(music_score-mean,2)
    +pow(medicine_score,2)))/3.0);
    int rank;
     scanf("%s%s %c %d-%d-%d %s %d%d%d %lf%lf %d%%",first_name,last_name,&gender,
    &birth_year,&birth_month,&birth_day,weekday,
    &c_score,&music_score,&medicine_score,
    &mean,&rank);
    
    printf("%s %s \t %c\n"
    "%.2d-%d-%d \t %.3s.\n"
    "%d\t %d\t %d\n"
    "%.1f\t %.2f \t%d%%\n"

    ,first_name,last_name,toupper(gender),
    birth_month,birth_day,birth_year,weekday,
    c_score ,
    music_score,
    medicine_score,
    mean , sd,rank);

    return 0;
    

}