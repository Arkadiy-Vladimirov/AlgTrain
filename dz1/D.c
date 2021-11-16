#include <stdio.h>

/*
  input: s:= \sigma ~-- permutation
  s = / a1,.. ak, b1,.. bl, .., d1,.. dm  x y \
      \ a2,.. a1, b2,.. b1, .., d2,.. d1  x y /, where a,b,.. d ~-- cycles.

  aim: s->id without:
     - repeated transpositions
     - transposing inside 'first part' of s (a1...dm)

  idea:
    a. cross swap:
      if we've got:
        / a b x y \
        \ b a x y /
      then we can do a cross swap:  
          a <-> x, b <-> y;
          b <-> x, a <-> y;
          x <-> y
      and end up with id.
    
    b. cycles elimination
      each permutaion is can be divided into cycles.
      we can eliminate each one like this:
        / a1,.. ak, x \  ->  / a1, a2,.. ak, x  \  ->  / a1, a2, a3,.. ak, x  \  ->       -> / a1,.. a_{k-1}, ak x  \
        \ a2,.. a1, x /  ->  \ x,  a3,.. a1, a2 /  ->  \ x,  a2, a4,.. a1, a3 /  ->  ...  -> \ x ,.. a_{k-1}, ak a1 /,
      and finish with situation a.

  algorithm:
  1.: x run through cycles: 
    x<->a1, x<->a2,.. x<->ak, x<->b1, ... x<->d_{m-1} (except last element of last cycle (dm))

    what we've got:
      / a1,.. ak, b1,.. bl, .., d1,.. dm  x y \
      \  x,.. ak, a1,.. bl, .., c1,.. d1 dm y /
    
    left unordered:
      / a1, b1,.., d1, dm  x y \
      \  x, a1,.., c1, d1 dm y /

  2.: y run backwards through emerged cycle:
    y<->dm, y<->d1,.. y<->b1, y<->a1 

      / a1, b1,.., d1, dm  x y \
      \ a1, b1,.., d1, y  dm x /

    left unordered:

      / dm  x y \
      \ y  dm x /

  3.: cross swap:
    x<->dm, x<->y

      / dm  x y \
      \ dm  x y /

    -> done!.
*/ 

int swap(int*, int*);
int swp_log(int a_idx, int b_idx, int log[][2], int* cnt);
int log_out(int log[][2], int cnt);
int test_out(int*, int);

int main(int argc, char **argv) {

  int N, M;
  int x, y;
  int i;
  int j, j_next, j_start, j_last;
  int not_id = 0; //not identity permutation = false
  int swps_cnt = 0;

  scanf("%d",&N);
  scanf("%d",&M);

  int s[N+1]; //id permutation
  int v[N+1]; //'visited' cells flags (to know which cycles are already eliminated)
  int swps[2*(N-1)+1][2]; //swps history (there are less then 2(N-1) + 1 swaps guranteed)
  s[0] = 0;   //fictitious element (not to count from 0)
  v[0] = 0;   //--||--
  
  for (i = 1; i < N+1; i++) {
    s[i] = i;
    v[i] = 0; //(not visited)
  }

  //construct initial permutation
  for (i = 0; i < M; i++) {
    scanf("%d", &x);
    scanf("%d", &y);
    swap(&s[x],&s[y]);
  }

  //non-triviality check
  i = 1;
while ((i < N-1) && (s[i] == i)) {
    i++;
  }




//__algorithm realization_______________________________  
  if (i < N-1) { //non-trivial case

  //step 1
    for (i = 1; i < N-1; i++) {
      if (i != s[i] && !v[i]) { //check if cycle is non-trivial and not visited

        j_start = j_next = j = i;

        do {

          j = j_next;
          j_next = s[j];

          swap(&s[j], &s[N-1]); //j <-> N-1
    
          v[j] = 1; //cell visited

          swp_log(j, N-1, swps, &swps_cnt); //record swap

        } while (s[N-1] != j_start); //until the end of cycle
      }
    }

  //undo last operation:
      swps_cnt--;
      j_last = j;
      swap(&s[j], &s[N-1]);

  //step 2
    while (s[N] != N-1) {
      j_next = s[j];
      swap(&s[j], &s[N]);
      swp_log(j, N, swps, &swps_cnt);
      j = j_next;
    }

  //step 3
    swap(&s[j_last],&s[N-1]);
    swp_log(j_last, N-1, swps, &swps_cnt);
    swap(&s[N-1],&s[N]);
    swp_log(N-1, N, swps, &swps_cnt);
  }
  //______________________________________________________

  log_out(swps, swps_cnt);
  
  return 0;
}




//__auxilary_functions____________________________________
int swap(int* a, int* b) {
  int c;
  c = *a;
  *a = *b;
  *b = c;
  return 0;
}

int swp_log(int a_idx, int b_idx, int log[][2], int* cnt) {
  log[*cnt][0] = a_idx;
  log[*cnt][1] = b_idx;
  *cnt = *cnt + 1;
  return 0;
}

int log_out(int log[][2], int cnt) {
  int i;
  for (i = 0; i < cnt; i++) {
    printf("%d ",log[i][0]);
    printf("%d\n",log[i][1]);
  }
  return 0;
}

int test_out(int *a, int n) {
  int i;
  for (i = 1; i < n+1; i++) {
    printf("%d ",a[i]);
  }
  printf("\n"); 
  return 0;
}
//________________________________________________________
//_______________Arkadiy_Vladimirov_______________________