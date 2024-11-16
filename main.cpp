#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstring>
#include<ctime> // For time in receipt.
#include <cstdlib>  // For rand() and srand().
#include <limits.h>

using namespace std;

class subject;
class batch;
class academic_record;
class fee_manager;
class subject;
class fee_manager;

// class User  is a common Generalised class whose characteristics are inherited in Teacher and Student.

class User{

     protected :

    string username ;
    string password;
    string name;
    long contact_no;
    string dob;
    string city;

    public :

    User(){}

    User(string a, string b, string c,long d,string e,string f): username(a),password(b),name(c),contact_no(d),dob(e),city(f){}

    string  getpassword(){
        return  password;
    }

    string  getusername(){
        return  username;
    }

    void  setpassword(string newp){
        password=newp ;
    }

    string  getname(){
        return  name;
    }

};

class fee_manager{

    protected:

    string name;
    string enrollment_no;
    int fee;
    int remainfee;

    public:

    fee_manager(string n,string e,int f )
    {
        name = n ;
        enrollment_no = e;
        fee = f;
        remainfee = f;
    }

    void view_feerecord(){

        cout << "Student Name: " << name << endl;
        cout << "Student ID: "<< enrollment_no <<endl;
        if(fee==0) cout<<"The fees is paid."<<endl;
        else cout<<"Fee Amount: Rs."<< fee <<" needs to be paid "<< endl;

}


void update_feerecord(){

        cout<<"Enter the  fee  submitted by  student : "<<endl;
        int feeSub;
        cin>>feeSub;
        remainfee=fee-feeSub;

        if(remainfee<0){
            cout<<"Amount exceeds the total amount due .\n";
            remainfee=-remainfee;
        }
        cout<<"Remaining Fee after Payment : RS. "<< remainfee <<endl;

}

void generate_feereceipt(){

        cout << "==============================================" << endl;
        cout << "                     RECEIPT" << endl;
        cout << "==============================================" << endl;
        cout << "Student Name: " << name << endl;
        cout << "Student ID: " << enrollment_no << endl;
        cout << "Fee Amount: $" << fee << endl;
        cout << "----------------------------------------------" << endl;
        cout << "Total Amount Paid: $" << fee - remainfee << endl;
        cout << "FEE remaining : $"<<remainfee<<endl;
        time_t currentTime = time(0);
        char* formattedTime = ctime(&currentTime);
        cout << "Time of payment:" << formattedTime;
        cout << "===============================================" << endl;

    }
};

class batch{

    public:

    int no_of_students;
    string batch_name;

    batch(){}

    batch(string nm): batch_name(nm){}

    batch(string a, int n): batch_name(a), no_of_students(n){}

    string show(){
        return batch_name;
    }
};

class subject {

    public:

    string sub_name;

    subject(){}

    subject(const string& s) : sub_name(s) {}

    string show(){
        return sub_name;
    }

};

//class to manage academic records of students.
class academic_record{

protected:

subject subjects[5] = {subject("Maths"), subject("Physics"), subject("SDF"), subject("ES"), subject("Chemistry")};

int marks[5];
float attendance[5];

public :

academic_record(){}

void view_attendance()

{
    cout<<"Your attendance is shown below:\n";
    cout<<"Subject \t \t Attendance\n";
    for(int i=0;i<5;i++)
    {
    cout<<subjects[i].sub_name <<" \t \t "<< attendance[i]<<"%"<<endl;
    }
}

void generate_random_marks() 
{
        // Seed the random number generator
        srand(time(0));

        // Generate random marks for each subject
        for (int i = 0; i < 5; ++i) {
            marks[i] = rand() % 101; 
            // Generate a random number between 0 and 100
        }
}

void view_marks()
{
    cout<<"Your marks are shown below:\n";
    cout<<"Subject \t \t Marks\n";
    for(int i=0;i<5;i++)
    {
    cout<<subjects[i].sub_name <<" \t \t "<< marks[i]<<"%"<<endl;
    }
}

void sgpa_generator(){

    float sgpa=0;

    for(int i=0;i<5;i++)
    {
    sgpa=sgpa+marks[i];
    }

    sgpa=sgpa/50;

    //we divide by 50 to get sgpa w.r.t. 10 as highest cgpa.

    cout<<"The sgpa of the student is :"<<sgpa<<endl;

}

};

// class Teacher inherits common Characteristics from user using Inheritance

class Teacher: public User {

    protected:

    string name ;
    string emp_id;
    subject *s[2];
    int no_of_sub;
    batch *b[5];
    int no_of_batch;
    int experience;
    string qualification ;

    public:

     Teacher() : no_of_sub(0) {
        // Initialize each element of st to nullptr
        for (int i = 0; i < 2; ++i) {
            s[i] = nullptr;
        }
    }

    Teacher(string tn,string a, int b , string q ,string au, string bu , string c,long d,string e,string f): User( au,  bu, c, d, e,f)
    {
        name= tn ;
        emp_id=a;
        no_of_batch=0;
        no_of_sub=0;
        experience=b;
        qualification=q;
    }

    void addsubject(subject*s1){
        if(no_of_sub>2){
            cout<<"\nA Teacher can maximum Teach two subjects."<<endl;
        }
        else
        s[no_of_sub++]=s1;
    }
 
    int getnumberOfBatch()
    {
        return no_of_batch;
    }

    void addnumberOfBatch()
    {
        no_of_batch++;
    }

    int getnumberOfSubject()
    {
        return no_of_sub;
    }

    void addnumberOfSubject()
    {
        no_of_sub++;
    }

    string showSubject(int i)
    {
        string na=  s[i]->show();
        return na;
    }

    void addbatch(int no , string batch_name){
        if(no_of_batch>2)
        {
            cout<<"A Teacher can teach maximum of three batches.";
        }

        else  
        {
            b[no_of_batch++]=new batch(batch_name,no);
        }
    }

    string showbatchname(int i) 
    {
    if (i >= 0 && i < no_of_batch) 
    {
        return b[i]->show();
    } 
    
    else 
    {
        return "Invalid Index"; // Handle out-of-bounds access
    }
    }

    string  getid()
    {
        return  emp_id;
    }

    // Displaying Teacher details

    void displayTeacher()
     {
        cout << "Teacher Name: " << name << endl;
        cout << "Employee ID: " << emp_id << endl;
        cout << "Experience: " << experience << " years" << endl;
        cout << "Qualification: " << qualification << endl;
        cout << "Subjects taught:" << endl;
        for (int i = 0; i < no_of_sub; ++i)
        {
            cout << "  - " << s[i]->sub_name << endl;
        }
        cout << "Batches taught:" << endl;
        for (int i = 0; i < no_of_batch; ++i) 
        {
            cout << "  - " << b[i]->batch_name << endl;
        }
    }

    void updateDetails() 
    {
        cout << "Which detail do you want to change?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Employee ID" << endl;
        cout << "3. Experience" << endl;
        cout << "4. Qualification" << endl;
        cout<<"\nEnter your choice  : ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                cin >> name;
                break;

            case 2:
                cout << "Enter new employee ID: ";
                cin >> emp_id;
                break;

            case 3:
                cout << "Enter new experience (in years): ";
                cin >> experience;
                break;

            case 4:
                cout << "Enter new qualification: ";
                cin >> qualification;
                break;

            default:
                cout << "Invalid choice." << endl;

        }

    }

};

// class student  inherits common Characteristics from user using Inheritance

class student : public User

{   protected:
    string enrollment_no;
    batch *b;
    string guardian_name;
    long contact_no;
    int year;

    subject *st[2];
    int no_of_sub;

    public:

    fee_manager *F;
    academic_record *A ;

    subject compulsorysubjects[5] = {subject("Maths"), subject("Physics"), subject("SDF"), subject("ES"), subject("Chemistry")};

     student() : no_of_sub(0) {
        // Initialize each element of st to nullptr
        for (int i = 0; i < 2; ++i) {
            st[i] = nullptr;
        }
    }

    student(string a,string b ,long c,int d,string au, string bu , string cu,long du,string e,string f): User( au,  bu,  b, du, e,f)
    {
        enrollment_no=a;
        guardian_name=cu;
        contact_no=c;
        year=d;
        no_of_sub=0;
        F= new fee_manager(a,cu,130000);
        A =new academic_record();
    }

    void addsubject(subject*s1)
    {
        if(no_of_sub>7)
        {
            cout<<"\nA A student can study maximum of two extra subjects \n"<<endl;
        }

        else
        {
            st[no_of_sub++]=s1;
        }
    }

    void addbatch(string batch_name)
    {
        b=new batch(batch_name);
        cout<<"Batch added successfully";
    }

    int getnumberOfSubject()
    {
        return no_of_sub;
    }

    void addnumberOfSubject()
    {
        no_of_sub++;
    }

    string showExtraSubject(int i) {

    if (i >= 0 && i < no_of_sub) 
    {
        return st[i]->show();
    } 
    
    else 
    {
        return "Invalid Index"; // Handle out-of-bounds access
    }

}




    // Displaying Student details

    void displayStudent() 
    {
        cout << "Enrollment Number: " << enrollment_no << endl;
        cout << "Guardian Name: " << guardian_name << endl;
        cout << "Contact Number: " << contact_no << endl;
        cout << "Year: " << year << endl;
        cout << "Subjects Enrolled:" << endl;
        for (int i = 0; i < no_of_sub; ++i)
        {
            cout << "  - " << st[i]->sub_name << endl;
        }

    }

    void updateDetails()
    {
        int choice;
        cout << "Choose the detail to update:" << endl;
        cout << "1. Enrollment Number" << endl;
        cout << "2. Guardian Name" << endl;
        cout << "3. Contact Number" << endl;
        cout << "4. Year" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter new Enrollment Number: ";
                cin >> enrollment_no;
                break;

            case 2:
                cout << "Enter new Guardian Name: ";
                cin >> guardian_name;
                break;

            case 3:
                cout << "Enter new Contact Number: ";
                cin >> contact_no;
                break;

            case 4:
                cout << "Enter new Year: ";
                cin >> year;
                break;

            default:
                cout << "Invalid choice.";

        }

    }

};

int   main(){

    system("color 4e"); //for getting the background colour and text colour.

// Array of 15 Teachers with detail allocation of 15 teachers.

int teacher_count=10;

Teacher teachers[15] ;
        teachers[0]= Teacher("Teacher1", "E001", 5, "PhD", "user1", "pass1", "John Doe", 1234567890, "01-01-1980", "New York");
        teachers[1]=Teacher("Teacher2", "E002", 7, "Masters", "user2", "pass2", "Alice Smith", 9876543210, "15-05-1975", "Los Angeles");
        teachers[2]=Teacher("Teacher3", "E003", 3, "Bachelor's", "user3", "pass3", "Bob Johnson", 4567890123, "20-10-1988", "Chicago");
        teachers[3]=Teacher("Teacher4", "E004", 8, "PhD", "user4", "pass4", "Emily Brown", 7890123456, "05-03-1972", "Houston");
        teachers[4]=Teacher("Teacher5", "E005", 6, "Masters", "user5", "pass5", "David Wilson", 3216549870, "12-09-1985", "San Francisco");
        teachers[5]=Teacher("Teacher6", "E006", 4, "Bachelor's", "user6", "pass6", "Sarah Taylor", 6549873210, "25-07-1990", "Seattle");
        teachers[6]=Teacher("Teacher7", "E007", 9, "PhD", "user7", "pass7", "Michael Clark", 9876543210, "18-04-1983", "Boston");
        teachers[7]=Teacher("Teacher8", "E008", 2, "Masters", "user8", "pass8", "Emma Anderson", 1597534680, "30-11-1978", "Philadelphia");
        teachers[8]=Teacher("Teacher9", "E009", 10, "PhD", "user9", "pass9", "Daniel Martinez", 3571592468, "08-06-1982", "Miami");
        teachers[9]=Teacher("Teacher10", "E010", 5, "Bachelor's", "user10", "pass10", "Olivia Garcia", 8529637410, "22-02-1977", "Dallas");

// Array of 25 students with detail allocation of 15 students

int student_count=15;

    student students[25];
        students[0]=student("S001", "John Doe", 987654321, 1, "user1", "pass1", "Guardian1", 1234567890, "05-05-2000", "Chicago");
        students[1]=student("S002", "Alice Smith", 123456789, 2, "user2", "pass2", "Guardian2", 9876543210, "10-10-2001", "San Francisco");
        students[2]=student("S003", "Bob Johnson", 456789012, 3, "user3", "pass3", "Guardian3", 7890123456, "15-01-2002", "New York");
        students[3]=student("S004", "Emily Brown", 789012345, 1, "user4", "pass4", "Guardian4", 4567890123, "20-06-2000", "Los Angeles");
        students[4]=student("S005", "David Wilson", 321654987, 2, "user5", "pass5", "Guardian5", 6549873210, "25-11-2001", "Seattle");
        students[5]=student("S006", "Sarah Taylor", 654987321, 3, "user6", "pass6", "Guardian6", 1597534680, "30-03-2002", "Houston");
        students[6]=student("S007", "Michael Clark", 987654321, 1, "user7", "pass7", "Guardian7", 3571592468, "08-08-2000", "Philadelphia");
        students[7]=student("S008", "Emma Anderson", 159753468, 2, "user8", "pass8", "Guardian8", 8529637410, "12-04-2001", "Boston");
        students[8]=student("S009", "Daniel Martinez", 357159246, 3, "user9", "pass9", "Guardian9", 2468135790, "18-09-2002", "Miami");
        students[9]=student("S010", "Olivia Garcia", 852963741, 1, "user10", "pass10", "Guardian10", 3698521470, "22-12-2000", "Dallas");
        students[10]=student("S011", "Sophia Hernandez", 369852147, 2, "user11", "pass11", "Guardian11", 2587413690, "07-07-2001", "Chicago");
        students[11]=student("S012", "James Baker", 258741369, 3, "user12", "pass12", "Guardian12", 1472583690, "14-02-2002", "San Francisco");
        students[12]=student("S013", "Lily Martinez", 147258369, 1, "user13", "pass13", "Guardian13", 3691472580, "01-05-2000", "New York");
        students[13]=student("S014", "William Hernandez", 369147258, 2, "user14", "pass14", "Guardian14", 7894561230, "18-10-2001", "Los Angeles");
        students[14]=student("S015", "Ethan Baker", 789456123, 3, "user15", "pass15", "Guardian15", 1597534560, "23-09-2002", "Seattle");


// Initializing each element separately

    bool exitProgram = false;

    while (!exitProgram) {
    cout<<"\n\n";
    cout <<"                                !!!!! Welcome to the WEBPORTAL !!!!!         "<<endl;
    cout <<"\n\n";
    cout<<"    1. LOGIN Into your  account "<<endl<<endl;
    cout <<"    2. Sign UP for a new account "<<endl;
    int choice=0;
    cout<<"  \nEnter your choice  : ";cin>>choice;cout<<endl;

    if (choice==1)
    {
        cout<<"    1.TEACHER LOGIN     "<<endl<<endl;
        cout <<"    2.STUDENT LOGIN    \n"<<endl;
        int choice2;
        cout<<"  Enter your choice : ";
        cin>>choice2;
        if (choice2==1)
        {
            cout<<"\n\n       WELCOME TO TEACHER LOGIN          \n";
            string user, pass;
            int attempts = 0;
            int teacher_found = -1; // Initialize to -1 to indicate not found

            while (attempts < 3 && teacher_found == -1) {
                cout << "\nENTER USERNAME: ";
                cin >> user;
                cout << "\nENTER PASSWORD: ";
                cin >> pass;

                for (int i = 0; i < teacher_count; i++) {
                    if ((teachers[i].getusername() == user) && (teachers[i].getpassword() == pass)) {
                        teacher_found = i;
                        cout << "\nLOGGED IN AS TEACHER " << teachers[i].getname() << endl;
                        break;

                    }
                }

                if (teacher_found == -1) {
                    cout << "\nINCORRECT USERNAME OR PASSWORD. ";
                    cout << "You have " << 2 - attempts << " attempts remaining." << endl;
                    attempts++;
                }
            }

            if (teacher_found == -1) {
                cout << "\nTOO MANY INCORRECT ATTEMPTS. PLEASE TRY AGAIN LATER.\n";
            }
            else {
                // Teacher successfully logged into his account.
                // Teacher's actions here...
                 bool logout = false;
                while (!logout) {

                    int teacherchoice ;
                cout <<"\n  Select  from following options:-\n";
                cout <<"\n  1.View your details ";
                cout <<"\n  2.Add/view student batch";
                cout <<"\n  3. Add/view subjects ";
                cout <<"\n  4. Change  Password ";
                cout <<"\n  5. Logout" <<endl;
                cout<<"\n ENTER YOUR CHOICE :";
                cin>>teacherchoice;
                switch(teacherchoice)
                {
                    // To view Teacher details
                    case 1:
                        {
                            teachers[teacher_found].displayTeacher();
                            cout <<"\nDo you wish to update any of details : y/n ";
                            char ch;
                            cin>>ch;
                            if((ch=='y')||(ch=='Y'))
                            {
                            teachers[teacher_found].updateDetails();
                            }
                            break;
                        }

                    // To view batch records
                    case 2:
                            {
                                if (teachers[teacher_found].getnumberOfBatch() == 0)
                                {
                                    cout << "Enter no. of students in batch: ";
                                    int numbatch;
                                    cin >> numbatch;
                                    cout << "Enter the name of Batch: ";
                                    string batchName;
                                    cin >> batchName;
                                    teachers[teacher_found].addbatch(numbatch, batchName);
                                    cout << "BATCH ADDED SUCCESSFULLY!!";
                                }
                                else
                                {
                                    cout << "Existing batches:" << endl;
                                    for (int i = 0; i < teachers[teacher_found].getnumberOfBatch(); ++i)
                                    {
                                        cout << i + 1 << ". " << teachers[teacher_found].showbatchname(i) << endl;
                                    }

                                    char divya;

                                    cout<<"Do you want to enter another batch(y/n):"<<endl;
                                    cin>>divya;
                                    if(divya=='y')
                                    {
                                    cout << "Enter no. of students in the new batch: ";
                                    int numbatch;
                                    cin >> numbatch;
                                    cout << "Enter the name of the new Batch: ";
                                    string batchName;
                                    cin >> batchName;
                                    teachers[teacher_found].addbatch(numbatch, batchName);
                                    if(teachers[teacher_found].getnumberOfBatch()<3)
                                    cout << "BATCH ADDED SUCCESSFULLY!!";
                                    }
                                    else break;
                                }
                                break;
                            }

                        // To view subject
                    case 3 :
                    {    if(teachers[teacher_found].getnumberOfSubject()==0)
                        {
                            cout<<"You have zero  Subjects\n ";
                            cout <<"Do You want to add extra subjects";
                            char c;
                            cin >>c;
                            if ((c == 'y') || (c == 'Y')){
                                string subjectName;
                                cout<<"Enter Subject Name ";
                                cin>>subjectName;
                                subject *sone=new subject(subjectName);
                                teachers[teacher_found].addsubject(sone);
                                cout<<"SUBJECT ADDED SUCCESSFULLY";
                                teachers[teacher_found].addnumberOfSubject();

                            }
                        }
                        else if(teachers[teacher_found].getnumberOfSubject()==3){
                            cout<<"\nYou already have registered two subjects successfully\n ";
                            for(int i=0 ;i<teachers[teacher_found].getnumberOfSubject()-1;i++)
                            {
                                cout<<i+1<<". "<<teachers[teacher_found].showSubject(i)<<endl;
                            }
                        }

                        else
                        {
                            cout<<"Extra Subjects are :  \n";
                            for(int i=0 ;i<teachers[teacher_found].getnumberOfSubject()-1;i++)
                            {
                                cout<<i+1<<". "<<teachers[teacher_found].showSubject(i)<<endl;
                            }
                            cout <<"Do You want to add extra subjects";
                            char c;
                            cin >>c;
                            if ((c == 'y') || (c == 'Y')){
                                string subjectName;
                                cout<<"Enter Subject Name ";
                                cin>>subjectName;
                                subject *sone=new subject(subjectName);
                                teachers[teacher_found].addsubject(sone);
                                cout<<"SUBJECT ADDED SUCCESSFULLY";
                                teachers[teacher_found].addnumberOfSubject();
                            }
                        }

                        
                        break;
                    }

                    // To change password
                    case 4 :
                    {  int attempts = 0;
                        string oldp, newp;
                        bool password_changed = false;

                        while (attempts < 3 && !password_changed)
                        {
                            cout << "Enter current password: ";
                            cin >> oldp;

                            if (oldp == teachers[teacher_found].getpassword()) 
                            {
                                cout << "Enter new password: ";
                                cin >> newp;
                                teachers[teacher_found].setpassword(newp);
                                password_changed = true;
                                cout << "Password changed successfully!" << endl;
                            } 
                            else 
                            {
                                cout << "Wrong password. Please try again." << endl;
                                attempts++;
                            }
                        }

                        if (!password_changed) {
                            cout << "Too many incorrect attempts. Please try again later." << endl;
                        }
                        break;
                    }

                    // for logout
                    case  5 :
                    {
                        cout<<"Do you want to Logout ? y/n";
                        char c;
                        cin>>c;
                        if (c == 'y') 
                            {
                                cout << "You are logged out Successfully!";
                                logout = true;
                            }
                            break;
                        }

                    default: {
                            cout << "Invalid choice." << endl;
                            break;
                    }

                }
                    }
                }

            }


        else if(choice2==2)
        {
            cout << "\n\n       WELCOME TO STUDENT LOGIN          \n";
                string stuser, stpass;
                int attempts = 0;
                int student_found = -1; // Initialize to -1 to indicate not found

                while (attempts < 3 && student_found == -1) {
                    cout << "\nENTER USERNAME: ";
                    cin >> stuser;
                    cout << "\nENTER PASSWORD: ";
                    cin >> stpass;

                    for (int i = 0; i < student_count; i++) {
                        if ((students[i].getusername() == stuser) && (students[i].getpassword() == stpass)) {
                            student_found = i;
                            cout << "\nLOGGED IN AS STUDENT " << students[i].getname() << endl;
                            break;
                        }
                    }

                    if (student_found == -1) {
                        cout << "\nINCORRECT USERNAME OR PASSWORD. ";
                        cout << "You have " << 2 - attempts << " attempts remaining." << endl;
                        attempts++;
                    }
                }

                if (student_found == -1)
                {
                    cout << "\nTOO MANY INCORRECT ATTEMPTS. PLEASE TRY AGAIN LATER.\n";
                }

                else
                {
                    // Student successfully logged into his/her account.
                    // Student's actions here...
                    bool logout = false;
                while (!logout) {

                    int studentchoice ;
                cout <<"\n  Select  from following options:-\n";
                cout <<"\n 1. View your details ";
                cout <<"\n 2. Update student batch";
                cout <<"\n 3. ADD/view subjects ";
                cout <<"\n 4. Change  Password ";
                cout<<"\n 5. View FEE RECORD ";
                cout<<"\n 6. VIEW MARKS /SGPA";
                cout << "\n 7. Logout" <<endl;
                cout<<"\n ENTER YOUR CHOICE :";
                cin>>studentchoice;

                switch(studentchoice)
                {
                    // To view Student Details
                    case 1:
                        {
                            students[student_found].displayStudent();
                            cout <<"\nDo you wish to update any of details : y/n ";
                            char ch;
                            cin>>ch;
                            if((ch=='y')||(ch=='Y'))
                            {
                            students[student_found].updateDetails();
                            }
                            break;

                        }

                    // For updating Student Batch
                    case 2 :
                        {
                            cout<<"Enter  the name of Batch  : ";
                            string batchName;
                            cin>>batchName;
                            students[student_found].addbatch(batchName);
                            break;
                        }

                    // To view subjects   1 
                    case 3: {
                        cout << "\nFIVE COMPULSORY SUBJECTS ARE:\n";
                        for (int i = 0; i < 5; ++i) {
                            cout << i + 1 << ". " << students[student_found].compulsorysubjects[i].sub_name << endl;
                        }

                        if (students[student_found].getnumberOfSubject() == 0) {
                            cout << "\nYou have zero Extra Subjects.\n";
                        } else {
                            cout << "\nExtra Subjects:\n";
                            for (int i = 0; i < students[student_found].getnumberOfSubject(); ++i) {
                                cout << i + 1 << ". " << students[student_found].showExtraSubject(i) << endl;
                            }
                        }

                        cout << "\nDo you want to add an extra subject? (y/n): ";
                        char c;
                        cin >> c;

                        if ((c == 'y') || (c == 'Y')) {
                            string subjectName;

                        
                            if (students[student_found].getnumberOfSubject() >= 2) {
                                cout << "You can only add a maximum of two extra subjects.\n";
                                break;
                            }

                            cout << "Enter Subject Name: ";
                            cin >> subjectName;

                            subject* sone = new subject(subjectName);
                            students[student_found].addsubject(sone);
                            cout << "SUBJECT ADDED SUCCESSFULLY\n";
                        }

                        break;
                    }



                    // To change password
                    case 4 :
                    {  int attempts = 0;
                        string oldp, newp;
                        bool password_changed = false;

                        while (attempts < 3 && !password_changed)
                        {
                            cout << "Enter current password: ";
                            cin >> oldp;

                            if (oldp == students[student_found].getpassword()) {
                                cout << "Enter new password: ";
                                cin >> newp;
                               students[student_found].setpassword(newp);
                                password_changed = true;
                                cout << "Password changed successfully!" << endl;
                            } 
                            
                            else {
                                cout << "Wrong password. Please try again." << endl;
                                attempts++;
                            }
                            
                        }

                        if (!password_changed) {
                            cout << "Too many incorrect attempts. Please try again later." << endl;
                        }

                        break;
                    }

                    // To view fee records
                    case 5:
                    {
                    cout<<"FEE RECORD OF  STUDENT \n\n";
                    students[student_found].F->view_feerecord();
                    cout<<"\nDO YOU WISH TO UPDATE FEE RECORD ?? y/n";
                    char c;
                    cin>>c;
                    
                    if(c=='y')
                    {
                        students[student_found].F->update_feerecord();
                    }

                    cout<<"\nDO YOU WISH TO GENERATE FEE RECIEPT ?? y/n";
                    char ch;
                    cin>>ch;

                    if(c=='y')
                    {
                        students[student_found].F->generate_feereceipt();
                        break ;
                    }

                    else{
                        break;
                    }

                    // To view marks/sgpa
                    case 6 :
                    {
                        cout <<"\nMARKS RECORD";
                        students[student_found].A->generate_random_marks();
                        students[student_found].A->view_marks();
                        cout<<"\nDo you wish to see sgpa ?";
                        char d;
                        cin>>d;

                        
                        if (d == 'y')
                        {
                        students[student_found].A->sgpa_generator();
                        }
                        break;

                    }

                    // To logout
                    case  7 :
                    {
                        cout<<"Do you want to Logout ? y/n";
                        char c;
                        cin>>c;


                        if (c == 'y') {
                                cout << "You are logged out Successfully!";
                                logout = true;
                            }
                            break;
                        }


                    default: {
                            cout << "Invalid choice." << endl;
                            break;
                    }

                }

                    }

                }

                }

        }
    }


    if (choice==2)
    {
        cout<<"    1.TEACHER SIGNUP     "<<endl<<endl;
        cout <<"    2.STUDENT SIGNUP    \n"<<endl;
        int choice3;
        cout<<"  Enter your choice : ";
        cin>>choice3;
        
        if (choice3==1)
        {
            cout<<"\n\n       WELCOME TO TEACHER SIGNUP          \n";

            cout<<" \nENTER NAME : ";
            string teachername;
            cin>> teachername;


            cout<<"\n ENTER USERNAME : ";
            string teacheruser;
            cin>>teacheruser;


            cout<<" \nENTER PASSWORD : ";
            string teacherpass;
            cin>> teacherpass;


            cout<<" \nENTER TEACHERNAME : ";
            string teacheruname;
            cin>> teacheruname;


            cout<<" \nENTER CONTACT NO. : ";
            long teacherno;
            cin>> teacherno;


            cout<<" \nENTER DOB : ";
            string teacherdob;
            cin>> teacherdob;


            cout<<" \nENTER CITY : ";
            string teachercity;
            cin>> teachercity;


            cout<<" \nENTER EMPLOYEE ID : ";
            string teacherid;
            cin>> teacherid;


            cout<<" \nENTER QUALIFICATIONS : ";
            string teacherqua;
            cin>> teacherqua;


            cout<<" \nENTER EXPERIENCE (in years): ";
            int teacherexp;
            cin>> teacherexp;


            cout<<"\n           YOU ARE REGISTERED SUCCESFULLY          ";

            teachers[teacher_count-1] =Teacher(teacheruname,teacherid,teacherexp,teacherqua,teacheruser,teacherpass,teachername,teacherno,teacherdob,teachercity);
            teacher_count++;
        }


        else if (choice3==2)
        {
            cout<<"\n\n       WELCOME TO STUDENT SIGNUP          \n";

            cout<<" \nENTER STUDENT NAME : ";
            string studentname;
            cin>> studentname;


            cout<<"\n ENTER USERNAME : ";
            string studentuser;
            cin>>studentuser;


            cout<<" \nENTER PASSWORD : ";
            string studentpass;
            cin>> studentpass;


            cout<<" \nENTER CONTACT NO. : ";
            long studentno;
            cin>> studentno;


            cout<<" \nENTER DOB : ";
            string studentdob;
            cin>> studentdob;


            cout<<" \nENTER CITY : ";
            string studentcity;
            cin>> studentcity;


            cout<<" \nENTER GUARDIAN NAME : ";
            string studentguardianname;
            cin>> studentguardianname;


            cout<<" \nENTER ENROLLMENT NO. : ";
            string studentenroll;
            cin>> studentenroll;


            cout<<" \nENTER GUARDIAN's PHONE NO. : ";
            long studentguardianno;
            cin>> studentguardianno;


            cout<<" \nENTER YOUR CURENT YEAR: ";
            int studentyear;
            cin>> studentyear;


            cout<<"\n           YOU ARE REGISTERED SUCCESFULLY          ";

            students[student_count-1]=student(studentenroll,studentname,studentno,studentyear,studentuser,studentpass,studentguardianname,studentguardianno,studentdob,studentcity);
            student_count++;

        }

    }

   }
return 0 ;
}
