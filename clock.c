#include <stdio.h>

int check(int low, int high, int checked,int checked1);
int checkrestict(int a, int b, int c,int target);

int main() {

    int h, m, s, a, b, low, med=-1 , high;
    scanf("%d %d %d %d %d", & h, & m, & s, & a, & b);

    if (h < 1 || h > 12 || m < 0 || m > 59 || s < 0 || s > 59 ||checkrestict(h,m,s,a)||checkrestict(h,m,s,b)|| a == b) { // ελενχω αν οι δεικτες ειναι ιδιοι (ωρες + λεπτα + δευτερολεπτα ή λεπτα και δευτερα ή δευτερα)
        printf("Wrong Input");
        return 0;
    }
    h *= 5;
    a *= 5; // μετατρέπω τις ώρες σε λεπτά (για να είναι ίδιο σύστημα αρίθμησης με λεπτά και δευτέρα (0->60))
    b *= 5;
    //printf("%d %d %d %d %d\n",h,m,s,a,b);

    low = h; // ταξινωμω τους δεικτες
    if (m < low)
        low = m;
    if (s < low)
        low = s;

    high = h;
    if (m > high)
        high = m;
    if (s > high)
        high = s;

    if (h >= low && h <= high) // και τον μεσο δείκτη (γιαυτό δεν κάνω την ωρα 0 αν ειναι 12, θελω παντα να εχω μεσαιο δεικτη)
        med = h;
    if (m >= low && m <= high)
        med = m;
    if (s >= low && s <= high)
        med = s;
    //printf("%d %d %d\n",low,med,high);
    //printf("last check: %d %d %d %d %d\n",h,m,s,a,b);
    if (check(low, med, a,b) || check(med, high, a,b)|| check(high, low + 60, a + 60,b)||check(high, low + 60, a,b+60))
        printf("Yes"); // τσεκάρω αν οι α, β βρίσκονται σε ενα απο τα διαστήματα [min, med] [med, max] , [max,min+60]
    else //στην τελευταία περίπτωση βάζω a+60 kai b+60 giati an einia px 9 kai o allos 1 prepei na einai sthn epomenh ora (ara +60) enas apo tous 2 kai epeidh den exw kanei taksinomish bazw kai tis 2 periptwseis
        printf("No");

    return 0;
}

int check(int low, int high, int checked,int checked1) {
    if ((low <= checked && checked <= high)&&(low<=checked1 && checked1<=high)) {
        //printf("%d %d\n",low,high);
        return 1;
    }else
        return 0;
}

int checkrestict(int a, int b, int c,int target) {
    if ((float)a*5+(float)b/100+(float)c/100==(float)target*5||(float)b+(float)c/100==(float)target*5||c==target*5) {
        //I turn it into float because just adding the minutes can result in wrong input
        return 1;// for example for input 3 15 15 it will pop wrong input if I just add them as minutes, so I turn it into float to add just a tiny fraction so its just not equal to the target
    }else
        return 0;
}



