#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX_SIZE 256
 
typedef struct {
    char weekday[4];
    int  month, day;
    int  hour, minutes;
    char away_team[4], home_team[4];
    int  away_score, home_score;
    int  specs;
} Match;
 
// Example line: Fri 2/12 6.00 AUS - USA 1-1 29534
int read_matches(const char *filename, Match *matches) {
    FILE *fin = fopen(filename, "r");
    if (!fin) {
        printf("Can't open file: %s\n", filename);
        return 0;
    }
    int i = 0;
    while (fscanf(fin, "%s %d/%d %d.%d %s - %s %d-%d %d", 
             matches[i].weekday,
            &matches[i].month,
            &matches[i].day,
            &matches[i].hour,
            &matches[i].minutes,
             matches[i].away_team,
             matches[i].home_team,
            &matches[i].away_score,
            &matches[i].home_score,
            &matches[i].specs) == 10)
        ++i;


    fclose(fin);
    return i;
}

void print_matches(Match *matches, int size) {
    for (int i = 0; i < size; ++i) {
        Match *m = &matches[i];
        printf("%s %2d/%2d %2d:%02d  %-3s - %-3s  %2d - %2d %6d\n",
            m->weekday, m->month, m->day,
            m->hour, m->minutes,
            m->away_team, m->home_team,
            m->away_score, m->home_score,
            m->specs);
    }
}
 
int main() {
    Match matches[MAX_SIZE];
    int size = read_matches("matches.txt", matches);
    print_matches(matches, size);
    return 0;
}
