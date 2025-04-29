#include <stdio.h>

struct Event {
    char name;
    int start, end;
};

void swap(struct Event *a, struct Event *b) {
    struct Event temp = *a;
    *a = *b;
    *b = temp;
}
void sorting(struct Event events[], int n){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n-i-1; j++){
            if (events[j].end > events[j+1].end){
                swap(&events[j], &events[j+1]);
            }
        }
    }
}

void scheduling(struct Event events[], int n){
    sorting(events, n);

    printf("The events are scheduled as follows:\n");
    int count = 0;
    int last_end_time = 0;

    for (int i=0; i<n; i++){
        if (events[i].start >= last_end_time){
            printf("%c ", events[i].name);
            last_end_time = events[i].end;
            count++;
        }
    }
    printf("\nTotal number of events scheduled: %d\n", count);

}

int main(){
    int n = 4;
    struct Event events[] = {
        {'B', 2, 4},
        {'A', 1, 3},
        {'D', 4, 6},
        {'C', 3, 5}
    };
    scheduling(events, n);
    return 0;
}