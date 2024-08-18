#include<stdio.h>
#include<string.h>
#include <stdlib.h>
//declaring job seeker profile array
struct job_seeker_comparision{
  char username[100];
  char name[90];
  int age;
  char gender[30];
  char recent_job[20];
  int work_experience;
  char jobs[100];
  int expected_salary;
  char shift[100];
  int work_place;
  int choice[2];
  char locality[100];
}jc[1000];

//declaring talent accquisition profile array
struct talent_acquisition_comparision{
  char company_name[100];
  char username[100];
  char jobs[100];
  int min_age;
  char gender[50];
  int work_experience;
  int work_place;
  char shift[100];
  int choice[4];
  int salary;
  double percentage;
  char address[100];
}tc[1000];

//declaring the structure array for jobseerker profile comparision 
typedef struct sk {
  char name[100];
  char username[100];
  int age;
  char gender[100];
  char locality[800];
  char recent_job[200];
  int work_experience;
  int n;
  char jobs[300];
  int expected_salary;
  char shift[300];
  int work_place;
  int choice[2];
  char qualifications[100];
}seeker;

//declaring structure array for talent acquisition profile comparision
typedef struct tc{
  char company_name[100];
  char username[100];
  char address[200];
  char about_company[500];
  int numof_jobs;
  char jobs[100];
  int min_age;
  char gender[30];
  int work_experience;
  int starting_salary;
  char shift[50];
  int work_place,i;
  int choice[4];
}talent;

// delcaring a structure array for displaying job seeker recper 
struct display_seeker{
  char username[40];
  char job[50];
  char company_name[60];
  float rec_per;
}ds[100];

//declaring a structure array for displaying talent acquisition recper
struct display_talent{
  char company_username[15];
  char jobs[15];
  char seeker_username[15];
  float rec_per;
}dt[100];

//declaring structure array for sorting the contents of the file job_seeker_recper
struct dp {
    char un[50];
    char jb[50];
    char cn[50];
    float per;
} dp1[1000];

//declaring the structure array for sorting the contents of the file talent_acquisition_recper
struct dt {
    char un1[50];
    char jb1[50];
    char sn[50];
    float per1;
} dt1[1000];

//prototype declaration of the functions called 
void login();
void signup();
void signup_1();
void login_1();
void seeker_profile();
void talent_acquisition();
void comparison(struct job_seeker_comparision jc[1000],struct talent_acquisition_comparision tc[1000]);
void display_seeker();
void display_talent();
void swap_s(struct dp *a, struct dp *b);
void bubbleSort_s(struct dp arr[], int n);
void swap_t(struct dt *a, struct dt *b);
void bubbleSort_t(struct dt arr[], int n);

//main function
int main(){
  int choice,choice_2;
  int count=0;
  FILE *f1;
  FILE *f;
  FILE *f3;
  FILE *f4;
  flag3:
  printf("enter whether you are a job seeker(0)\ntalent acquisition(1): ");
  scanf("%d",&choice);
  if(choice==0){
    flag:
    fflush(stdin);
    printf("if already existing user enter 1\nenter 2 for sign in: ");
    scanf("%d",&choice_2);
    if (choice_2==1){
      login();
      comparison(jc,tc);
      display_seeker();
    }
    else if(choice_2==2){
      signup();
      seeker_profile();
      comparison(jc,tc);
      display_seeker();
    }
    else{
      printf("u have entered unavailable choice\nplease enter the correct choice");
      goto flag;
    }
  }
  else if(choice==1){
    flag2:
    printf("if already existing user enter 1 \nenter 2 for sign in: ");
    scanf("%d",&choice_2);
    if (choice_2==1){
      login_1();
      comparison(jc,tc);
      display_talent();
    }
    else if(choice_2==2){
      signup_1();
      talent_acquisition();
      comparison(jc,tc);
      display_talent();
    }
    else{
      printf("u have entered unavailable choice\nplease enter the correct choice");
      goto flag2;
    }
  }
  else{
    printf("enter the correct choice");
    goto flag3;
  }
  return 0;

}

//login function for job seekers
void login(){

  char a[100];
  char un[100],pwd[100];
  flag1:
  fflush(stdin);
  printf("enter the username:");
  scanf("%s",un);
  fflush(stdin);
  printf("enter the password:");
  scanf("%s",pwd);
  FILE *f1;
  f1=fopen("details.txt","r");
  char *un1,*pwd1;
  int z=0;
  while(fscanf(f1,"%s",a)!=EOF){
    un1=strtok(a,",");
    pwd1=strtok(NULL,",");
    if(strcmp(un1,un)==0&&strcmp(pwd1,pwd)==0){
      printf("login sucessfull\n");
      z=1;
      break;

    }

  }
  fclose(f1);
  if(z==0){
     printf("acesss denied\n");
      goto flag1;
  }

}

//sign_up function for job seekers
void signup(){

  char username[50];
  char password[50];
  char s[100];
  flag:
  fflush(stdin);
  printf("create a new username:");
  scanf("%s",username);
  fflush(stdin);
  printf("create a new password:");
  scanf("%s",password);
  FILE *f;
  f=fopen("details.txt","a+");
  char *un;
  if(f!=NULL) {
    while(fgets(s,95,f)) {
      un=strtok(s,",");
      if(strcmp(username,un)==0){
        printf("username already exist\n");
        goto flag;
      }
    }
    printf("succesfully signed in!\n");
    fprintf(f,"%s,%s\n",username,password);
  }
  else
      printf("Error in opening the file");
  fclose(f);

}

//login function for talent acquisitiors
void login_1(){

  char a[100];
  char un[100],pwd[100];
  flag1:
  printf("enter the username:");
  scanf("%s",un);
  printf("enter the password:");
  scanf("%s",pwd);
  FILE *f2;
  f2=fopen("details_1.txt","r");
  char *un1,*pwd1;
  int z=0;
  while(fscanf(f2,"%s",a)!=EOF){
    un1=strtok(a,",");
    pwd1=strtok(NULL,",");
    if(strcmp(un1,un)==0&&strcmp(pwd1,pwd)==0){
      printf("login sucessfull\n");
      z=1;
      break;

    }

  }
  if(z==0){
     printf("acesss denied\n");
      goto flag1;
  }

}

//sign_up function for talent acquisitors
void signup_1(){

  char username[50];
  char password[50];
  char s[100];
  flag:
  //printf("hi");
  printf("create a new username:");
  scanf("%s",username);
  printf("create a new password:");
  scanf("%s",password);
  FILE *f3;
  f3=fopen("details_1.txt","a+");
  char *un;
  if(f3!=NULL) {
  while(fgets(s,95,f3)) {
    un=strtok(s,",");
    if(strcmp(username,un)==0){
      printf("username already exist\n");
      goto flag;
    }

  }
    printf("succesfully signed in!\n");
    fprintf(f3,"%s,%s\n",username,password);

  }


}

//job seeker profile
void seeker_profile(){
  seeker sk;
  FILE *f;
  FILE *f1;
  f=fopen("job_seeker_profile.txt","a");
  fflush(stdin);
  printf("NAME:");
  scanf("%s",sk.name);
  printf("USERNAME:");
  scanf("%s",sk.username);
  printf("AGE:");
  scanf("%d",&sk.age);
  fflush(stdin);
  printf("GENDER:");
  scanf("%s",sk.gender);
  fflush(stdin);
  printf("LOCALITY(city,country):");
  scanf("%s",sk.locality);
  fflush(stdin);
  printf("RECENT JOB:");
  scanf("%s",sk.recent_job);
  fflush(stdin);

  printf("NO.OF JOBS TO BE APPLIED FOR:");
  scanf("%d",&sk.n);
  for(int i=0;i<sk.n;i+=1){
    printf("JOBS:");
    scanf("%s",sk.jobs);
    printf("WORK EXPERIENCE(in years):");
    scanf("%d",&sk.work_experience);
    printf("EXPECTED SALARY:");
    scanf("%d",&sk.expected_salary);
    printf("SHIFT:");
    scanf("%s",sk.shift);
    printf("0 FOR NON-MANDATORY ELSE ANYOTHER ENTRY WILL BE CONSIDERDED MANDATORY:");
    scanf("%d",&sk.choice[0]);
    printf("WORK PLACE(0 for work from home):");
    scanf("%d",&sk.work_place);
    printf("0 FOR NON-MANDATORY ELSE ANYOTHER ENTRY WILL BE CONSIDERDED MANDATORY:");
    scanf("%d",&sk.choice[1]);
    fprintf(f,"%s %s %d %s %s %s %s %d %d %s %d %d %d\n",sk.name,sk.username,sk.age,sk.gender,sk.locality,sk.recent_job,sk.jobs,sk.work_experience,sk.expected_salary,sk.shift,sk.choice[0],sk.work_place,sk.choice[1]);
  }
  fclose(f);
  //comparision(sk,)
}

//talent acquisitor's profile
void talent_acquisition(){
  talent tc;
  FILE *f1;
  FILE*f2;
  f1=fopen("talent_aquisitiors_profile.txt","a+");
  f2=fopen("jobs.txt","a+");
  fflush(stdin);
  printf("COMPANY NAME:");
  scanf("%s",tc.company_name);
  printf("USERNAME:");
  scanf("%s",tc.username);
  printf("ADDRESS:");
  scanf("%s",tc.address);
  printf("NO.OF JOBS TO BE POSTED:");
  scanf("%d",&tc.numof_jobs);
  for(int i=0;i<tc.numof_jobs;i+=1){
    printf("JOB TITLE:");
    scanf("%s",tc.jobs);
    printf("MINIMUM AGE REQUIRED:");
    scanf("%d",&tc.min_age);
    printf("PREFERRED GENDER:");
    scanf("%s",tc.gender);
    printf("0 FOR NON-MANDATORY ELSE ANYOTHER ENTRY WILL BE CONSIDERDED MANDATORY:");
    scanf("%d",&tc.choice[0]);
    printf("MINIMUM WORK EXPERIENCE REQUIRED:");
    scanf("%d",&tc.work_experience);
    printf("0 FOR NON-MANDATORY ELSE ANYOTHER ENTRY WILL BE CONSIDERDED MANDATORY:");
    scanf("%d",&tc.choice[1]);
    printf("STARTING SALARY:");
    scanf("%d",&tc.starting_salary);
    printf("SHIFT:");
    scanf("%s",tc.shift);
    printf("0 FOR NON-MANDATORY ELSE ANYOTHER ENTRY WILL BE CONSIDERDED MANDATORY:");
    scanf("%d",&tc.choice[2]);
    printf("WORK PLACE(0 for work from home):");
    scanf("%d",&tc.work_place);
    printf("0 FOR NON-MANDATORY ELSE ANYOTHER ENTRY WILL BE CONSIDERDED MANDATORY:");
    scanf("%d",&tc.choice[3]);
    //printf("%d",tc.choice[3]);
    fprintf(f2,"%s\n",tc.jobs);
    fprintf(f1,"%s %s %s %s %d %s %d %d %d %d %s %d %d %d\n",tc.company_name,tc.username,tc.address,tc.jobs,tc.min_age,tc.gender,tc.choice[0],tc.work_experience,tc.choice[1],tc.starting_salary,tc.shift,tc.choice[2],tc.work_place,tc.choice[3]);
  }
  fclose(f1);
  fclose(f2);
}

//comparision module
void comparison(struct job_seeker_comparision jc[1000], struct talent_acquisition_comparision tc[1000]){
  int i, j, s1, s2, s3, s4, s5, s6, score;
  FILE *f1;
  FILE *f2;
  FILE *f3;
  FILE *f4;
  f1 = fopen("job_seeker_profile.txt", "r");
  f2 = fopen("talent_aquisitiors_profile.txt","r");
  f3 = fopen("job_seeker_recper.txt", "w+");
  f4 = fopen("talent_acquisition_recper.txt", "w+");
  if (f1 == NULL || f3 == NULL || f2 == NULL) {
    printf("Error in opening file(s).\n");

  }
  else{
  //printf("hi");
  int min_age1, c0, c1, c2, c3, we1, salary1, workplace;
  char job1[100], gender1[100], shift1[100], b[100],username1[50],name1[50],locality1[100];
  int count=0;
  while (fscanf(f2,"%s %s %s %s %d %s %d %d %d %d %s %d %d %d",tc[count].company_name,tc[count].username,tc[count].address,tc[count].jobs,&tc[count].min_age,tc[count].gender,&tc[count].choice[0],&tc[count].work_experience,&tc[count].choice[1],&tc[count].salary,tc[count].shift,&tc[count].choice[2],&tc[count].work_place,&tc[count].choice[3])!=EOF) {
    // Tokenize the line and extract data
  count+=1;


    }
  int q=count;
  int age,salary,workplace1,ch0,ch1;
  char a[30],username[30],gen[30],locality[30],recentjob[30],job[30],shift[30],name[30];
  int we;
  int count_2=0;
  while (fscanf(f1,"%s %s %d %s %s %s %s %d %d %s %d %d %d",jc[count_2].name,jc[count_2].username,&jc[count_2].age,jc[count_2].gender,jc[count_2].locality,jc[count_2].recent_job,jc[count_2].jobs,&jc[count_2].work_experience,&jc[count_2].expected_salary,jc[count_2].shift,&jc[count_2].choice[0],&jc[count_2].work_place,&jc[count_2].choice[1])!=EOF) {
    // Tokenize the line and extract data
    count_2+=1;
    }
    //printf("%d\n",count_2);
    int e=count_2;
    float percentage=0;


    for (i = 0; i < e; i++) {
        for (j = 0; j < q; j++) {
            if (strcmp(jc[i].jobs,tc[j].jobs) == 0) {
              //printf("hi");

              if (jc[i].age >= tc[j].min_age) {
                s1 = 4;
              }
              else {
                s1 = 2;
              }
              if (strcmp(jc[i].gender, tc[j].gender) == 0) {
                s2 = 9;
              }
              else if (tc[j].choice[0] == 0) {
                s2 = 9;
              }
              else {
                s2 = 3;
              }
              if (jc[i].expected_salary <= tc[j].salary) {
                s3 = 16;
              }
              else {
                s3 = 8;
              }
              if (strcmp(jc[i].shift, tc[j].shift) == 0) {
                s4 = 16;
              }
              else if (jc[i].choice[0] == 0 && tc[j].choice[2] == 0) {
                s4 = 16;
              }
              else {
                s4 = 4;
              }
              if (jc[i].work_experience >= tc[j].work_experience) {
                s5 = 9;
              }
              else if (tc[j].choice[1] == 0) {
                s5 = 9;
              }
              else {
                s5 = 6;
              }
              if (jc[i].work_place == tc[j].work_place) {
                s6 = 16;
              }
              else if (tc[j].choice[3] == 0) {
                s6 = 16;
              }
              else{
                s6 = 4;
              }
              //printf("\nhio");
              score = s1 + s2 + s3 + s4 + s5 + s6;
              percentage = (score / 70.0) * 100.0;

            fprintf(f3,"%s %s %s %f\n",jc[i].username,jc[i].jobs,tc[j].company_name,percentage);
            fprintf(f4,"%s %s %s %f\n",tc[j].username,tc[j].jobs,jc[i].username,percentage);

            }
        }

    }
  }

    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);

}

//swapping the contents of the job_seeker_recper file
void swap_s(struct dp *a, struct dp *b) {
    struct dp temp = *a;
    *a = *b;
    *b = temp;
}

//sorting the contents of the job_seeker_recper file
void bubbleSort_s(struct dp arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].per < arr[j + 1].per) {
                swap_s(&arr[j], &arr[j + 1]);
            }
        }
    }
}

//display module for job seeker
void display_seeker()
{
      FILE *file_s = fopen("job_seeker_recper.txt", "r");
    if (file_s == NULL) {
        printf("Failed to open the file.\n");
    }

    int count = 0;
    while (fscanf(file_s, "%s %s %s %f", dp1[count].un, dp1[count].jb, dp1[count].cn, &dp1[count].per) != EOF) {
        count++;
    }
    fclose(file_s);

    bubbleSort_s(dp1, count);

    file_s = fopen("job_seeker_recper.txt", "w");
    if (file_s == NULL) {
        printf("Failed to open the file.\n");
    }

    for (int i = 0; i < count; i++) {
        fprintf(file_s, "%s %s %s %f\n", dp1[i].un, dp1[i].jb, dp1[i].cn, dp1[i].per);
    }

    fclose(file_s);


      FILE *f3;
      f3 = fopen("job_seeker_recper.txt", "r");
      //char us[10],z1[10],j1[10],cn1[10];
      //float per1;
      char us[15];
      printf("ENTER THE USERNAME  :");
      scanf("%s",us);
      int rand=0;
      printf("\n__________________________________________________________________________________________\n");
      printf("job                           company's_name                             percentage\n");
      while(fscanf(f3,"%s %s %s %f",ds[rand].username,ds[rand].job,ds[rand].company_name,&ds[rand].rec_per)!=EOF)
      {

        if(strcmp(us,ds[rand].username)==0)
        {


            printf("\n%s                    %12s                                     %9f",ds[rand].job,ds[rand].company_name,ds[rand].rec_per);
        }
        rand+=1;
      }
      printf("\n__________________________________________________________________________________________\n");
    fclose(f3);
}

//swapping the contents of the talent_acquisition_recper file
void swap_t(struct dt *a, struct dt *b) {
    struct dt temp = *a;
    *a = *b;
    *b = temp;
}

//sorting the contents of the talent_acquisition_recper file
void bubbleSort_t(struct dt arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].per1 < arr[j + 1].per1) {
                swap_t(&arr[j], &arr[j + 1]);
            }
        }
    }
}

//display module for talent acquisitiors
void display_talent(){
      FILE *file_t = fopen("talent_acquisition_recper.txt", "r");
    if (file_t == NULL) {
        printf("Failed to open the file.\n");
      
    }

    int count = 0;
    while (fscanf(file_t, "%s %s %s %f", dt1[count].un1, dt1[count].jb1, dt1[count].sn, &dt1[count].per1) != EOF) {
        count++;
    }
    fclose(file_t);

    bubbleSort_t(dt1, count);

    file_t = fopen("talent_acquisition_recper.txt", "w");
    if (file_t == NULL) {
        printf("Failed to open the file.\n");
      
    }

    for (int i = 0; i < count; i++) {
        fprintf(file_t, "%s %s %s %f\n", dt1[i].un1, dt1[i].jb1, dt1[i].sn, dt1[i].per1);
    }

    fclose(file_t);


      FILE *f4;
      f4=fopen("talent_acquisition_recper.txt","r");
      char us1[15];
      printf("ENTER THE USERNAME   :");
      scanf("%s",us1);
      int rand1=0;
      printf("\n______________________________________________________________________________\n");
      printf("job        seeker_username        percentage");
      while(fscanf(f4,"%s %s %s %f",dt[rand1].company_username,dt[rand1].jobs,dt[rand1].seeker_username,&dt[rand1].rec_per)!=EOF){
        if(strcmp(us1,dt[rand1].company_username)==0){

            printf("\n%10s        %7s        %11f",dt[rand1].jobs,dt[rand1].seeker_username,dt[rand1].rec_per);
                                                    }

        rand1+=1;

                                                    }
      printf("\n________________________________________________________________________________\n");
                                }