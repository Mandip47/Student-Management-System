#include <stdio.h>
#include <string.h>

//structure
struct Student {
  char name[50];
  int age;
  char major[50];
  float percentage;
  int attendance;
};

// functions declaration
void calculatePERC(struct Student *student);
float percentage(float total,float fM);
void inputAttendance(struct Student *student);

//main function 
int main() {
  struct Student students[100];
  FILE *fptr;
  int choice, num_students = 0,num_saved_stds=1;

  do {   
printf("------------------------------------------------"); printf("\n*********************Menu***********************\n");
    printf("------------------------------------------------\n");
    printf("1. Add Student\n");
    printf("2. Calculate Percentage\n");
    printf("3. Input Attendance\n");
    printf("4. View Recent Students\n");
    printf("5. View Saved Students\n");
    printf("6. Save Recent Info\n");
    printf("7. Exit\n");
    printf("------------------------------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    getchar();
    switch (choice) {
    case 1:
      printf("\n------------------------------------------------");
printf("\n****************Student Form********************\n");
    printf("------------------------------------------------\n");
      printf("Enter name: ");
      fgets(students[num_students].name, 50, stdin);
      printf("Enter age: ");
      scanf("%d", &students[num_students].age);
      getchar(); // Consume the newline character left by scanf
      printf("Enter major: ");
      fgets(students[num_students].major, 50, stdin);
      // getchar();
      students[num_students].percentage = 0; 
      students[num_students].attendance = 0;
      num_students++;
      printf("\nStudent Added Successfully!!\n");
      printf("\n");
      break;
      
    case 2:
      
      if (num_students > 0) {
        int student_index;
        printf("\n------------------------------------------------\n");
        printf("Enter student index (0 to %d): ", num_students - 1);
        scanf("%d", &student_index);
        if (student_index >= 0 && student_index < num_students) {
calculatePERC(&students[student_index]);
          printf("\nPercentage calculated for %s\n", students[student_index].name);
        } else {
          printf("\n⚠ Invalid student index\n");
        }
      } else {
        printf("\n⚠No students to calculate Percentage\n");
      }
      printf("\n");
      break;
    case 3:
      if (num_students > 0) {
        int student_index;
        printf("\n------------------------------------------------\n");
        printf("Enter student index (0 to %d): ", num_students - 1);
        scanf("%d", &student_index);
        if (student_index >= 0 && student_index < num_students) {
          inputAttendance(&students[student_index]);
          printf("Attendance recorded for %s!!!\n", students[student_index].name);
        } else {
          printf("\n⚠Invalid student index\n");
        }
      } else {
        printf("\n⚠No students to record attendance\n");
      }
      printf("\n");
      break;
      
    case 4:
      if (num_students > 0) {
        printf("\nRecently added Students:\n");
        for (int i = 0; i < num_students; i++) {
printf("-----------------------\n");
printf("Name: %s", students[i].name);
printf("Age: %d\n", students[i].age);
printf("Major: %s", students[i].major);
printf("Percentage: %.2f%\n", students[i]. percentage);
printf("Attendance: %d/30\n", students[i].attendance);
printf("-----------------------\n");
printf("You should save it permanently!!\n");
      }
      } else {
        printf("\n⚠No students to display\n");
      }
      break;
      
    case 5:
      if (num_saved_stds > 0) {
        fptr = fopen("stdsData.txt","r");
        char ch;
        ch = fgetc(fptr);
        
        while(ch != EOF){
          printf("%c",ch);
          ch=fgetc(fptr);
        }
        fclose(fptr);
      } else {
        printf("\n⚠No students to display\n");
            }
      break;
      
    case 6:
      if (num_students > 0){
     fptr = fopen("stdsData.txt","a");
      for (int i = 0; i < num_students; i++) {
    fprintf(fptr,"-----------------------\n");
fprintf(fptr,"Name: %s", students[i].name);
fprintf(fptr,"Age: %d\n", students[i].age);
fprintf(fptr,"Major: %s", students[i].major);
fprintf(fptr,"Percentage: %.2f%\n", students[i]. percentage);
fprintf(fptr,"Attendance: %d/30\n", students[i].attendance);
fprintf(fptr,"-----------------------\n");
num_saved_stds++;
      }
    fclose(fptr);
    printf("\nData Successfully saved \n");
      }else {
        printf("\n⚠No students to save!!\n");
      }
      break;
    case 7:
      printf("\nExiting program\n");
      break;
    default:
      printf("\n⚠Invalid choice, please try again\n");
    }
  } while (choice != 7);
  printf("\n");
  return 0;
}

//Functions defination 

void calculatePERC(struct Student *student) {

  float phy,che,mat,nep,eng,comp,fM, percent;
  
  printf("\nEnter full marks : ");
  scanf("%f",&fM);
  printf("\nEnter physics marks : ");
  scanf("%f",&phy);
  printf("\nEnter chemistry marks : ");
  scanf("%f",&che);
  printf("\nEnter math marks : ");
  scanf("%f",&mat);
  printf("\nEnter nepali marks : ");
  scanf("%f",&nep);
  printf("\nEnter english marks : ");
  scanf("%f",&eng);
  printf("\nEnter computer marks : ");
  scanf("%f",&comp);
  float total = phy+che+mat+nep+eng+comp;
  
  percent = percentage(total,fM);
  
  student->percentage = percent;
  
}

void inputAttendance(struct Student *student) {
int att;
  printf("\nEnter this month attendence:");
  scanf("%d",&att);
  student->attendance=att;
  
}

float percentage(float total,float fM){
  return (total/(fM * 6)) * 100;
}