/*
 * mini.cpp
 *
 *  Created on: Nov 19, 2019
 *      Author: lenovo
 */
/*
 * TITLE: AVERAGE ANALYSIS IN FITNESS TRACKING SYSTEM
 * 
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace std;
class node //node class
{
  node *next;
  node *prev;
  long step_count;
  float cal;
  int sleep_count;
  int no_of_glasses;
  string workout;
  int day;

public:
  node() //constructor for initialising node fields
  {
    step_count = 0;
    cal = 0.0f;
    sleep_count = 0;
    no_of_glasses = 0;
    workout = "\0";
    next = NULL;
    prev = NULL;
    day = 0;
  }
  friend class list;
};
class list
{
  node *head;

public:
  list()
  {
    head = NULL;
  }

public:
  //function declarations
  void accept_node(string name, long step_goal1, int water_intake_goal, int sleep_goal, int i);
  long step_goal(long);
  float calories();
  float bmi(float, float);
  int sleep(int, string);
  int water(int);
  string workout();
  void display();
  void display1(string, int, char, float, float, float, int, int, long);
  void bmi12(float);
  void search(int);
  void search(long);
  void display_node(node *);
  void avg_analysis(long, int, int);
  void delete_day();
  void update();
  void line();
};
int list::water(int water_intake_goal) //defines water intake taken per day
{
  int water_intake;
  int flag = 1;
  cout << "Enter today's water intake : " << endl;
  cin >> water_intake;
  do
  {
    if (water_intake < 0 || water_intake > 25) //water intake validation starts
    {
      flag = 1;
      cout << "Please enter valid water intake : " << endl;
      cin >> water_intake;
    }
    else
    {
      flag = 0;
    }
  } while (flag == 1); //validation ends
  if (water_intake < water_intake_goal)
  {
    cout << "-----------------------------------------" << endl;
    cout << "You should increase your water intake :( " << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
  }
  if (water_intake > water_intake_goal || water_intake == water_intake_goal)
  {
    cout << "-----------------------------------------" << endl;
    cout << "Great!! You have accomplished your goal :) " << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
  }
  return water_intake;
} //water intake function ends

void list::accept_node(string name, long step_goal1, int water_intake_goal, int sleep_goal, int i)
{ //accepting node data fields
  node *temp, *ptr;
  long steps_walked;
  steps_walked = step_goal(step_goal1);
  int water_taken = water(water_intake_goal);
  int sleep_taken = sleep(sleep_goal, name);
  float cal;
  cal = calories();
  string workout1;
  workout1 = workout();
  temp = new node(); //creating new node
  temp->step_count = steps_walked;
  temp->sleep_count = sleep_taken;
  temp->no_of_glasses = water_taken;
  temp->cal = cal;
  temp->workout = workout1;
  temp->day = i;
  //creation of List
  if (head == NULL) //if list is empty
  {
    head = temp;
  }
  else //adding nodes at the end of list
  {
    ptr = head;
    while (ptr->next != NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
  }
} //accept function ends
long list::step_goal(long step_goal) //Step count function which counts steps moved per day
{
  step_goal = step_goal + 2000;
  long step_count = (rand() % (step_goal - 400 + 1)) + 400; //use of rand function
  return step_count;
}
int list ::sleep(int sleep_goal, string name) //No of hours slept
{
  int sleep_hours;
  int flag1 = 1;
  cout << "How much sleep did you take (in hours)?" << endl;
  cin >> sleep_hours;
  do //sleep time validation starts
  {
    if (sleep_hours < 0 || sleep_hours > 24)
    {
      flag1 = 1;
      cout << "Please enter valid sleep hours : " << endl;
      cin >> sleep_hours;
    }
    else
    {
      flag1 = 0;
    }
  } while (flag1 == 1);          //validation ends
  if (sleep_hours == sleep_goal) //if sleep time ==sleep goals set
  {
    cout << "----------------------------------" << endl;
    cout << name << ",Yay!!Sleep goals achieved!" << endl;
    cout << "----------------------------------" << endl;
    cout << endl;
  }
  if (sleep_hours < sleep_goal) //if sleep time< sleep goal set
  {
    cout << "----------------------------------" << endl;
    cout << name << ",you need more sleep!!" << endl;
    cout << "----------------------------------" << endl;
    cout << endl;
  }
  if (sleep_hours > sleep_goal) //if sleep time > sleep goal set
  {
    cout << "----------------------------------" << endl;
    cout << name << ",too much sleep!!" << endl;
    cout << "----------------------------------" << endl;
    cout << endl;
  }
  return sleep_hours;
} //end of function
float list::calories() //Counts calories based on food had in 24 hrs
{
  int a, flag2;
  char ch;
  float calories = 0.0, cal1;
  do
  { //Generalised food option categories having average calories per quantity eaten
    cout << "FOOD OPTIONS:\n1.Pulse/Grains?" << endl;
    cout << "2.Fruits?" << endl;
    cout << "3.Vegetables?" << endl;
    cout << "4.Junk Food?" << endl;
    cout << "Choose Food option" << endl;
    cin >> a;
    do //validation of choosing option starts
    {
      if (a < 1 || a > 4)
      {
        flag2 = 1;
        cout << "Please enter valid food option" << endl;
        cin >> a;
      }
      else
      {
        flag2 = 0;
      }
    } while (flag2 == 1); //validation ends
    switch (a)
    { //assigning calories to meal eaten
    case 1:
      if (a == 1)
      {
        cal1 = 200;
      }
      break;
    case 2:
      if (a == 2)
      {
        cal1 = 100;
      }
      break;
    case 3:
      if (a == 3)
      {
        cal1 = 100;
      }
      break;
    case 4:
      if (a == 4)
      {
        cal1 = 800;
      }
      break;
    }                           //switch ends here
    calories = calories + cal1; //adding total calories based on total no of meals taken
    cout << "Did you eat anything else(y/n)??" << endl;
    cin >> ch;
  } while (ch == 'y');
  return calories; //returning total calories
}
float list::bmi(float h, float w) //BMI calculation
{
  float bmi;
  bmi = (w / ((h) * (h)));
  return bmi;
}
string list::workout() //Workout done in a day
{
  string str, str1 = "\0";
  int workout;
  int flag = 0;

  cout << "WORKOUT OPTIONS: "
          "1. Swimming\n"
          "2. Walking\n"
          "3. Treadmill\n"
          "4. Elliptical training\n"
          "5. Weight training\n"
          "6. Running\n"
          "7. Cycling\n"
          "8. Hiking\n"
          "9. Aerobics\n"
          "10. NA\n";
  //do
  //{
  do //validation for choosing correct option
  {
    cout << "Enter your choice";
    cin >> workout;
    if (workout < 1 || workout > 10)
    {
      flag = 0;
      cout << "Invalid choice" << endl;
    }
    else
      flag = 1;
  } while (flag == 0); //validation ends
  switch (workout)
  {
  case 1:
    str = "Swimming";
    break;
  case 2:
    str = "Walking";
    break;
  case 3:
    str = "Treadmill";
    break;
  case 4:
    str = "Elliptical";
    break;
  case 5:
    str = "Training";
    break;
  case 6:
    str = "Running";
    break;
  case 7:
    str = "Cycling";
    break;
  case 8:
    str = "Hiking";
    break;
  case 9:
    str = "Aerobics";
    break;
  case 10:
    str = "NA";
    break;
  }
  //str1=str1+"\n"+str;
  //flag=0;
  //cout<<"More workouts??(y/n)??"<<endl;
  //cin>>ch;
  //}while(ch=='y');
  return str;
} //workout function ends
void list::line() //function used for dislaying in tabular format
{
  for (int i = 1; i < 50; i++)
    cout << "--";

  cout << "\n";
}

void list::display() //displaying details of all day
{
  node *ptr;

  if (head == NULL)
  {
    cout << "list is empty" << endl;
  }

  cout << "\n\n\n";
  cout << setw(52) << "FITNESS TRACKING SYSTEM\n";
  line();
  cout << "DAY" << setw(15) << "WATER INTAKE" << setw(15) << "SLEEP TIME " << setw(15) << "STEPS" << setw(20) << "WORKOUT" << setw(20) << "CALORIES\n";
  line();
  for (ptr = head; ptr != NULL; ptr = ptr->next)
  {
    if (ptr->day == 0)
    {
      break;
    }
    else
    {
      cout << ptr->day << setw(12) << ptr->no_of_glasses << setw(12) << ptr->sleep_count << setw(20) << ptr->step_count << setw(20) << ptr->workout << setw(20) << ptr->cal << endl;
    }
  }
}
void list::display1(string name, int age, char gender, float height, float weight, float bmi, int sleep_goal, int water_intake_goal, long step_goal1)
{ //display function for displaying details of person
  cout << setw(70) << "DISPLAY DETAILS" << endl;
  cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << "NAME\t\tAGE\t\tGENDER\t\tHEIGHT\t\tWEIGHT\t\tSLEEP GOALS\t\tWATER GOALS\t\tSTEP GOALS\t\tBMI" << endl;
  cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
  cout << name << "\t\t" << age << "\t\t" << gender << "\t\t" << height << "\t\t" << weight << "\t\t\t" << sleep_goal << "\t\t\t" << water_intake_goal << "\t\t\t" << step_goal1 << "\t\t" << bmi << endl;
  cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void list::bmi12(float bmi) //Based on BMI displays persons health status
{
  if (bmi < 15)
  {
    cout << "Very severly underweight" << endl;
  }

  if (bmi >= 15 && bmi < 16)
  {
    cout << "Severly underweigth" << endl;
  }

  if (bmi >= 16 && bmi < 18.5)
  {
    cout << "Underweigth" << endl;
  }

  if (bmi >= 18.5 && bmi < 25)
  {
    cout << "Normal" << endl;
  }

  if (bmi >= 25 && bmi < 30)
  {
    cout << "Overweight" << endl;
  }

  if (bmi >= 30 && bmi < 35)
  {
    cout << "Moderately obese" << endl;
  }

  if (bmi >= 35 && bmi < 40)
  {
    cout << "Severly obese" << endl;
  }
  if (bmi >= 40)
  {
    cout << "Very severly obese" << endl;
  }
}
void list::search(int day) //Searching a node based on day no
{
  int flag = 0;
  node *ptr;
  for (ptr = head; ptr != NULL; ptr = ptr->next)
  {
    if (day == ptr->day)
    {
      flag = 1;
      display_node(ptr);
      break;
    }
  }
  if (flag == 0)
  {
    cout << "Day not found" << endl;
  }
}
void list::search(long value) //Searching based on min steps achieved
{
  int flag = 0;
  node *ptr;
  for (ptr = head; ptr != NULL; ptr = ptr->next)
  {
    if (ptr->step_count >= value) //displays all the days which achieved the min stepcount value
    {
      flag++;
      display_node(ptr);
    }
  }
  if (flag == 0) //if no milestone achieved
  {
    cout << "Oops!You haven't achieved these milestones" << endl;
  }
}
void list::display_node(node *ptr) //displaying details of one node
{

  cout << "***************************" << endl;
  cout << "DAY " << ptr->day << endl;
  cout << "WATER INTAKE : " << ptr->no_of_glasses << endl;
  cout << "SLEEP TIME :" << ptr->sleep_count << endl;
  cout << "STEPS: " << ptr->step_count << endl;
  cout << "WORKOUT:" << ptr->workout << endl;
  cout << "CALORIES:" << ptr->cal << endl;
  cout << "***************************" << endl;
}
void list::avg_analysis(long step_count1, int sleep_count, int water_count) //Average Analaysis of all the days
{
  node *ptr;
  ptr = head;
  int i = 0;
  long avg_step_count = 0;
  float avg_cal = 0.0f;
  float avg_sleep_count = 0;
  float avg_no_of_glasses = 0;
  if (head == NULL)
  {
    cout << "List is empty.";
  }
  else
  {
    while (ptr != NULL)
    {
      i++;
      avg_step_count += ptr->step_count;
      avg_cal += ptr->cal;
      avg_sleep_count += ptr->sleep_count;
      avg_no_of_glasses += ptr->no_of_glasses;
      ptr = ptr->next;
    }
    avg_step_count /= i;
    avg_cal /= i;
    avg_sleep_count /= i;
    avg_no_of_glasses /= i;
    cout << setw(50) << "AVERAGE ANALYSIS" << endl;
    //display average analysis
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Avg. step count(steps):\t "
         << "Avg. calories consumed(cal):\t  "
         << "Avg. sleep taken(in hrs):      "
         << "Avg. water intake(in glasses):" << setw(10) << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << avg_step_count << setw(30) << avg_cal << setw(30) << avg_sleep_count << setw(30) << avg_no_of_glasses << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    if (avg_step_count >= step_count1)
    {
      cout << "***STEP GOALS***" << endl;
      cout << "Hurray,Goals achieved" << endl;
      cout << endl;
    }
    else
    {
      cout << "***STEP GOALS***" << endl;
      cout << "You need to walk more often!!" << endl;
      cout << endl;
    }
    if (avg_sleep_count >= sleep_count)
    {
      cout << "***SLEEP TIME***" << endl;
      cout << "Hurray,your sleep time is good!" << endl;
      cout << endl;
    }
    else
    {
      cout << "***SLEEP TIME***" << endl;
      cout << "You need to have good sleep for healthy life!!" << endl;
      cout << endl;
    }
    if (avg_no_of_glasses >= water_count)
    {
      cout << "***WATER INTAKE***" << endl;
      cout << "Hurray,Goals achieved!!" << endl;
      cout << endl;
    }
    else
    {
      cout << "***WATER INTAKE***" << endl;
      cout << "You need to drink water more often!!" << endl;
      cout << endl;
    }
    if (avg_cal >= 1000)
    {
      cout << "***CALOREIS***" << endl;
      cout << "You need to exercise more to burn calories" << endl;
      cout << endl;
    }
    else
    {
      cout << "***CALORIES***" << endl;
      cout << "Hurray,your diet is perfect!!" << endl;
    }
  }
}
void list ::delete_day() //delete details of a day
{
  node *ptr;
  ptr = head;
  int n, flag4 = 1;
  cout << "Enter day number to delete" << endl;
  cin >> n;
  do //validation for day no selection starts
  {
    if (n <= 0 || n > 7)
    {
      flag4 = 1;
      ;
      cout << "Invalid day: " << endl;
      cout << "Enter number of day to delete" << endl;
      cin >> n;
    }
    else
    {
      flag4 = 0;
    }
  } while (flag4 == 1); //validation ends
  if (head == NULL)     //if list empty
  {
    cout << "List is empty.";
  }
  else //if list exists
  {
    while (ptr != NULL)
    {
      if (ptr->day == n && ptr == head && ptr->next == NULL) //if search successful and first and only node in list
      {
        ptr->day = 0;
        head = NULL;
        delete ptr;
        cout << "\nList is empty.";
        break;
      }
      if (ptr->day == n && ptr == head) //if search successful and first node in list
      {
        head = head->next;
        head->prev = ptr->next = NULL;
        delete ptr;
        break;
      }
      if (ptr->next == NULL && ptr->day == n) //last node
      {
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        delete ptr;
        break;
      }
      if (ptr->day == n) //any other node
      {
        ptr->next->prev = ptr->prev;
        ptr->prev->next = ptr->next;
        ptr->next = ptr->prev = NULL;
        delete ptr;
        break;
      }
      if (ptr->next == NULL) //if node not found
      {
        cout << "day not found";
      }
      ptr = ptr->next; //increment ptr
    }
  }
}
void list::update() //Updating data fields based on workout and water intake
{
  node *ptr;
  int x;
  ptr = head;
  string workout1;
  string str;
  int no_of_glasses1;
  int day1;
  cout << "Enter number of day to update ";
  cin >> day1;
  if (head == NULL) //validation for updating a node begins
  {
    cout << "\nList is already empty. Cannot update a node";
  } //validation for updating a node ends
  else
  {
    for (ptr = head; ptr != NULL; ptr = ptr->next) //updating day details
    {
      if (ptr->day == day1)
      {
        do
        {
          cout << "\n\nEnter 1 for updating workout" << endl;
          cout << "Enter 2 for updating water intake" << endl;
          cout << "Enter 3 to exit from update " << endl;
          cout << "\nEnter your choice " << endl;
          cin >> x;
          switch (x)
          {
          case 1:
            int c;
            //  do
            // {
            cout << "\nWORKOUT OPTIONS: "
                    "1. Swimming\n"
                    "2. Walking\n"
                    "3. Treadmill\n"
                    "4. Elliptical training\n"
                    "5. Weight training\n"
                    "6. Running\n"
                    "7. Cycling\n"
                    "8. Hiking\n"
                    "9. Aerobics\n";
            "10. NA\n";
            cout << "\nEnter updated workout " << endl;
            cin >> c;
            switch (c)
            {
            case 1:
              str = "Swimming";
              break;
            case 2:
              str = "Walking";
              break;
            case 3:
              str = "Treadmill";
              break;
            case 4:
              str = " Elliptical";
              break;
            case 5:
              str = "Weight training";
              break;
            case 6:
              str = "Running";
              break;
            case 7:
              str = "Cycling";
              break;
            case 8:
              str = "Hiking";
              break;
            case 9:
              str = "Aerobics";
              break;
            case 10:
              str = "NA";
              break;
            }                   //switch ends here
                                // cout<<"\n\nDid you do any other workout(y/n)?";
                                //cin>>ans;
                                //}while(ans=='y');
            ptr->workout = str; //contents of string are stored in datafield of node of list
                                // cout<<ptr->workout;
            break;
          case 2:
            cout << "\nEnter updated water intake in glasses " << endl;
            cin >> no_of_glasses1;
            ptr->no_of_glasses = ptr->no_of_glasses + no_of_glasses1; //adding no of glasses to existing glass count
            cout << "Your new water intake is"
                 << " " << ptr->no_of_glasses;
            break;
          case 3:
            break;
          } //switch case ends here
        } while (x != 3);
      }
    }

  } //else loop ends here
}
int main()
{
  list l;
  int ch;
  string name;
  int age;
  int flag7 = 1;
  float weight;
  float height;
  char gender;
  float bmi1;
  int sleep_goal;
  int water_intake_goal;
  long step_goal1;
  int no_of_days;
  int value;
  long value1;
  int flag6 = 1;
  int cnt = 0;
  do
  {
    cout << endl;
    cout << "-----------MENU----------------" << endl;
    cout << "1.Accept details of person" << endl;
    cout << "2.Display details of person" << endl;
    cout << "3.Accept details for a day" << endl;
    cout << "4.Display details for a day" << endl;
    cout << "5.Search a day " << endl;
    cout << "6.Search as per step count " << endl;
    cout << "7.Delete details for a day" << endl;
    cout << "8.Update details for a day" << endl;
    cout << "9.Average Analysis" << endl;
    cout << "10.EXIT" << endl;
    cout << "Enter your choice" << endl;
    cin >> ch;
    cnt++;
    if (cnt == 1) //validation for compelling user to enter the data first before any other operations
    {
      while (ch != 1)
      {
        cout << "Mandatory to input data"
             << "\n"
             << "Enter your choice again";
        cin >> ch;
      }
    } //validation ends
    switch (ch)
    {
    case 1:
      cout << "Enter your name" << endl;
      cin >> name;
      do
      {
        for (int k = 0; name[k] != '\0'; k++)
        { //validation for name starts
          if (!((name[k] >= 'a' && name[k] <= 'z') || (name[k] == 39) || name[k] >= 'A' && name[k] <= 'Z'))
          {
            flag7 = 1;
            cout << "Invalid input.\nEnter your name" << endl;
            cin >> name;
            break;
          }
          else
          {
            flag7 = 0;
          }
        }
      } while (flag7 == 1); //validation of name ends
      cout << "Enter your age(in years)" << endl;
      cin >> age;
      do //age validation starts
      {
        if (age <= 15 || age > 100)
        {
          flag7 = 1;
          cout << "Invalid age\n";
          cout << "Enter your age(in years)" << endl;
          cin >> age;
        }
        else
        {
          flag7 = 0;
        }
      } while (flag7 == 1); //age validation ends
      flag7 = 0;
      cout << "Enter your gender(m/f)" << endl;
      cin >> gender;
      do //gender validation starts
      {
        if (!(gender == 'f' || gender == 'm'))
        {
          cout << "Please enter valid gender(m/f)" << endl;
          cin >> gender;
          flag7 = 1;
        }
        else
          flag7 = 0;
      } while (flag7 == 1); //gender validation ends
      flag7 = 0;
      cout << "Enter your height(in metres)" << endl;
      cin >> height;
      do //height validation starts
      {
        if (height < 0.5 || height > 2.5)
        {
          cout << "Please enter valid height(in metres)" << endl;
          cin >> height;
          flag7 = 1;
        }
        else
          flag7 = 0;
      } while (flag7 == 1); //height validation ends
      flag7 = 0;
      cout << "Enter your weight(in kg)" << endl;
      cin >> weight;
      do //weight validation starts
      {
        if (weight < 15 || weight > 150)
        {
          cout << "Please enter valid weight(in kg)" << endl;
          cin >> weight;
          flag7 = 1;
        }
        else
          flag7 = 0;
      } while (flag7 == 1); //end of validation of height
      cout << "Enter your sleep target(in hours)" << endl;
      cin >> sleep_goal;
      flag7 = 0;
      do //sleep target validation starts
      {
        if (sleep_goal < 0 || sleep_goal > 24)
        {
          flag7 = 1;
          cout << "Please enter valid sleep hours : " << endl;
          cin >> sleep_goal;
        }
        else
        {
          flag7 = 0;
        }
      } while (flag7 == 1); //weight validation ends
      cout << "Enter target for water intake(in glasses)" << endl;
      cin >> water_intake_goal;
      flag7 = 0;
      do //Water intake target validation starts
      {
        if (water_intake_goal < 1 || water_intake_goal > 30)
        {
          flag7 = 1;
          cout << "Please enter valid water intake goal : " << endl;
          cin >> water_intake_goal;
        }
        else
        {
          flag7 = 0;
        }
      } while (flag7 == 1); //Water intake validation ends

      cout << "Enter target for walking" << endl;
      cin >> step_goal1;
      flag7 = 0;
      do //Step goals validation starts
      {
        if (step_goal1 < 100 || step_goal1 > 300000)
        {
          flag7 = 1;
          cout << "Please enter valid step goal : " << endl;
          cin >> step_goal1;
        }
        else
        {
          flag7 = 0;
        }
      } while (flag7 == 1); //Step goals validation ends

      cout << endl;
      ;
      break;
    case 2:
      bmi1 = l.bmi(height, weight);
      l.display1(name, age, gender, height, weight, bmi1, sleep_goal, water_intake_goal, step_goal1);
      cout << "HEALTH STATUS:";
      l.bmi12(bmi1);

      break;
    case 3:
      cout << "Enter number of days for which you want to enter data" << endl;
      cin >> no_of_days;
      do //no of days validation starts
      {
        if (no_of_days <= 0 || no_of_days > 7)
        {
          flag6 = 1;
          ;
          cout << "Invalid day: " << endl;
          cout << "Enter number of days for which you want to enter data" << endl;
          cin >> no_of_days;
        }
        else
        {
          flag6 = 0;
        }
      } while (flag6 == 1);                 //end of validation
      for (int i = 1; i <= no_of_days; i++) //displaying data
      {
        cout << "DAY:" << i << endl;
        l.accept_node(name, step_goal1, water_intake_goal, sleep_goal, i); //changed,,passing i
        cout << endl;
      }
      break;
    case 4:
      l.display();
      break;
    case 5:
      cout << "Enter day for searching data " << endl;
      cin >> value;
      l.search(value);
      break;
    case 6:
      cout << "Enter steps for searching data " << endl;
      cin >> value1;
      l.search(value1);
      break;
    case 7:
      l.delete_day();

      break;
    case 8:
      l.update();
      break;
    case 9:
      l.avg_analysis(step_goal1, sleep_goal, water_intake_goal);

      break;
    case 10:
      break;
    }
  } while (ch != 10);
  return 0;
}

/* ---------------------------------------OUTPUT----------------------------------------
 * -----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
2
Mandatory to input data
Enter your choice again1
Enter your name
Anaya
Enter your age(in years)
19
Enter your gender(m/f)
f
Enter your height(in metres)
78
Please enter valid height(in metres)
1.5
Enter your weight(in kg)
1000
Please enter valid weight(in kg)
59
Enter your sleep target(in hours)
27
Please enter valid sleep hours :
8
Enter target for water intake(in glasses)
100
Please enter valid water intake goal :
9
Enter target for walking
20
Please enter valid step goal :
10000


-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
2
                                                       DISPLAY DETAILS
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
NAME		AGE		GENDER		HEIGHT		WEIGHT		SLEEP GOALS		WATER GOALS		STEP GOALS		BMI
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
Anaya		19		f		1.5		59			8			9			10000		26.2222
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
HEALTH STATUS:Overweight

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
3
Enter number of days for which you want to enter data
4
DAY:1
Enter today's water intake :
8
-----------------------------------------
You should increase your water intake :(
-----------------------------------------

How much sleep did you take (in hours)?
9
----------------------------------
Anaya,too much sleep!!
----------------------------------

FOOD OPTIONS:
1.Pulse/Grains?
2.Fruits?
3.Vegetables?
4.Junk Food?
Choose Food option
1
Did you eat anything else(y/n)??
y
FOOD OPTIONS:
1.Pulse/Grains?
2.Fruits?
3.Vegetables?
4.Junk Food?
Choose Food option
3
Did you eat anything else(y/n)??
n
WORKOUT OPTIONS: 1. Swimming
2. Walking
3. Treadmill
4. Elliptical training
5. Weight training
6. Running
7. Cycling
8. Hiking
9. Aerobics
10. NA
Enter your choice7

DAY:2
Enter today's water intake :
6
-----------------------------------------
You should increase your water intake :(
-----------------------------------------

How much sleep did you take (in hours)?
3
----------------------------------
Anaya,you need more sleep!!
----------------------------------

FOOD OPTIONS:
1.Pulse/Grains?
2.Fruits?
3.Vegetables?
4.Junk Food?
Choose Food option
3
Did you eat anything else(y/n)??
y
FOOD OPTIONS:
1.Pulse/Grains?
2.Fruits?
3.Vegetables?
4.Junk Food?
Choose Food option
2
Did you eat anything else(y/n)??
n
WORKOUT OPTIONS: 1. Swimming
2. Walking
3. Treadmill
4. Elliptical training
5. Weight training
6. Running
7. Cycling
8. Hiking
9. Aerobics
10. NA
Enter your choice3

DAY:3
Enter today's water intake :
5
-----------------------------------------
You should increase your water intake :(
-----------------------------------------

How much sleep did you take (in hours)?
9
----------------------------------
Anaya,too much sleep!!
----------------------------------

FOOD OPTIONS:
1.Pulse/Grains?
2.Fruits?
3.Vegetables?
4.Junk Food?
Choose Food option
4
Did you eat anything else(y/n)??
n
WORKOUT OPTIONS: 1. Swimming
2. Walking
3. Treadmill
4. Elliptical training
5. Weight training
6. Running
7. Cycling
8. Hiking
9. Aerobics
10. NA
Enter your choice2

DAY:4
Enter today's water intake :
7
-----------------------------------------
You should increase your water intake :(
-----------------------------------------

How much sleep did you take (in hours)?
4
----------------------------------
Anaya,you need more sleep!!
----------------------------------

FOOD OPTIONS:
1.Pulse/Grains?
2.Fruits?
3.Vegetables?
4.Junk Food?
Choose Food option
3
Did you eat anything else(y/n)??
y
FOOD OPTIONS:
1.Pulse/Grains?
2.Fruits?
3.Vegetables?
4.Junk Food?
Choose Food option
2
Did you eat anything else(y/n)??
n
WORKOUT OPTIONS: 1. Swimming
2. Walking
3. Treadmill
4. Elliptical training
5. Weight training
6. Running
7. Cycling
8. Hiking
9. Aerobics
10. NA
Enter your choice7


-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
4



                            FITNESS TRACKING SYSTEM
--------------------------------------------------------------------------------------------------
DAY   WATER INTAKE    SLEEP TIME           STEPS             WORKOUT           CALORIES
--------------------------------------------------------------------------------------------------
1           8           9                9455             Cycling                 300
2           6           3               11882           Treadmill                 200
3           5           9                 616             Walking                 800
4           7           4                9515             Cycling                 200

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
5
Enter day for searching data
9
Day not found

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
5
Enter day for searching data
2
***************************
DAY 2
WATER INTAKE : 6
SLEEP TIME :3
STEPS: 11882
WORKOUT:Treadmill
CALORIES:200
***************************

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
6
Enter steps for searching data
30000
Oops!You haven't achieved these milestones

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
6
Enter steps for searching data
9500
***************************
DAY 2
WATER INTAKE : 6
SLEEP TIME :3
STEPS: 11882
WORKOUT:Treadmill
CALORIES:200
***************************
***************************
DAY 4
WATER INTAKE : 7
SLEEP TIME :4
STEPS: 9515
WORKOUT:Cycling
CALORIES:200
***************************

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
7
Enter day number to delete
9
Invalid day:
Enter number of day to delete
6
day not found
-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
7
Enter day number to delete
1

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
4



                            FITNESS TRACKING SYSTEM
--------------------------------------------------------------------------------------------------
DAY   WATER INTAKE    SLEEP TIME           STEPS             WORKOUT           CALORIES
--------------------------------------------------------------------------------------------------
2           6           3               11882           Treadmill                 200
3           5           9                 616             Walking                 800
4           7           4                9515             Cycling                 200

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
9
                                  AVERAGE ANALYSIS
-------------------------------------------------------------------------------------------------------------------------------------------
Avg. step count(steps):	 Avg. calories consumed(cal):	  Avg. sleep taken(in hrs):      Avg. water intake(in glasses):
-----------------------------------------------------------------------------------------------------------------------------------------
7337                           400                       5.33333                             6
------------------------------------------------------------------------------------------------------------------------------------------
***STEP GOALS***
You need to walk more often!!

***SLEEP TIME***
You need to have good sleep for healthy life!!

***WATER INTAKE***
You need to drink water more often!!

***CALORIES***
Hurray,your diet is perfect!!

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
8
Enter number of day to update 3


Enter 1 for updating workout
Enter 2 for updating water intake
Enter 3 to exit from update

Enter your choice
1

WORKOUT OPTIONS: 1. Swimming
2. Walking
3. Treadmill
4. Elliptical training
5. Weight training
6. Running
7. Cycling
8. Hiking
9. Aerobics

Enter updated workout
9


Enter 1 for updating workout
Enter 2 for updating water intake
Enter 3 to exit from update

Enter your choice
2

Enter updated water intake in glasses
4
Your new water intake is 9

Enter 1 for updating workout
Enter 2 for updating water intake
Enter 3 to exit from update

Enter your choice
3

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
4



                            FITNESS TRACKING SYSTEM
--------------------------------------------------------------------------------------------------
DAY   WATER INTAKE    SLEEP TIME           STEPS             WORKOUT           CALORIES
--------------------------------------------------------------------------------------------------
2           6           3               11882           Treadmill                 200
3           9           9                 616            Aerobics                 800
4           7           4                9515             Cycling                 200

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
9
                                  AVERAGE ANALYSIS
-------------------------------------------------------------------------------------------------------------------------------------------
Avg. step count(steps):	 Avg. calories consumed(cal):	  Avg. sleep taken(in hrs):      Avg. water intake(in glasses):
-----------------------------------------------------------------------------------------------------------------------------------------
7337                           400                       5.33333                       7.33333
------------------------------------------------------------------------------------------------------------------------------------------
***STEP GOALS***
You need to walk more often!!

***SLEEP TIME***
You need to have good sleep for healthy life!!

***WATER INTAKE***
You need to drink water more often!!

***CALORIES***
Hurray,your diet is perfect!!

-----------MENU----------------
1.Accept details of person
2.Display details of person
3.Accept details for a day
4.Display details for a day
5.Search a day
6.Search as per step count
7.Delete details for a day
8.Update details for a day
9.Average Analysis
10.EXIT
Enter your choice
10
 *
 */


